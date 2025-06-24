/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:42:22 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/12 14:56:29 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Iterates through all different combinations of two distinct two-digits
numbers (XX XX) between 00 and 99:
	a2 from 0 to 98
	b2 from a2 + 1 to 99
*/

void	ft_print_comb2(void)
{
	int	a2;
	int	b2;

	a2 = 0;
	while (a2 <= 98)
	{
		b2 = a2 + 1;
		while (b2 <= 99)
		{
			write(1, &"0123456789"[a2 / 10], 1);
			write(1, &"0123456789"[a2 % 10], 1);
			write(1, " ", 1);
			write(1, &"0123456789"[b2 / 10], 1);
			write(1, &"0123456789"[b2 % 10], 1);
			if (!(a2 == 98 && b2 == 99))
			{
				write(1, ", ", 2);
			}
			b2++;
		}
		a2++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
