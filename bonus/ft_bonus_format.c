/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_format.c                                  :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 08:16:59 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_format_print(const t_fmt *fmt, va_list ap)
{
	if (fmt->spec == 'c')
		return (ft_handle_c(fmt, va_arg(ap, int)));
	else if (fmt->spec == 's')
		return (ft_handle_s(fmt, va_arg(ap, char *)));
	else if (fmt->spec == 'p')
		return (ft_handle_p(fmt, (unsigned long long)va_arg(ap, void *)));
	else if (fmt->spec == 'd' || fmt->spec == 'i')
		return (ft_handle_di(fmt, va_arg(ap, int)));
	else if (fmt->spec == 'u')
		return (ft_handle_uxx(fmt, va_arg(ap, unsigned int), 10, 0));
	else if (fmt->spec == 'x')
		return (ft_handle_uxx(fmt, va_arg(ap, unsigned int), 16, 0));
	else if (fmt->spec == 'X')
		return (ft_handle_uxx(fmt, va_arg(ap, unsigned int), 16, 1));
	else if (fmt->spec == '%')
		return (ft_handle_percent(fmt));
	return (0);
}
