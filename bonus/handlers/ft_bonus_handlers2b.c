/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_handlers2b.c                              :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:35:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 08:35:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
#include <unistd.h>

static int	handle_percent(const t_fmt *fmt)
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
	ft_putchar_fd('%', 1);
	count += 1;
	if (fmt->flag_minus)
		count += ft_put_n_chars(' ', pad);
	return (count);
}

int	ft_handle_percent(const t_fmt *fmt)
{
	return (handle_percent(fmt));
}
