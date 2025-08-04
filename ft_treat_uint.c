/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:46:22 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/08/14 16:36:11 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_nbr_cu(unsigned int n)
{
	char			str;
	unsigned int	tmp;
	size_t			t;

	tmp = n;
	t = 0;
	while (9 < tmp)
	{
		tmp = tmp / 10;
		t++;
	}
	if (9 < n)
		ft_put_nbr_cu(n / 10);
	str = '0' + n % 10;
	write(1, &str, 1);
	return (t + 1);
}

int	ft_treat_uint(unsigned long long uint)
{
	int	n;

	n = 0;
	n = ft_put_nbr_cu((unsigned int)uint);
	return (n);
}
