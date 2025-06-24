/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:45:37 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/20 23:39:23 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int		solve_puzzle_iterative(int n, int *clues, int grid[n][n]);
void	print_solution(int n, int grid[n][n]);
int		*get_clues(int n, char *str);
void	count_clues(int *total, char *str);
void	ft_error(void);

int	main(int argc, char *argv[])
{
	int	*clues;
	int total_clues;
	int n;

	clues = NULL;
	total_clues = 0;
	n = 0;
	if (argc < 2)
	{
        ft_error();
        return 1;
    }

    count_clues(&total_clues, argv[1]);
    printf("total: %d\n ", total_clues);
    
    n = total_clues / 4;
    
    if (total_clues != 4 * (n)) {
        ft_error();
        return (0);
    }

	// Convert clues to integers
    clues = get_clues(n, argv[1]);

    if (!clues)
    {
        ft_error();
        return (0);
    }
	printf("%s\n", argv[1]);
    
    // Create variable-length array grid
	printf("%d\n", n);
	printf("%d\n", total_clues);
    int (*grid)[n] = malloc(n * sizeof(*grid));
    if (!grid) {
        ft_error();
        free(clues);
        return 1;
    }

    // Solve and print result
    if (solve_puzzle_iterative(n, clues, grid)) {
        printf("Solution found:\n");
        print_solution(n, grid);
    } else {
        ft_error();
		printf("here\n");
    }

    free(grid);
    free(clues);
    return 0;
}
