/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:29:43 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/23 19:51:24 by ypachkou         ###   ########.fr       */
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
	ft_putchar('\n');
}

int	ft_strcmp(char *s1, char *s2)
/*
    This function compares characters in 2 strings:
    0, if the s1 and s2 are equal;
    a negative value if s1 is less than s2;
    a positive value if s1 is greater than s2.
*/
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_sort(int arglen, char **argv)
/*
	this function sorts input arguments 
	from argv[1] to argv[argc - 1]
*/
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < arglen - 1)
	{
		j = i + 1;
		while (j < arglen)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
/*
	this program sorts it's arguments in ascii order
*/
{
	int	i;

	i = 1;
	ft_sort(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
