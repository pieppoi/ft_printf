/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 08:21:35 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int	ft_put_n_chars(char ch, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(ch, 1);
		i++;
	}
	if (n > 0)
		return (n);
	return (0);
}

static void	reverse_string(char *str, int len)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

static int	convert_to_base(unsigned long long v, int base,
	const char *digits, char *tmp)
{
	int	len;

	len = 0;
	if (v == 0)
		tmp[len++] = '0';
	while (v > 0)
	{
		tmp[len++] = digits[v % (unsigned)base];
		v /= (unsigned)base;
	}
	return (len);
}

int	ft_num_to_str_unsigned(unsigned long long v, int base, int upper,
	char *buf)
{
	const char	*digits_low = "0123456789abcdef";
	const char	*digits_up = "0123456789ABCDEF";
	const char	*digits;
	char		tmp[65];
	int			len;

	if (upper)
		digits = digits_up;
	else
		digits = digits_low;
	len = convert_to_base(v, base, digits, tmp);
	reverse_string(tmp, len);
	tmp[len] = '\0';
	ft_strlcpy(buf, tmp, len + 1);
	return (len);
}
