/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:39:22 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/19 01:17:34 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	handle_format(const char *s, int *i, int *count, va_list ap)
{
	t_fmt	fmt;
	int		next;

	(*i)++;
	next = ft_parse_format(s, i, &fmt);
	if (next == -1)
	{
		ft_putchar_fd('%', 1);
		(*count)++;
		return (0);
	}
	*count += ft_format_print(&fmt, ap);
	*i = next;
	return (1);
}

int	ft_printf_bonus(const char *inp, ...)
{
	const char	*s;
	va_list		ap;
	int			count;
	int			i;

	count = 0;
	s = inp;
	va_start(ap, inp);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (handle_format(s, &i, &count, ap))
				continue ;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			count++;
			i++;
		}
	}
	va_end(ap);
	return (count);
}

static int	handle_format2(const char *s, int *i, int *count, va_list ap)
{
	t_fmt	fmt;
	int		next;

	(*i)++;
	if (s[*i] == '\0')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
		return (-1);
	}
	next = ft_parse_format(s, i, &fmt);
	if (next == -1)
	{
		ft_putchar_fd('%', 1);
		(*count)++;
		return (0);
	}
	*count += ft_format_print(&fmt, ap);
	*i = next;
	return (1);
}

static int	process_printf(const char *s, va_list ap)
{
	int	count;
	int	i;
	int	ret;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			ret = handle_format2(s, &i, &count, ap);
			if (ret == -1)
				break ;
			if (ret == 1)
				continue ;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			count++;
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *inp, ...)
{
	const char	*s;
	va_list		ap;
	int			count;

	s = inp;
	va_start(ap, inp);
	count = process_printf(s, ap);
	va_end(ap);
	return (count);
}
