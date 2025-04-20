/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:57:35 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/20 16:02:20 by ypachkou         ###   ########.fr       */
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

int	ft_strlen(char *str)
/*
    This function that counts and returns
    the number of characters in a string
*/
{
	int	index;

	index = 0;
	while (str[index])
	{
		index++;
	}
	return (index);
}

int	is_valid_base(char *base)
/*
	This function checks if the base:
	has at least two characters
	does not contain duplicates
	does not contain + or -
*/
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
/*
	This function converts an int from dec into another base:
	base is a string and is checked in is_valid_base
	then divides the number by its base and calls itself!
		then prints result of mod_division
	the function is recursive!!
*/
{
	long	n;
	int		len;

	if (!is_valid_base(base))
	{
		return ;
	}
	len = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= len)
	{
		ft_putnbr_base(n / len, base);
	}
	ft_putchar(base[n % len]);
}

/*
int main(void)
{
	ft_putnbr_base(-42, "0123456789");       // -42
	write(1, "\n", 1);
	ft_putnbr_base(42, "01");                // 101010
	write(1, "\n", 1);
	ft_putnbr_base(255, "0123456789ABCDEF"); // FF
	write(1, "\n", 1);
	ft_putnbr_base(420, "poneyvif");          // iyy
	write(1, "\n", 1);
	return (0);
}
*/
