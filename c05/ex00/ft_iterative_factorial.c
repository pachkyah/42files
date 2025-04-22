/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:04:00 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/22 17:14:46 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	#include <stdio.h>

int	ft_iterative_factorial(int nb)
/*
	This function counts factorial until nb,
	using iterative methid
	returns 0 for bad inputs
*/
{
	int	result;
	int	i;

	i = 1;
	result = 1;
	if (nb < 0)
	{
		return (0);
	}
	while (i <= nb)
	{
		result *= i;
		i++;
	}
	return (result);
}

/*
int main() {
    int number = 10;
    int result = ft_iterative_factorial(number);

    if (result != 0) {
        printf("%d!=%d\n", number, result);
    } else {
        printf("bad input\n");
    }
    return 0;
}
*/
