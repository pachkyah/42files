# include "philo.h"

// Example of the logic you'll need in init.c

int init_data(t_data *data, char **argv)
{
    data->nb_philos = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    // Handle the optional 5th argument (must_eat_count)
    data->simulation_end = false;
    data->start_time = get_time(); // We will write this helper soon
    
    // Allocate memory for forks and philos
    data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
    data->philos = malloc(sizeof(t_philo) * data->nb_philos);
    
    if (!data->forks || !data->philos) {
        return (1); // If you forget this, and malloc fails, boom.
    }
    
    printf("inside Init\n");

    // Initialize Mutexes
    pthread_mutex_init(&data->print_lock, NULL);
    pthread_mutex_init(&data->data_lock, NULL);
    
    int i = -1;
    while (++i < data->nb_philos)
    {
        // 1. Give them an ID
        data->philos[i].id = i + 1;
        
        // 2. Link them to the shared data (THIS PREVENTS THE SEGFAULT)
        data->philos[i].data = data;
        
        // 3. Initialize their individual meal lock
        pthread_mutex_init(&data->philos[i].philo_lock, NULL);
        
        // 4. Assign forks (left is current index, right is next index)
        data->philos[i].left_fork_id = i;
        data->philos[i].right_fork_id = (i + 1) % data->nb_philos;
        
        // 5. Initialize meal time to now so they don't die instantly
        data->philos[i].last_meal_time = data->start_time;
        data->philos[i].meals_eaten = 0;
    }
    
    // Also initialize forks in their own loop (which you have)
    i = -1;
    while (++i < data->nb_philos)
        pthread_mutex_init(&data->forks[i], NULL);

    return (0);
}