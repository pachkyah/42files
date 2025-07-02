/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:11:04 by ypachkou          #+#    #+#             */
/*   Updated: 2025/07/02 21:41:30 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int print_char(t_flags *flags, va_list args)
{
    char c = (char)va_arg(args, int);
    int printed = 0;

    if (!flags->minus)
        printed += put_padding(' ', flags->width - 1);

    write(1, &c, 1);
    printed += 1;

    if (flags->minus)
        printed += put_padding(' ', flags->width - 1);

    return printed;
}

int print_string(t_flags *flags, va_list args)
{
    char *str = va_arg(args, char *);
    int len;
    int printed = 0;

    if (!str)
        str = "(null)";

    len = (int)ft_strlen(str);
    if (flags->dot && flags->precision < len)
        len = flags->precision;

    if (!flags->minus)
        printed += put_padding(' ', flags->width - len);

    write(1, str, len);
    printed += len;

    if (flags->minus)
        printed += put_padding(' ', flags->width - len);

    return printed;
}

int print_pointer(t_flags *flags, va_list args)
{
    unsigned long long ptr = (unsigned long long)va_arg(args, void *);
    char *str;
    int len;
    int printed = 0;

    if (ptr == 0)
        str = ft_strdup("nil");
    else if (flags->dot && flags->precision == 0)
        str = ft_strdup("");
    else
        str = ft_itoa_base(ptr, 16, 0);

    if (!str)
        return -1;

    len = (int)ft_strlen(str);
    if (ft_strncmp(str, "nil", 4) == 0)
        len += 2; // add 2 for "0x"

    if (!flags->minus)
        printed += put_padding(' ', flags->width - len);

    if (ft_strncmp(str, "nil", 4) == 0)
        printed += write(1, "(nil)", 5);
    else
    {
        printed += write(1, "0x", 2);
        printed += write(1, str, ft_strlen(str));
    }

    if (flags->minus)
        printed += put_padding(' ', flags->width - len);

    free(str);
    return printed;
}


int print_decimal(t_flags *flags, va_list args)
{
    long long num = (long long)va_arg(args, int);
    char *str;
    int len;
    int printed = 0;
    int neg = 0;

    if (num < 0)
    {
        neg = 1;
        num = -num;
    }

    if (num == 0 && flags->dot && flags->precision == 0)
        str = ft_strdup("");
    else
        str = ft_itoa_base((unsigned long long)num, 10, 0);

    if (!str)
        return -1;

    len = (int)ft_strlen(str);

    // Calculate padding
    int prec_zeros = 0;
    if (flags->dot && flags->precision > len)
        prec_zeros = flags->precision - len;

    int width_padding = flags->width - len - prec_zeros - neg;

    // Left pad (spaces or zeros depending on flags)
    if (!flags->minus && (!flags->zero || flags->dot))
        printed += put_padding(' ', width_padding);

    // Sign
    if (neg)
        printed += write(1, "-", 1);
    else if (flags->plus)
        printed += write(1, "+", 1);
    else if (flags->space)
        printed += write(1, " ", 1);

    // Left pad zeros (if zero flag and no precision)
    if (!flags->minus && flags->zero && !flags->dot)
        printed += put_padding('0', width_padding);

    // Precision zeros
    printed += put_padding('0', prec_zeros);

    // Print number
    printed += write(1, str, len);

    // Right pad spaces
    if (flags->minus)
        printed += put_padding(' ', width_padding);

    free(str);
    return printed;
}

int print_unsigned(t_flags *flags, va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char *str;
    int len;
    int printed = 0;

    if (num == 0 && flags->dot && flags->precision == 0)
        str = ft_strdup("");
    else
        str = ft_itoa_base(num, 10, 0);

    if (!str)
        return -1;

    len = (int)ft_strlen(str);

    int prec_zeros = 0;
    if (flags->dot && flags->precision > len)
        prec_zeros = flags->precision - len;

    int width_padding = flags->width - len - prec_zeros;

    if (!flags->minus && (!flags->zero || flags->dot))
        printed += put_padding(' ', width_padding);

    if (!flags->minus && flags->zero && !flags->dot)
        printed += put_padding('0', width_padding);

    printed += put_padding('0', prec_zeros);

    printed += write(1, str, len);

    if (flags->minus)
        printed += put_padding(' ', width_padding);

    free(str);
    return printed;
}

int print_hex(t_flags *flags, va_list args, int uppercase)
{
    unsigned int num = va_arg(args, unsigned int);
    char *str;
    int len;
    int printed = 0;
    int prefix_len = 0;

    if (num == 0 && flags->dot && flags->precision == 0)
        str = ft_strdup("");
    else
        str = ft_itoa_base(num, 16, uppercase);

    if (!str)
        return -1;

    len = (int)ft_strlen(str);

    // '#' flag adds '0x' or '0X' prefix if number != 0
    if (flags->hash && num != 0)
        prefix_len = 2;

    int prec_zeros = 0;
    if (flags->dot && flags->precision > len)
        prec_zeros = flags->precision - len;

    int width_padding = flags->width - len - prec_zeros - prefix_len;

    if (!flags->minus && (!flags->zero || flags->dot))
        printed += put_padding(' ', width_padding);

    if (flags->hash && num != 0)
        printed += write(1, uppercase ? "0X" : "0x", 2);

    if (!flags->minus && flags->zero && !flags->dot)
        printed += put_padding('0', width_padding);

    printed += put_padding('0', prec_zeros);

    printed += write(1, str, len);

    if (flags->minus)
        printed += put_padding(' ', width_padding);

    free(str);
    return printed;
}

int print_percent(t_flags *flags)
{
    int printed = 0;

    if (!flags->minus)
        printed += put_padding(flags->zero ? '0' : ' ', flags->width - 1);

    printed += write(1, "%", 1);

    if (flags->minus)
        printed += put_padding(' ', flags->width - 1);

    return printed;
}
