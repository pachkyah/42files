/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:25:55 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 18:52:25 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_putchar(char c)
/* writes 1 character,
	write args:
	1 means stdout,
	1 means length */
{
	write(1, &c, 1);
}

void	ft_print_hex(unsigned char c)
/*
	This function prints ascii as two-digit hex value
*/
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
/*
	This function displays a string of characters on screen:
	If this string contains non-printable characters,
	they are displayed as lowercase hexadecimal values with  backslash
*/
{
	unsigned char	c;
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (c >= 32 && c <= 126)
			ft_putchar(c);
		else
			ft_print_hex(c);
		i++;
	}
}

/*
int main(void)
{
    char str[] = "Hello\nHow are you?\tGood!";
	char str1[] = "I'm\rFine\tThank you!";

    ft_putstr_non_printable(str);
	ft_putstr_non_printable(str1);
    
    return 0;
}
*/
