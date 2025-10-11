/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_handlers1b.c                              :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:35:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 08:35:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
#include <unistd.h>

static int	handle_s_precision(const t_fmt *fmt, int str_len)
{
	if (fmt->precision >= 0)
	{
		if (fmt->precision < str_len)
			str_len = fmt->precision;
	}
	return (str_len);
}

static void	handle_s_padding(const t_fmt *fmt, int inner, int *pad)
{
	if (fmt->width > inner)
		*pad = fmt->width - inner;
	else
		*pad = 0;
}

static int	handle_s(const t_fmt *fmt, const char *s)
{
	int	str_len;
	int	inner;
	int	pad;
	int	count;

	count = 0;
	if (!s)
		handle_s_null(fmt, &s, &str_len);
	else
		str_len = (int)ft_strlen(s);
	str_len = handle_s_precision(fmt, str_len);
	inner = str_len;
	handle_s_padding(fmt, inner, &pad);
	if (!fmt->flag_minus)
		count += ft_put_n_chars(' ', pad);
	if (inner > 0)
	{
		write(1, s, inner);
		count += inner;
	}
	if (fmt->flag_minus)
		count += ft_put_n_chars(' ', pad);
	return (count);
}

int	ft_handle_s(const t_fmt *fmt, const char *s)
{
	return (handle_s(fmt, s));
}
