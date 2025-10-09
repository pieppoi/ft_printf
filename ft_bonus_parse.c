/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/09 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t parse_number(const char *s, size_t i, int *out)
{
    long value;

    value = 0;
    while (ft_isdigit((unsigned char)s[i]))
    {
        value = value * 10 + (s[i] - '0');
        i++;
        if (value > 1000000000)
            break;
    }
    *out = (int)value;
    return i;
}

static void init_format(t_format *fmt)
{
    fmt->flag_minus = 0;
    fmt->flag_zero = 0;
    fmt->flag_hash = 0;
    fmt->flag_space = 0;
    fmt->flag_plus = 0;
    fmt->width = 0;
    fmt->precision = 0;
    fmt->precision_specified = 0;
    fmt->spec = '\0';
}

size_t ft_parse_format(const char *s, size_t i, t_format *fmt)
{
    init_format(fmt);
    /* flags */
    while (s[i] == '-' || s[i] == '0' || s[i] == '#' || s[i] == ' ' || s[i] == '+')
    {
        if (s[i] == '-')
            fmt->flag_minus = 1;
        else if (s[i] == '0')
            fmt->flag_zero = 1;
        else if (s[i] == '#')
            fmt->flag_hash = 1;
        else if (s[i] == ' ')
            fmt->flag_space = 1;
        else if (s[i] == '+')
            fmt->flag_plus = 1;
        i++;
    }
    /* width */
    if (ft_isdigit((unsigned char)s[i]))
        i = parse_number(s, i, &fmt->width);
    /* precision */
    if (s[i] == '.')
    {
        i++;
        fmt->precision_specified = 1;
        fmt->precision = 0;
        if (ft_isdigit((unsigned char)s[i]))
            i = parse_number(s, i, &fmt->precision);
    }
    /* specifier */
    if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd' || s[i] == 'i'
        || s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == '%')
    {
        fmt->spec = s[i];
    }
    return i;
}
