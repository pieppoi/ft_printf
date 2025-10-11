/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:19:45 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 08:12:04 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
/* no extra includes for mandatory */

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

/* bonus structures and APIs are declared in bonus/ft_printf_bonus.h */

#endif