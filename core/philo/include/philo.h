#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft.h"

/* --- Structures --- */

typedef struct s_data t_data;

typedef struct s_philo
{
    int             id;
    int             meals_eaten;
    long long       last_meal_time;
    int             left_fork_id;
    int             right_fork_id;
    pthread_t       thread;
    t_data          *data;          // Pointer to access global rules/mutexes
    pthread_mutex_t philo_lock;     // To protect philo-specific data (last_meal)
}   t_philo;

typedef struct s_data
{
    int             nb_philos;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             must_eat_count; // Optional argument
    long long       start_time;
    bool            simulation_end; // Flag to stop all threads
    pthread_mutex_t *forks;         // Array of mutexes
    pthread_mutex_t print_lock;     // Prevents text overlapping
    pthread_mutex_t data_lock;      // Protects simulation_end and global vars
    t_philo         *philos;        // Array of philo structs
}   t_data;

/* --- Prototypes --- */

// You'll add your function prototypes here as you build them:
// void         print_status(t_philo *philo, char *status);

int init_data(t_data *data, char **argv);

int start_simulation(t_data *data);
void *philo_routine(void *arg);
void ft_usleep(long long milliseconds, t_data *data);

long long get_time(void);
void cleanup_everything(t_data *data);

/* --- Actions (actions.c) --- */
void        eat_action(t_philo *philo);
void        print_status(t_philo *philo, char *status);

/* --- Monitor (monitor.c) --- */
void        monitor_death(t_data *data);
bool        get_sim_status(t_data *data);
#endif 