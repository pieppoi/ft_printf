/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_numbers_di.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:40:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 09:54:35 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static int	output_di(const t_fmt *fmt, long long val, t_di_params *params)
{
	int	count;

	count = 0;
	count += output_di_padding(fmt, val, params);
	count += ft_put_n_chars('0', params->precision_len);
	count += output_di_number(val, params);
	if (fmt->flag_minus)
		count += ft_put_n_chars(' ', ft_calc_pad(fmt, params->total_len, 1));
	return (count);
}

static int	handle_di(const t_fmt *fmt, long long val)
{
	t_di_params	params;

	calc_di_params(fmt, val, &params);
	return (output_di(fmt, val, &params));
}

int	ft_handle_di(const t_fmt *fmt, long long val)
{
	return (handle_di(fmt, val));
}
