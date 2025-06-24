/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:22:09 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/20 16:10:34 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

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
	does not contain +, - or unprintable characters
*/
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
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

int	base_index(char c, char *base)
/*
	This function finds the position (index)
	of a character in the base string;
	returns -1 if not found	
*/
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
	This function ft_atoi_base reads number in base from a string
	and converts it into decimal:
	check base,
	then standart atoi:
		ignore space + \* characters
		find sign
		convert digits from their base to decimal
*/

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	b_len;

	i = 0;
	sign = 1;
	result = 0;
	if (!is_valid_base(base))
		return (0);
	b_len = ft_strlen(base);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (base_index(str[i], base) != -1)
	{
		result = result * b_len + base_index(str[i], base);
		i++;
	}
	return (sign * result);
}

/*
int main(void)
{
    printf("%d\n", ft_atoi_base("  --+--1010", "01"));// -10 (bin)
    printf("%d\n", ft_atoi_base("   ---1A", "0123456789ABCDEF"));// -26 (hex)
    printf("%d\n", ft_atoi_base("pookie", "poneyvif"));// 9 (k is not in base)
    printf("%d\n", ft_atoi_base("vif", "poneyvif"));// 375 (octal-style base)
	printf("%d\n", ft_atoi_base("123", ""));// 0  (emply base)
    return 0;
}
*/
