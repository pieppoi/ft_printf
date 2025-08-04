/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_point_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:18:53 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/08/14 16:36:28 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_base_change(unsigned long long u, int b, char *r, int c)
{
	while (u != 0)
	{
		if ((u % b) < 10)
			r[c - 1] = (u % b) + '0';
		else
			r[c - 1] = (u % b) + 'A' - 10;
		u = u / b;
		c--;
	}
	return (r);
}

char	*ft_base_point(unsigned long long p, int b)
{
	char				*r;
	unsigned long long	u;
	int					count;

	count = 0;
	u = p;
	if (p == 0)
		return (ft_strdup("0"));
	while (p != 0)
	{
		p /= b;
		count++;
	}
	r = ft_calloc(count + 1, sizeof(char));
	if (!r)
		return (0);
	r = ft_base_change(u, b, r, count);
	return (r);
}
