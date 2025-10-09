/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:24:34 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/30 17:22:59 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_out(const char *save, va_list arg)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (save[i])
	{
		if (save[i] == '%')
		{
			i++;
			c += ft_something_treat(save[i], arg);
		}
		else
		{
			ft_putchar_fd(save[i], 1);
			c++;
		}
		i++;
		if (!save[i])
			return (c);
	}
	return (c);
}
