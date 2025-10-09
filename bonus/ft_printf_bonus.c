/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:39:22 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/09 20:43:34 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_printf_bonus(const char *inp, ...)
{
    const char *s;
    va_list     ap;
    int         count;
    int         i;

    count = 0;
    s = inp;
    va_start(ap, inp);
    i = 0;
    while (s[i])
    {
        if (s[i] == '%')
        {
            t_fmt fmt;
            int   next;

            i++;
            next = ft_parse_format(s, i, &fmt);
            if (next == -1)
            {
                ft_putchar_fd('%', 1);
                count++;
            }
            else
            {
                count += ft_format_print(&fmt, ap);
                i = next;
                continue;
            }
        }
        else
        {
            ft_putchar_fd(s[i], 1);
            count++;
            i++;
        }
    }
    va_end(ap);
    return (count);
}