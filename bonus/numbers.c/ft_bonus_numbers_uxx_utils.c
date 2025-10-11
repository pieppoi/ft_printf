/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_numbers_uxx_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:40:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 09:54:35 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static int	calc_prefix_len(const t_fmt *fmt, unsigned long long u, int base)
{
	if (fmt->flag_hash && u != 0)
	{
		if (base == 16)
			return (2);
		else if (base == 8)
			return (1);
	}
	return (0);
}

static int	output_prefix(const t_fmt *fmt, unsigned long long u, int base,
	int upper)
{
	int	count;

	count = 0;
	if (fmt->flag_hash && u != 0)
	{
		if (base == 16)
		{
			if (upper)
				write(1, "0X", 2);
			else
				write(1, "0x", 2);
			count += 2;
		}
		else if (base == 8)
		{
			write(1, "0", 1);
			count += 1;
		}
	}
	return (count);
}

void	calc_uxx_params(const t_fmt *fmt, unsigned long long u,
	t_uxx_params *params)
{
	char	num[65];

	params->nlen = ft_num_to_str_unsigned(u, params->base, 0, num);
	if (fmt->precision == 0 && u == 0)
		params->nlen = 0;
	params->precision_len = 0;
	if (fmt->precision >= 0 && fmt->precision > params->nlen)
		params->precision_len = fmt->precision - params->nlen;
	params->prefix_len = calc_prefix_len(fmt, u, params->base);
	params->total_len = params->prefix_len + params->precision_len
		+ params->nlen;
}

int	output_uxx(const t_fmt *fmt, unsigned long long u,
	t_uxx_params *params)
{
	char	num[65];
	int		count;

	count = 0;
	if (fmt->flag_zero && !fmt->flag_minus && fmt->precision < 0)
	{
		count += output_prefix(fmt, u, params->base, params->upper);
		count += ft_put_n_chars('0', fmt->width - params->total_len);
	}
	else
	{
		count += ft_put_n_chars(' ', ft_calc_pad(fmt, params->total_len, 0));
		count += output_prefix(fmt, u, params->base, params->upper);
	}
	count += ft_put_n_chars('0', params->precision_len);
	if (params->nlen > 0)
	{
		ft_num_to_str_unsigned(u, params->base, params->upper, num);
		write(1, num, params->nlen);
		count += params->nlen;
	}
	if (fmt->flag_minus)
		count += ft_put_n_chars(' ', ft_calc_pad(fmt, params->total_len, 1));
	return (count);
}
