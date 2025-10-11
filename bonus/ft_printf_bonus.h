/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:39:54 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/10/11 09:54:35 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../srcs/ft_printf.h"

typedef struct s_fmt
{
	int		flag_minus;
	int		flag_zero;
	int		flag_hash;
	int		flag_plus;
	int		flag_space;
	int		width;
	int		precision;
	char	spec;
}	t_fmt;

typedef struct s_di_params
{
	int	nlen;
	int	precision_len;
	int	sign_len;
	int	total_len;
}	t_di_params;

typedef struct s_uxx_params
{
	int	nlen;
	int	precision_len;
	int	prefix_len;
	int	total_len;
	int	base;
	int	upper;
}	t_uxx_params;

int		ft_put_n_chars(char ch, int n);
int		ft_num_to_str_unsigned(unsigned long long v, int base, int upper,
			char *buf);
int		ft_calc_pad(const t_fmt *fmt, int inner, int is_right);

// DI functions
int		calc_di_params(const t_fmt *fmt, long long val, t_di_params *params);
int		output_di_padding(const t_fmt *fmt, long long val, t_di_params *params);
int		output_di_number(long long val, t_di_params *params);

// UXX functions
void	calc_uxx_params(const t_fmt *fmt, unsigned long long u,
			t_uxx_params *params);
int		output_uxx(const t_fmt *fmt, unsigned long long u,
			t_uxx_params *params);

// P functions
void	calc_p_params(const t_fmt *fmt, unsigned long long p,
			int *nlen, int *pad);
int		output_p_nil(const t_fmt *fmt, int pad);
int		output_p_hex(const t_fmt *fmt, unsigned long long p, int nlen,
			int pad);
int		output_p(const t_fmt *fmt, unsigned long long p, int nlen, int pad);

int		ft_parse_format(const char *s, int i, t_fmt *fmt);
void	ft_parse_flags(const char *s, int *i, t_fmt *fmt);
void	ft_parse_width(const char *s, int *i, t_fmt *fmt);
void	ft_parse_precision(const char *s, int *i, t_fmt *fmt);
int		ft_is_flag_char(char ch);
int		ft_is_spec_char(char ch);
int		ft_format_print(const t_fmt *fmt, va_list ap);
int		ft_printf_bonus(const char *fmt, ...);

void	handle_s_null(const t_fmt *fmt, const char **s, int *str_len);
int		ft_handle_c(const t_fmt *fmt, int c);
int		ft_handle_s(const t_fmt *fmt, const char *s);
int		ft_handle_p(const t_fmt *fmt, unsigned long long p);
int		ft_handle_di(const t_fmt *fmt, long long val);
int		ft_handle_uxx(const t_fmt *fmt, unsigned long long u, int base,
			int upper);
int		ft_handle_percent(const t_fmt *fmt);

#endif
