/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:11:27 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/22 18:34:50 by ypachkou         ###   ########.fr       */
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

/*
int main() {
    int nb = 7;
    int result = ft_is_prime(nb);

    if (result == 1) {
        printf("%d is a prime number😁\n", nb);
    } else {
        printf("%d is not a prime number😔\n", nb);
    }

    return 0;
}
*/
