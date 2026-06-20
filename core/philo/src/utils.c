# include "philo.h"

long long get_time(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL))
        return (0);
    // Convert seconds and microseconds to total milliseconds
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void cleanup_everything(t_data *data)
{
    int i;

    i = 0;
    // Destroy fork mutexes
    while (i < data->nb_philos)
    {
        pthread_mutex_destroy(&data->forks[i]);
        pthread_mutex_destroy(&data->philos[i].philo_lock);
        i++;
    }
    // Destroy global mutexes
    pthread_mutex_destroy(&data->print_lock);
    pthread_mutex_destroy(&data->data_lock);
    
    // Free allocated memory
    free(data->forks);
    free(data->philos);
}