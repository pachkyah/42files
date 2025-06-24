/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:33:54 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/22 18:08:55 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_recursive_power(int nb, int power)
/*
	This function calculates nb^power,
	using recursive methid
	returns 0 for bad inputs
*/
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}

/*
int main() {
    int number = 2;
	int power = 3;
    int result = ft_recursive_power(number, power);

    if (result != 0) {
        printf("%d!=%d\n", number, result);
    } else {
        printf("bad input 😭\n");
    }
    return 0;
}
*/
