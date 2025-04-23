/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:00:21 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/23 19:22:55 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_sqrt(int nb)
/*
	This function eturns the square root
	of a given number (if it exists in int numbers),
	else output 0
*/
{
	int	i;
    // todo: change to long int to solve for max_int

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

/*
int main() {
    int nb = 24;
    int result = ft_sqrt(nb);

    if (result != 0) {
        printf("√%d = %d\n", nb, result);
    } else {
        printf("No integer square root 😭 for %d\n", nb);
    }

    return 0;
}
*/
