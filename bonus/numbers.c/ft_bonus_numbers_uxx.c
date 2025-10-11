/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_numbers_uxx.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:40:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 09:54:35 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static int	handle_uxx(const t_fmt *fmt, unsigned long long u,
	int base, int upper)
{
	t_uxx_params	params;

	params.base = base;
	params.upper = upper;
	calc_uxx_params(fmt, u, &params);
	return (output_uxx(fmt, u, &params));
}

int	ft_handle_uxx(const t_fmt *fmt, unsigned long long u,
	int base, int upper)
{
	return (handle_uxx(fmt, u, base, upper));
}
