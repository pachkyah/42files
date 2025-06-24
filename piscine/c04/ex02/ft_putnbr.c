/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:37:55 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/20 14:37:59 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
/* writes 1 character,
	write args:
	1 means stdout,
	1 means length */
{
	write(1, &c, 1);
}

/*
	The function to display all possible values
	of an int type variable on stdout:
	first it checks the lowest int -2147483648,
	then sign,
	then works with single digits of positive int
*/

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
}

/*
int	main(void)
{
	ft_putnbr(42);
	// ft_putnbr(12345);
    // ft_putnbr(-12345);
    // ft_putnbr(0);
    // ft_putnbr(-2147483648);
	return (0);
}
*/
