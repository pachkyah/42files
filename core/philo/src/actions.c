#include "philo.h"

void print_status(t_philo *philo, char *status)
{
    long long time;

    pthread_mutex_lock(&philo->data->print_lock);
    time = get_time() - philo->data->start_time;
    
    // Only print if the simulation isn't over
    if (!get_sim_status(philo->data))
        printf("%lld %d %s\n", time, philo->id, status);
        
    pthread_mutex_unlock(&philo->data->print_lock);
}

void eat_action(t_philo *philo)
{
    // Pick up forks (Mutex locking)
    pthread_mutex_lock(&philo->data->forks[philo->left_fork_id]);
    print_status(philo, "has taken a fork");

    // If there's only one philo, they can't take a second fork
    if (philo->data->nb_philos == 1)
    {
        // Just wait until the monitor kills us
        ft_usleep(philo->data->time_to_die + 10, philo->data);
        pthread_mutex_unlock(&philo->data->forks[philo->left_fork_id]);
        return;
    }

    pthread_mutex_lock(&philo->data->forks[philo->right_fork_id]);
    print_status(philo, "has taken a fork");

    // Eating
    print_status(philo, "is eating");
    
    pthread_mutex_lock(&philo->philo_lock);
    philo->last_meal_time = get_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->philo_lock);

    ft_usleep(philo->data->time_to_eat, philo->data);

    // Drop forks
    pthread_mutex_unlock(&philo->data->forks[philo->left_fork_id]);
    pthread_mutex_unlock(&philo->data->forks[philo->right_fork_id]);
}