/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:11:07 by ypachkou          #+#    #+#             */
/*   Updated: 2025/07/02 20:23:48 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int put_padding(char c, int count)
{
    int i;

    if (count <= 0)
        return 0;

    for (i = 0; i < count; i++)
        write(1, &c, 1);

    return count;
}


char *ft_itoa_base(unsigned long long num, int base, int uppercase)
{
    char *digits;
    char *str;
    int len = 0;
    unsigned long long tmp = num;

    digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (num == 0)
    {
        str = malloc(2);
        if (!str)
            return NULL;
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    // Calculate length
    while (tmp != 0)
    {
        tmp /= base;
        len++;
    }

    str = malloc(len + 1);
    if (!str)
        return NULL;

    str[len] = '\0';

    while (num != 0)
    {
        str[--len] = digits[num % base];
        num /= base;
    }

    return str;
}

int ft_numlen(long long num, int base)
{
    int len = 0;

    if (num == 0)
        return 1;

    // Handle negative numbers only if base is 10
    if (num < 0 && base == 10)
        num = -num;

    while (num != 0)
    {
        num /= base;
        len++;
    }
    return len;
}
