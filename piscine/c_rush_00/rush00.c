/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:59:49 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/12 14:27:22 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_first_last(int x)
{
	int	xi;

	xi = 0;
	while (xi < x)
	{
		if (xi == 0 || xi == x - 1)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
		xi++;
	}
	ft_putchar('\n');
}

void	print_sides(int x)
{
	int	xi;

	xi = 0;
	while (xi < x)
	{
		if (xi == 0 || xi == x - 1)
		{
			ft_putchar('|');
		}
		else
		{
			ft_putchar(' ');
		}
		xi++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	yi;

	yi = 0;
	while (yi < y)
	{
		if (yi == 0 || yi == y - 1)
		{
			print_first_last(x);
		}
		else
		{
			print_sides(x);
		}
		yi++;
	}
}
