/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_handlers2a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:58:57 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 09:58:58 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static int	handle_p(const t_fmt *fmt, unsigned long long p)
{
	int	nlen;
	int	pad;

	calc_p_params(fmt, p, &nlen, &pad);
	return (output_p(fmt, p, nlen, pad));
}

int	ft_handle_p(const t_fmt *fmt, unsigned long long p)
{
	return (handle_p(fmt, p));
}
