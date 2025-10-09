/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:39:54 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/09 20:43:52 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
#define FT_PRINTF_BONUS_H

#include "../srcs/ft_printf.h"

typedef struct s_fmt
{
    int     flag_minus;
    int     flag_zero;
    int     flag_hash;
    int     flag_plus;
    int     flag_space;
    int     width;      // -1 if not specified
    int     precision;  // -1 if not specified
    char    spec;       // one of cspdiuxX%
}   t_fmt;

int     ft_parse_format(const char *s, int i, t_fmt *fmt);
int     ft_format_print(const t_fmt *fmt, va_list ap);

int     ft_printf_bonus(const char *fmt, ...);

#endif