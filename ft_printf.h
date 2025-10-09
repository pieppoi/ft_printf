/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:19:45 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/08/14 17:28:34 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stddef.h>

char	*ft_alltolower(char *c);
char	*ft_base_point(unsigned long long p, int b);
int		ft_count_out(const char *save, va_list arg);
int		ft_printf(const char *inp, ...);
int		ft_putstr_c(char *c);
int		ft_something_treat(int c, va_list arg);
int		ft_treat_char(char c);
int		ft_treat_hex(unsigned int t, int f);
int		ft_treat_int(int i);
int		ft_treat_point(unsigned long long point);
int		ft_treat_string(char *str);
int		ft_treat_uint(unsigned long long u);

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

// Bonus parsing/formatting
int     ft_parse_format(const char *s, int i, t_fmt *fmt);
int     ft_format_print(const t_fmt *fmt, va_list ap);

#endif