/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:56:17 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/23 19:46:43 by ypachkou         ###   ########.fr       */
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

void	ft_putstr(char const *str)
/*
    This function that displays
    a string of characters on the standard output
*/
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

int	main(int argc, char const *argv[])
/*
	this program prints out it's arguments
*/
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
