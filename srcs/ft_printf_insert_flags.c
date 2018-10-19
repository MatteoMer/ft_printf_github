/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_insert_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:34:26 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/19 12:53:21 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		usefull_insert_flags(t_infos *infos, int base, int *neg)
{
	(void)base;
	if (infos->options->opt_zero == 1 && infos->options->precision > 0)
		infos->options->field_width--;
	if ((infos->options->opt_zero == 0 || infos->options->\
				precision > 0) && infos->options->opt_minus == 0)
		insert_field(infos);
	*neg = 1;
	infos->buffer[infos->buf_index] = '-';
	ft_memmove(infos->tmp_str, infos->\
			tmp_str + 1, ft_strlen(infos->tmp_str) - 1);
	infos->tmp_str[ft_strlen(infos->tmp_str) - 1] = 0;
	return (0);
}

static int		usefull_insert_flags_2(t_infos *infos, int base, int neg)
{
	(void)base;
	if (!neg && infos->options->opt_space == 1)
		infos->buffer[infos->buf_index] = ' ';
	if (!neg && infos->options->opt_plus == 1)
		infos->buffer[infos->buf_index] = '+';
	return (0);
}

int				insert_flags(t_infos *infos, int base)
{
	int			neg;

	neg = 0;
	if (base != 10 || infos->is_unsigned)
		return (0);
	if (infos->options->opt_minus == 0 && (infos->options->\
opt_zero == 0 || infos->options->precision > 0) && (infos->options->\
opt_space || infos->options->opt_plus))
		insert_field(infos);
	if (infos->tmp_str[0] == '-')
		usefull_insert_flags(infos, base, &neg);
	usefull_insert_flags_2(infos, base, neg);
	if (infos->buffer[infos->buf_index] == '+' || infos->buffer\
[infos->buf_index] == ' ' || infos->buffer[infos->buf_index] == '-')
	{
		infos->buf_index++;
		infos->total_ret++;
	}
	if ((neg && infos->options->opt_minus == 0) || (infos->options->\
opt_minus == 0 && infos->options->opt_zero == 1 && infos->options->\
precision == 0 && (infos->options->opt_space || infos->options->opt_plus)))
		insert_field(infos);
	infos->buf_index = infos->total_ret;
	return (0);
}

static int		useful_insert_hashtag(t_infos *infos, int base, int maj, int nb)
{
	(void)nb;
	if (base != 8)
	{
		if (base == 16)
			ft_strcat(infos->buffer, maj == 0 ? "0x" : "0X");
		else if (base == 2)
			ft_strcat(infos->buffer, maj == 0 ? "0b" : "0B");
		infos->buf_index += 2;
		infos->total_ret += 2;
	}
	else
	{
		if (infos->tmp_str[0] != '0')
		{
			ft_strcat(infos->buffer, "0");
			infos->buf_index++;
			infos->total_ret++;
		}
	}
	return (0);
}

int				insert_hashtag(t_infos *infos, int base, int maj, int nb)
{
	if (base == 10 || nb == 0)
		return (0);
	if (infos->options->opt_hashtag == 0)
		return (0);
	infos->options->field_width -= base == 8 ? 1 : 2;
	if (infos->tmp_str[0] != '-' && infos->options->opt_minus == 0 && (infos->\
				options->opt_zero == 0 || infos->options->precision > 0))
		insert_field(infos);
	useful_insert_hashtag(infos, base, maj, nb);
	if (infos->options->opt_minus == 0 && infos->options->opt_zero == 1)
		insert_field(infos);
	infos->buf_index = infos->total_ret;
	return (0);
}
