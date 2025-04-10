/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:38:14 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/10 19:45:25 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
/*
	Iterates through all combinations of three distinct digits:
	a from 0 to 7
	b from a + 1 to 8
	c from b + 1 to 9
*/
{
	int	a;
	int b;
	int	c;


	for (a = 0; a <= 7; a++) // a can go from 0 to 7
	{
		for (b = a + 1; b <= 8; b++) // b is always greater than a
		{
			for (c = b + 1; c <= 9; c++) // c is always greater than b
			{
				// Print the combination: a, b, c using write()
				write(1, &"0123456789"[a], 1);
				write(1, &"0123456789"[b], 1);
				write(1, &"0123456789"[c], 1);

				// Print a comma and a space if it's not the last combination
				if (!(a == 7 && b == 8 && c == 9))
				{
					write(1, ", ", 2);
				}
			}
		}
	}
}

/*
int	main(void)
{
	ft_print_comb();
	return (0);
}
*/
