/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_numbers_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:40:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 09:48:13 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_calc_pad(const t_fmt *fmt, int inner, int is_right)
{
	int	pad;

	if (fmt->width > inner)
		pad = fmt->width - inner;
	else
		pad = 0;
	if (!is_right)
	{
		if (fmt->flag_minus)
			return (0);
		return (pad);
	}
	else
	{
		if (!fmt->flag_minus)
			return (0);
		return (pad);
	}
}
