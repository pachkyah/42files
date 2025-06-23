/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:00 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/23 17:24:30 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(int n)
/*
	Helper function for counting digits in an int number
*/
{
	size_t	len;
	long	num;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	num = n;
	if (num < 0)
		num = -num;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
/*
    This function allocates memory  and returns
    a string representing the integer received as an
    argument. (int edge cases are handled)
*/
{
	size_t	len;
	char	*str;
	long	num;

	num = n;
	len = int_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[--len] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}
