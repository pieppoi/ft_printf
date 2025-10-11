/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_numbers_di_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:40:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 09:54:35 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static int	calc_sign_len(const t_fmt *fmt, int is_negative)
{
	if (is_negative)
		return (1);
	else if (fmt->flag_plus)
		return (1);
	else if (fmt->flag_space)
		return (1);
	return (0);
}

static int	output_sign(const t_fmt *fmt, int is_negative, int sign_len)
{
	if (is_negative)
		ft_putchar_fd('-', 1);
	else if (fmt->flag_plus)
		ft_putchar_fd('+', 1);
	else if (fmt->flag_space)
		ft_putchar_fd(' ', 1);
	return (sign_len);
}

int	calc_di_params(const t_fmt *fmt, long long val, t_di_params *params)
{
	unsigned long long	u;
	char				num[21];

	if (val < 0)
		u = (unsigned long long)(-(long long)val);
	else
		u = (unsigned long long)val;
	params->nlen = ft_num_to_str_unsigned(u, 10, 0, num);
	if (fmt->precision == 0 && u == 0)
		params->nlen = 0;
	params->precision_len = 0;
	if (fmt->precision >= 0 && fmt->precision > params->nlen)
		params->precision_len = fmt->precision - params->nlen;
	params->sign_len = calc_sign_len(fmt, val < 0);
	params->total_len = params->sign_len + params->precision_len + params->nlen;
	return (0);
}

int	output_di_padding(const t_fmt *fmt, long long val,
	t_di_params *params)
{
	int	count;

	count = 0;
	if (fmt->flag_zero && !fmt->flag_minus && fmt->precision < 0)
	{
		count += output_sign(fmt, val < 0, params->sign_len);
		if (fmt->width > params->total_len)
			count += ft_put_n_chars('0', fmt->width - params->total_len);
	}
	else
	{
		count += ft_put_n_chars(' ', ft_calc_pad(fmt, params->total_len, 0));
		count += output_sign(fmt, val < 0, params->sign_len);
	}
	return (count);
}

int	output_di_number(long long val, t_di_params *params)
{
	unsigned long long	u;
	char				num[21];
	int					count;

	count = 0;
	if (params->nlen > 0)
	{
		if (val < 0)
			u = (unsigned long long)(-(long long)val);
		else
			u = (unsigned long long)val;
		ft_num_to_str_unsigned(u, 10, 0, num);
		write(1, num, params->nlen);
		count += params->nlen;
	}
	return (count);
}
