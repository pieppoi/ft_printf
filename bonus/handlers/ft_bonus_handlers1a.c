/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_handlers1a.c                              :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:35:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 08:35:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
#include <unistd.h>

static int	handle_c(const t_fmt *fmt, int c)
{
	int	pad;
	int	count;

	count = 0;
	if (fmt->width > 1)
		pad = fmt->width - 1;
	else
		pad = 0;
	if (!fmt->flag_minus)
		count += ft_put_n_chars(' ', pad);
	ft_putchar_fd(c, 1);
	count += 1;
	if (fmt->flag_minus)
		count += ft_put_n_chars(' ', pad);
	return (count);
}

void	handle_s_null(const t_fmt *fmt, const char **s, int *str_len)
{
	if (fmt->precision >= 0)
	{
		*s = "";
		*str_len = 0;
	}
	else
	{
		*s = "(null)";
		*str_len = 6;
	}
}

int	ft_handle_c(const t_fmt *fmt, int c)
{
	return (handle_c(fmt, c));
}
