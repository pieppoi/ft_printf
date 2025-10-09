/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:57:08 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/09/12 18:39:34 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_point(unsigned long long point)
{
	char	*p;
	int		n;

	if (!point)
	{
		n = ft_putstr_c("(nil)");
		return (n);
	}
	p = ft_alltolower(ft_base_point(point, 16));
	n = ft_putstr_c("0x");
	n += ft_putstr_c(p);
	free(p);
	return (n);
}
