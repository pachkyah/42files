#include "philo.h"

bool get_sim_status(t_data *data)
{
    bool status;

    pthread_mutex_lock(&data->data_lock);
    status = data->simulation_end;
    pthread_mutex_unlock(&data->data_lock);
    return (status);
}

// This function will run in the main thread and watch the philos
void monitor_death(t_data *data)
{
    int i;

    while (1)
    {
        i = 0;
        while (i < data->nb_philos)
        {
            pthread_mutex_lock(&data->philos[i].philo_lock);
            if (get_time() - data->philos[i].last_meal_time >= data->time_to_die)
            {
                print_status(&data->philos[i], "died");
                pthread_mutex_lock(&data->data_lock);
                data->simulation_end = true;
                pthread_mutex_unlock(&data->data_lock);
                pthread_mutex_unlock(&data->philos[i].philo_lock);
                return ;
            }
            pthread_mutex_unlock(&data->philos[i].philo_lock);
            i++;
        }
        usleep(1000); // Don't burn the CPU
    }
}