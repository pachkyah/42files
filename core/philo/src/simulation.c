#include "philo.h"

int start_simulation(t_data *data)
{
    int i;

    i = 0;
    data->start_time = get_time();
    printf("Inside simulation 1\n");
    while (i < data->nb_philos)
    {
        // Set the meal time BEFORE creating the thread
        pthread_mutex_lock(&data->philos[i].philo_lock);
        data->philos[i].last_meal_time = data->start_time;
        pthread_mutex_unlock(&data->philos[i].philo_lock);
        // Give each philo their start time and thread
        if (pthread_create(&data->philos[i].thread, NULL, &philo_routine, &data->philos[i]))
            return (1);
        i++;
    }
    // Start the monitor thread (The "Grim Reaper")
    monitor_death(data); 
    printf("Inside simulation 2\n");
    
    // Join threads (Wait for them to finish)
    i = 0;
    while (i < data->nb_philos){
        printf("Joining threads %d\n", i);
        pthread_join(data->philos[i++].thread, NULL);
    }
    return (0);
}

void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    printf("Philo %d thread spawned!\n", philo->id); // DEBUG
    // Delay even philos to avoid instant deadlock
    if (!philo)
        return (printf("Philo struct is NULL!\n"), NULL);
    if (!philo->data)
        return (printf("Philo %d data pointer is NULL!\n", philo->id), NULL);
    if (philo->id % 2 == 0)
        ft_usleep(1, philo->data); 

    printf("Inside philo_routine 1\n");
    while (get_sim_status(philo->data) == false) // Check if simulation is still running
    {
        eat_action(philo);
        if (get_sim_status(philo->data)) // Check again after eating
            break;
        print_status(philo, "is sleeping");
        ft_usleep(philo->data->time_to_sleep, philo->data);
        print_status(philo, "is thinking");
    }
    return (NULL);
}

void ft_usleep(long long milliseconds, t_data *data)
{
    long long start = get_time();
    while ((get_time() - start) < milliseconds)
    {
        if (get_sim_status(data)) // Stop sleeping if someone died
            break;
        usleep(500); // Sleep in very small chunks
    }
}