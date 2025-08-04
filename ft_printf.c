/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:08 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/30 17:43:26 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *inp, ...)
{
	const char	*save;
	va_list		arg;
	int			n;

	n = 0;
	save = ft_strdup(inp);
	if (!save)
		return (0);
	va_start(arg, inp);
	n = ft_count_out(save, arg);
	va_end(arg);
	free((char *)save);
	return (n);
}
