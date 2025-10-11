/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_handlers2a_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:58:27 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 09:58:30 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	calc_p_params(const t_fmt *fmt, unsigned long long p,
	int *nlen, int *pad)
{
	char	num[65];

	if (p == 0)
	{
		*nlen = 3;
		if (fmt->width > 3)
			*pad = fmt->width - 3;
		else
			*pad = 0;
	}
	else
	{
		*nlen = ft_num_to_str_unsigned(p, 16, 0, num);
		if (fmt->precision == 0 && p == 0)
			*nlen = 0;
		if (fmt->width > 2 + *nlen)
			*pad = fmt->width - 2 - *nlen;
		else
			*pad = 0;
	}
}

int	output_p_nil(const t_fmt *fmt, int pad)
{
	int	count;

	count = 0;
	if (!fmt->flag_minus)
		count += ft_put_n_chars(' ', pad);
	write(1, "(nil)", 5);
	count += 5;
	if (fmt->flag_minus)
		count += ft_put_n_chars(' ', pad);
	return (count);
}

int	output_p_hex(const t_fmt *fmt, unsigned long long p, int nlen,
	int pad)
{
	char	num[65];
	int		count;

	count = 0;
	ft_num_to_str_unsigned(p, 16, 0, num);
	if (!fmt->flag_minus)
		count += ft_put_n_chars(' ', pad);
	write(1, "0x", 2);
	count += 2;
	if (nlen > 0)
	{
		write(1, num, nlen);
		count += nlen;
	}
	if (fmt->flag_minus)
		count += ft_put_n_chars(' ', pad);
	return (count);
}

int	output_p(const t_fmt *fmt, unsigned long long p, int nlen, int pad)
{
	if (p == 0)
		return (output_p_nil(fmt, pad));
	else
		return (output_p_hex(fmt, p, nlen, pad));
}
