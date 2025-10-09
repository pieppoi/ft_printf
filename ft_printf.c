/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:08 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/30 17:43:26 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *inp, ...)
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
                // Invalid sequence: print '%' literally and continue
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
