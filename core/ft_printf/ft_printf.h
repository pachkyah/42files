/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:10:54 by ypachkou          #+#    #+#             */
/*   Updated: 2025/07/02 20:23:01 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_flags
{
    int minus;       // '-' flag
    int zero;        // '0' flag
    int dot;         // precision specified flag ('.')
    int width;       // minimum field width
    int precision;   // precision value
    int plus;        // '+' flag
    int space;       // ' ' flag
    int hash;        // '#' flag
    char specifier;  // conversion specifier: 'd', 's', 'x', etc.
}   t_flags;

// Main ft_printf function
int     ft_printf(const char *format, ...);

// Parsing
int     parse_flags(const char *format, t_flags *flags);

// Printing handlers (one for each type)
int     print_char(t_flags *flags, va_list args);
int     print_string(t_flags *flags, va_list args);
int     print_pointer(t_flags *flags, va_list args);
int     print_decimal(t_flags *flags, va_list args);
int     print_unsigned(t_flags *flags, va_list args);
int     print_hex(t_flags *flags, va_list args, int uppercase);
int     print_percent(t_flags *flags);

// Utility functions
int     ft_numlen(long long num, int base);
char    *ft_itoa_base(unsigned long long num, int base, int uppercase);
int     put_padding(char c, int count);

#endif
