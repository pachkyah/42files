#include "philo.h"

int main(int argc, char **argv)
{
    t_data  data;

    // 1. Argument Check
    if (argc != 5 && argc != 6)
        return (printf("Error: Wrong number of arguments\n"), 1);

    printf("arg num: %d\n", argc);
    // 2. Initialization
    if (init_data(&data, argv) != 0) {
        printf("Init failed\n");
        return (1); // Ensure init_data handles its own clean cleanup on failure
    }

    printf("arg num: %d\n", argc);
    // 3. Start Simulation
    if (start_simulation(&data) != 0)
    {
        printf("Simulation failed\n");
        cleanup_everything(&data);
        return (1);
    }

    // 4. Cleanup & Exit
    cleanup_everything(&data);
    return (0);
}