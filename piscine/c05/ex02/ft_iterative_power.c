/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:20:41 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/22 18:09:04 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_iterative_power(int nb, int power)
/*
	This function calculates nb^power,
	using iterative methid
	returns 0 for bad inputs
*/
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	if (power < 0)
	{
		return (0);
	}
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

/*
int main() {
    int number = 2;
	int power = 3;
    int result = ft_iterative_power(number, power);

    if (result != 0) {
        printf("%d!=%d\n", number, result);
    } else {
        printf("bad input 😭\n");
    }
    return 0;
}
*/
