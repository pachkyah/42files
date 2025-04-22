/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:35:44 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/22 18:45:06 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_is_prime(int nb)
/*
	This function that returns:
	1 if the given number is a prime number
	0 if it is not;
	+ special cases for 0,1,2 and all even nums
*/
{
	int	i;

	i = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
/*
	This function checks if nb is prime and returns it,
	otherwise increases number and checks again
*/
{
    if (nb <= 2)
        return (2);
    while (!ft_is_prime(nb))
        nb++;
    return (nb);
}

/*
int main() {
    int nb = 8;
    int result = ft_find_next_prime(nb);

    printf("%d is the next prime number😁\n", result);
    return 0;
}
*/
