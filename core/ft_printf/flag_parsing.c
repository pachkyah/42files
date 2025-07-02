/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:10:58 by ypachkou          #+#    #+#             */
/*   Updated: 2025/07/02 20:29:46 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>

static int is_flag_char(char c)
{
    return (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#');
}

static int is_specifier_char(char c)
{
    return (c == 'c' || c == 's' || c == 'p' || c == 'd' || 
            c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int parse_flags(const char *format, t_flags *flags)
{
    int i = 0;

    // Reset flags to defaults (0)
    flags->minus = 0;
    flags->zero = 0;
    flags->plus = 0;
    flags->space = 0;
    flags->hash = 0;
    flags->dot = 0;
    flags->width = 0;
    flags->precision = 0;
    flags->specifier = 0;

    // 1. Parse flag characters
    while (is_flag_char(format[i]))
    {
        if (format[i] == '-')
            flags->minus = 1;
        else if (format[i] == '0')
            flags->zero = 1;
        else if (format[i] == '+')
            flags->plus = 1;
        else if (format[i] == ' ')
            flags->space = 1;
        else if (format[i] == '#')
            flags->hash = 1;
        i++;
    }

    // If '-' is set, zero padding is ignored
    if (flags->minus)
        flags->zero = 0;

    // 2. Parse width (number)
    while (isdigit(format[i]))
    {
        flags->width = flags->width * 10 + (format[i] - '0');
        i++;
    }

    // 3. Parse precision if '.' found
    if (format[i] == '.')
    {
        flags->dot = 1;
        i++;
        flags->precision = 0;
        while (isdigit(format[i]))
        {
            flags->precision = flags->precision * 10 + (format[i] - '0');
            i++;
        }
    }

    // 4. Parse specifier
    if (is_specifier_char(format[i]))
    {
        flags->specifier = format[i];
        i++;
    }

    return i;
}
