/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:24:34 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/30 17:22:59 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_out(const char *save, va_list arg)
{
    size_t i;
    int    count;

    i = 0;
    count = 0;
    while (save[i])
    {
        if (save[i] == '%')
        {
            t_format fmt;
            size_t    j;

            j = ft_parse_format(save, i + 1, &fmt);
            if (fmt.spec != '\0')
            {
                count += ft_dispatch_format(&fmt, arg);
                i = j + 1;
                continue;
            }
            /* fallthrough: not a valid spec, print '%' literally */
            ft_putchar_fd('%', 1);
            count++;
            i++;
        }
        else
        {
            ft_putchar_fd(save[i], 1);
            count++;
            i++;
        }
    }
    return (count);
}
