/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/19 03:03:30 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_parse_format(const char *s, int *i, t_fmt *fmt)
{
	int	original_i;

	original_i = *i;
	fmt->flag_minus = 0;
	fmt->flag_zero = 0;
	fmt->flag_hash = 0;
	fmt->flag_plus = 0;
	fmt->flag_space = 0;
	fmt->width = -1;
	fmt->precision = -1;
	fmt->spec = '\0';
	ft_parse_flags(s, i, fmt);
	ft_parse_width(s, i, fmt);
	ft_parse_precision(s, i, fmt);
	if (s[*i] && ft_is_spec_char(s[*i]))
	{
		fmt->spec = s[*i];
		(*i)++;
		return (*i);
	}
	*i = original_i;
	return (-1);
}
