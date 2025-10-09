/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+      */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/09 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/ft_printf_bonus.h"

static int max_int(int a, int b) { return (a > b ? a : b); }

static int put_n_chars(char ch, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        ft_putchar_fd(ch, 1);
        i++;
    }
    return (n > 0 ? n : 0);
}

static int print_sign(long long value, const t_fmt *fmt)
{
    if (value < 0)
    {
        ft_putchar_fd('-', 1);
        return 1;
    }
    if (fmt->flag_plus)
    {
        ft_putchar_fd('+', 1);
        return 1;
    }
    if (fmt->flag_space)
    {
        ft_putchar_fd(' ', 1);
        return 1;
    }
    return 0;
}

static int num_to_str_unsigned(unsigned long long v, int base, int upper, char *buf)
{
    const char *digits_low = "0123456789abcdef";
    const char *digits_up  = "0123456789ABCDEF";
    const char *digits = upper ? digits_up : digits_low;
    char tmp[65];
    int len = 0;

    if (v == 0)
        tmp[len++] = '0';
    while (v > 0)
    {
        tmp[len++] = digits[v % (unsigned)base];
        v /= (unsigned)base;
    }
    // reverse into buf
    for (int i = 0; i < len; i++)
        buf[i] = tmp[len - 1 - i];
    buf[len] = '\0';
    return len;
}

// unused helper intentionally removed

static int handle_c(const t_fmt *fmt, int ch)
{
    int inner = 1;
    int pad = (fmt->width > inner) ? (fmt->width - inner) : 0;
    int count = 0;

    if (!fmt->flag_minus)
        count += put_n_chars(' ', pad);
    ft_putchar_fd((char)ch, 1);
    count += 1;
    if (fmt->flag_minus)
        count += put_n_chars(' ', pad);
    return count;
}

static int handle_s(const t_fmt *fmt, const char *s)
{
    int str_len;
    int inner;
    int pad;
    int count = 0;

    if (!s)
        s = "(null)";
    str_len = (int)ft_strlen(s);
    if (fmt->precision >= 0 && fmt->precision < str_len)
        str_len = fmt->precision;
    inner = str_len;
    pad = (fmt->width > inner) ? (fmt->width - inner) : 0;

    if (!fmt->flag_minus)
        count += put_n_chars(' ', pad);
    write(1, s, inner);
    count += inner;
    if (fmt->flag_minus)
        count += put_n_chars(' ', pad);
    return count;
}

static int handle_p(const t_fmt *fmt, unsigned long long ptr)
{
    char num[17];
    int  nlen;
    int  inner;
    int  pad;
    int  count = 0;

    if (ptr == 0)
    {
        // GNU printf prints (nil) with no width/precision adjustments beyond padding
        const char *nil = "(nil)";
        inner = (fmt->precision >= 0 && fmt->precision < 5) ? fmt->precision : 5;
        // For pointers, precision doesn't apply in standard printf; we ignore it for (nil)
        inner = 5;
        pad = (fmt->width > inner) ? (fmt->width - inner) : 0;
        if (!fmt->flag_minus)
            count += put_n_chars(' ', pad);
        write(1, nil, 5);
        count += 5;
        if (fmt->flag_minus)
            count += put_n_chars(' ', pad);
        return count;
    }

    nlen = num_to_str_unsigned(ptr, 16, 0, num);
    int prec_zeros = 0;
    if (fmt->precision >= 0)
        prec_zeros = (fmt->precision > nlen) ? (fmt->precision - nlen) : 0;

    // prefix "0x"
    int prefix = 2;
    inner = prefix + prec_zeros + nlen;
    pad = (fmt->width > inner) ? (fmt->width - inner) : 0;

    if (!fmt->flag_minus)
        count += put_n_chars(' ', pad);
    write(1, "0x", 2);
    count += 2;
    count += put_n_chars('0', prec_zeros);
    write(1, num, nlen);
    count += nlen;
    if (fmt->flag_minus)
        count += put_n_chars(' ', pad);
    return count;
}

static int handle_di(const t_fmt *fmt, long long val)
{
    char num[21];
    unsigned long long u;
    int negative = (val < 0);
    int nlen;
    int sign_len;
    int inner;
    int pad;
    int count = 0;

    if (negative)
        u = (unsigned long long)(-(long long)val);
    else
        u = (unsigned long long)val;

    nlen = num_to_str_unsigned(u, 10, 0, num);

    // Precision suppresses output for zero when precision==0
    if (fmt->precision == 0 && u == 0)
        nlen = 0;

    sign_len = (negative || fmt->flag_plus || fmt->flag_space) ? 1 : 0;

    int prec_zeros = 0;
    if (fmt->precision >= 0)
        prec_zeros = (fmt->precision > nlen) ? (fmt->precision - nlen) : 0;

    // When precision is specified, '0' flag is ignored
    int zero_padding = 0;
    if (fmt->precision < 0 && fmt->flag_zero && !fmt->flag_minus && fmt->width > (sign_len + nlen))
        zero_padding = fmt->width - (sign_len + nlen);

    inner = sign_len + max_int(prec_zeros + nlen, nlen + zero_padding);
    pad = (fmt->width > inner) ? (fmt->width - inner) : 0;

    if (!fmt->flag_minus)
        count += put_n_chars(' ', pad);
    if (sign_len)
        count += print_sign(negative ? -1 : 1, fmt);
    count += put_n_chars('0', (fmt->precision >= 0) ? prec_zeros : zero_padding);
    if (nlen > 0)
    {
        write(1, num, nlen);
        count += nlen;
    }
    if (fmt->flag_minus)
        count += put_n_chars(' ', pad);
    return count;
}

static int handle_uxx(const t_fmt *fmt, unsigned long long u, int base, int upper, int is_hex)
{
    char num[65];
    int nlen;
    int inner;
    int pad;
    int count = 0;
    int prefix_len = 0;

    nlen = num_to_str_unsigned(u, base, upper, num);

    // Precision==0 and value==0 => empty
    if (fmt->precision == 0 && u == 0)
        nlen = 0;

    if (is_hex && fmt->flag_hash && u != 0)
        prefix_len = 2; // 0x or 0X

    int prec_zeros = 0;
    if (fmt->precision >= 0)
        prec_zeros = (fmt->precision > nlen) ? (fmt->precision - nlen) : 0;

    int zero_padding = 0;
    if (fmt->precision < 0 && fmt->flag_zero && !fmt->flag_minus && fmt->width > (prefix_len + nlen))
        zero_padding = fmt->width - (prefix_len + nlen);

    inner = prefix_len + ((fmt->precision >= 0) ? (prec_zeros + nlen) : (zero_padding + nlen));
    pad = (fmt->width > inner) ? (fmt->width - inner) : 0;

    if (!fmt->flag_minus)
        count += put_n_chars(' ', pad);
    if (prefix_len)
    {
        if (upper)
            write(1, "0X", 2);
        else
            write(1, "0x", 2);
        count += 2;
    }
    count += put_n_chars('0', (fmt->precision >= 0) ? prec_zeros : zero_padding);
    if (nlen > 0)
    {
        write(1, num, nlen);
        count += nlen;
    }
    if (fmt->flag_minus)
        count += put_n_chars(' ', pad);
    return count;
}

static int handle_percent(const t_fmt *fmt)
{
    (void)fmt;
    ft_putchar_fd('%', 1);
    return 1;
}

int ft_format_print(const t_fmt *fmt, va_list ap)
{
    if (fmt->spec == 'c')
        return handle_c(fmt, va_arg(ap, int));
    if (fmt->spec == 's')
        return handle_s(fmt, va_arg(ap, const char *));
    if (fmt->spec == 'p')
        return handle_p(fmt, (unsigned long long)va_arg(ap, void *));
    if (fmt->spec == 'd' || fmt->spec == 'i')
        return handle_di(fmt, (long long)va_arg(ap, int));
    if (fmt->spec == 'u')
        return handle_uxx(fmt, (unsigned long long)va_arg(ap, unsigned int), 10, 0, 0);
    if (fmt->spec == 'x')
        return handle_uxx(fmt, (unsigned long long)va_arg(ap, unsigned int), 16, 0, 1);
    if (fmt->spec == 'X')
        return handle_uxx(fmt, (unsigned long long)va_arg(ap, unsigned int), 16, 1, 1);
    if (fmt->spec == '%')
        return handle_percent(fmt);
    return 0;
}
