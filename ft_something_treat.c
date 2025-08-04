/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_something_treat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:27:14 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/08/14 16:36:38 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_something_treat(int c, va_list arg)
{
	int	n;

	n = 0;
	if (c == 'c')
		n = ft_treat_char(va_arg(arg, int));
	else if (c == 's')
		n = ft_treat_string(va_arg(arg, char *));
	else if (c == 'p')
		n = ft_treat_point((unsigned long long)va_arg(arg, void *));
	else if ((c == 'd') || (c == 'i'))
		n = ft_treat_int(va_arg(arg, int));
	else if (c == 'u')
		n = ft_treat_uint((unsigned long long)va_arg(arg, unsigned long long));
	else if (c == 'x')
		n = ft_treat_hex(va_arg(arg, unsigned int), 1);
	else if (c == 'X')
		n = ft_treat_hex(va_arg(arg, unsigned int), 2);
	else if (c == '%')
		n = ft_putstr_c("%");
	return (n);
}
