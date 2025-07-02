/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:11:01 by ypachkou          #+#    #+#             */
/*   Updated: 2025/07/02 20:30:45 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int dispatch_print(t_flags *flags, va_list args)
{
    if (flags->specifier == 'c')
        return print_char(flags, args);
    else if (flags->specifier == 's')
        return print_string(flags, args);
    else if (flags->specifier == 'p')
        return print_pointer(flags, args);
    else if (flags->specifier == 'd' || flags->specifier == 'i')
        return print_decimal(flags, args);
    else if (flags->specifier == 'u')
        return print_unsigned(flags, args);
    else if (flags->specifier == 'x')
        return print_hex(flags, args, 0);
    else if (flags->specifier == 'X')
        return print_hex(flags, args, 1);
    else if (flags->specifier == '%')
        return print_percent(flags);

    return 0;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    t_flags flags;
    int total_printed = 0;
    int i = 0;
    int parsed_len;
    int printed;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            parsed_len = parse_flags(&format[i], &flags);
            if (flags.specifier == 0) // Invalid specifier, just print %
            {
                total_printed += write(1, "%", 1);
                continue;
            }
            printed = dispatch_print(&flags, args);
            if (printed == -1) // error handling if needed
            {
                va_end(args);
                return -1;
            }
            total_printed += printed;
            i += parsed_len;
        }
        else
        {
            total_printed += write(1, &format[i], 1);
            i++;
        }
    }

    va_end(args);
    return total_printed;
}
