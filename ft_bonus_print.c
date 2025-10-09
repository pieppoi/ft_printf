/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:01:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/09 10:01:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int write_nchar(char c, int n)
{
    int written;

    written = 0;
    while (n-- > 0)
    {
        ft_putchar_fd(c, 1);
        written++;
    }
    return written;
}

static int write_strn(const char *s, int len)
{
    int i;

    if (len <= 0)
        return 0;
    i = 0;
    while (i < len && s[i])
    {
        ft_putchar_fd(s[i], 1);
        i++;
    }
    return i;
}

static int max_int(int a, int b)
{
    return (a > b) ? a : b;
}

static int print_with_width(const char *prefix, int zeros, const char *digits, int digits_len, const t_format *fmt, int zero_pad_allowed)
{
    int count;
    int prefix_len;
    int total_core;
    int pad_len;
    int left_align;
    int pad_with_zero;

    prefix_len = (int)ft_strlen((char *)prefix);
    total_core = prefix_len + zeros + digits_len;
    pad_len = (fmt->width > total_core) ? (fmt->width - total_core) : 0;
    left_align = (fmt->flag_minus != 0);
    pad_with_zero = (fmt->flag_zero != 0) && !left_align && !fmt->precision_specified && zero_pad_allowed;
    count = 0;
    if (!left_align && !pad_with_zero)
        count += write_nchar(' ', pad_len);
    /* when zero padding is active, zeros act as left pad after prefix */
    count += write_strn(prefix, prefix_len);
    if (pad_with_zero)
        count += write_nchar('0', pad_len);
    count += write_nchar('0', zeros);
    count += write_strn(digits, digits_len);
    if (left_align)
        count += write_nchar(' ', pad_len);
    return count;
}

static int dispatch_char(const t_format *fmt, char c)
{
    char tmp[1];
    int pad_len;
    int count;
    int left_align;
    int pad_with_zero;

    tmp[0] = c;
    left_align = (fmt->flag_minus != 0);
    pad_with_zero = (fmt->flag_zero != 0) && !left_align;
    pad_len = (fmt->width > 1) ? (fmt->width - 1) : 0;
    count = 0;
    if (!left_align)
        count += write_nchar(pad_with_zero ? '0' : ' ', pad_len);
    count += write_strn(tmp, 1);
    if (left_align)
        count += write_nchar(' ', pad_len);
    return count;
}

static int dispatch_string(const t_format *fmt, const char *s)
{
    int len;
    int to_print;
    int pad_len;
    int left_align;
    int pad_with_zero;
    int count;

    if (!s)
        s = "(null)";
    len = (int)ft_strlen((char *)s);
    to_print = fmt->precision_specified ? max_int(0, (int)fmt->precision) : len;
    if (fmt->precision_specified && to_print < len)
        len = to_print;
    else
        len = (int)ft_strlen((char *)s);
    left_align = (fmt->flag_minus != 0);
    pad_with_zero = (fmt->flag_zero != 0) && !left_align; /* allowed for s */
    pad_len = (fmt->width > len) ? (fmt->width - len) : 0;
    count = 0;
    if (!left_align)
        count += write_nchar(pad_with_zero ? '0' : ' ', pad_len);
    count += write_strn(s, len);
    if (left_align)
        count += write_nchar(' ', pad_len);
    return count;
}

static int dispatch_percent(const t_format *fmt)
{
    return dispatch_char(fmt, '%');
}

static int dispatch_signed(const t_format *fmt, int value)
{
    char *raw;
    int negative;
    const char *digits;
    int digits_len;
    int zeros;
    char prefix_buf[2];
    const char *prefix;

    raw = ft_itoa(value);
    if (!raw)
        return 0;
    negative = (raw[0] == '-');
    digits = negative ? (raw + 1) : raw;
    digits_len = (int)ft_strlen((char *)digits);
    if (fmt->precision_specified && fmt->precision == 0 && digits_len == 1 && digits[0] == '0')
        digits_len = 0;
    zeros = 0;
    if (fmt->precision_specified)
        zeros = (fmt->precision > digits_len) ? (fmt->precision - digits_len) : 0;
    prefix = "";
    if (negative)
        prefix = "-";
    else if (fmt->flag_plus)
    {
        prefix_buf[0] = '+'; prefix_buf[1] = '\0';
        prefix = prefix_buf;
    }
    else if (fmt->flag_space)
    {
        prefix_buf[0] = ' '; prefix_buf[1] = '\0';
        prefix = prefix_buf;
    }
    /* zero padding allowed for numeric */
    digits_len = print_with_width(prefix, zeros, digits, digits_len, fmt, 1);
    free(raw);
    return digits_len;
}

static int dispatch_unsigned_base(const t_format *fmt, unsigned long long value, int base, int is_hex_upper, int allow_alt)
{
    char *digits_str;
    int digits_len;
    int zeros;
    const char *prefix;
    char prefix_buf[3];
    int is_nonzero;

    digits_str = ft_base_point(value, base);
    if (!digits_str)
        return 0;
    if (base == 16 && !is_hex_upper)
        ft_alltolower(digits_str);
    is_nonzero = !(digits_str[0] == '0' && digits_str[1] == '\0');
    digits_len = (int)ft_strlen(digits_str);
    if (fmt->precision_specified && fmt->precision == 0 && !value)
        digits_len = 0; /* print nothing for 0 with precision 0 */
    zeros = 0;
    if (fmt->precision_specified)
        zeros = (fmt->precision > digits_len) ? (fmt->precision - digits_len) : 0;
    prefix = "";
    if (allow_alt && fmt->flag_hash && is_nonzero)
    {
        if (base == 16)
        {
            prefix_buf[0] = '0';
            prefix_buf[1] = is_hex_upper ? 'X' : 'x';
            prefix_buf[2] = '\0';
            prefix = prefix_buf;
        }
    }
    /* zero padding allowed for numeric */
    digits_len = print_with_width(prefix, zeros, digits_str, digits_len, fmt, 1);
    free(digits_str);
    return digits_len;
}

static int dispatch_pointer(const t_format *fmt, unsigned long long ptr)
{
    if (ptr == 0)
    {
        /* keep mandatory behavior: (nil) */
        t_format copy;
        copy = *fmt;
        copy.flag_zero = 0; /* padding with spaces for nil */
        return dispatch_string(&copy, "(nil)");
    }
    else
    {
        char *digits;
        int digits_len;
        int zeros;
        const char *prefix;

        digits = ft_base_point(ptr, 16);
        if (!digits)
            return 0;
        ft_alltolower(digits);
        digits_len = (int)ft_strlen(digits);
        if (fmt->precision_specified && fmt->precision == 0 && ptr == 0)
            digits_len = 0;
        zeros = 0;
        if (fmt->precision_specified)
            zeros = (fmt->precision > digits_len) ? (fmt->precision - digits_len) : 0;
        prefix = "0x";
        /* zero padding allowed */
        digits_len = print_with_width(prefix, zeros, digits, digits_len, fmt, 1);
        free(digits);
        return digits_len;
    }
}

int ft_dispatch_format(const t_format *fmt, va_list args)
{
    if (fmt->spec == 'c')
        return dispatch_char(fmt, (char)va_arg(args, int));
    else if (fmt->spec == 's')
        return dispatch_string(fmt, va_arg(args, char *));
    else if (fmt->spec == '%')
        return dispatch_percent(fmt);
    else if (fmt->spec == 'd' || fmt->spec == 'i')
        return dispatch_signed(fmt, va_arg(args, int));
    else if (fmt->spec == 'u')
        return dispatch_unsigned_base(fmt, (unsigned int)va_arg(args, unsigned int), 10, 1, 0);
    else if (fmt->spec == 'x')
        return dispatch_unsigned_base(fmt, (unsigned int)va_arg(args, unsigned int), 16, 0, 1);
    else if (fmt->spec == 'X')
        return dispatch_unsigned_base(fmt, (unsigned int)va_arg(args, unsigned int), 16, 1, 1);
    else if (fmt->spec == 'p')
        return dispatch_pointer(fmt, (unsigned long long)va_arg(args, void *));
    return 0;
}
