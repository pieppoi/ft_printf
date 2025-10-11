/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_parse_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:30:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 09:50:36 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_parse_flags(const char *s, int *i, t_fmt *fmt)
{
	while (s[*i] && ft_is_flag_char(s[*i]))
	{
		if (s[*i] == '-')
			fmt->flag_minus = 1;
		else if (s[*i] == '0')
		{
			if (!ft_isdigit(s[*i + 1]))
				fmt->flag_zero = 1;
			else
				break ;
		}
		else if (s[*i] == '#')
			fmt->flag_hash = 1;
		else if (s[*i] == '+')
		{
			fmt->flag_plus = 1;
			fmt->flag_space = 0;
		}
		else if (s[*i] == ' ')
			fmt->flag_space = 1;
		(*i)++;
	}
}

void	ft_parse_width(const char *s, int *i, t_fmt *fmt)
{
	int	start_i;

	if (s[*i] && ft_isdigit(s[*i]))
	{
		start_i = *i;
		fmt->width = 0;
		while (s[*i] && ft_isdigit(s[*i]))
		{
			fmt->width = fmt->width * 10 + (s[*i] - '0');
			(*i)++;
		}
		if (s[start_i] == '0' && fmt->width > 0)
			fmt->flag_zero = 1;
	}
}

void	ft_parse_precision(const char *s, int *i, t_fmt *fmt)
{
	if (s[*i] == '.')
	{
		(*i)++;
		fmt->precision = 0;
		while (s[*i] && ft_isdigit(s[*i]))
		{
			fmt->precision = fmt->precision * 10 + (s[*i] - '0');
			(*i)++;
		}
	}
}

int	ft_is_flag_char(char ch)
{
	return (ch == '-' || ch == '0' || ch == '#' || ch == '+' || ch == ' ');
}

int	ft_is_spec_char(char ch)
{
	return (ch == 'c' || ch == 's' || ch == 'p' || ch == 'd' || ch == 'i'
		|| ch == 'u' || ch == 'x' || ch == 'X' || ch == '%');
}
