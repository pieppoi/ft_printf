/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:00:41 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/08/14 16:36:02 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_hex(unsigned int t, int f)
{
	char	*str;
	int		count;

	str = ft_base_point((unsigned long long)t, 16);
	if (f == 1)
	{
		ft_alltolower(str);
	}
	count = ft_putstr_c(str);
	free(str);
	return (count);
}
