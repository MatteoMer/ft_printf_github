/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_insert_nb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:44:45 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/19 12:48:03 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** /!\ WARNING : Entering unstable code area /!\
*/

static int		insert_precision_nb(t_infos *infos)
{
	int			i;

	i = 0;
	infos->options->precision -= ft_strlen(infos->tmp_str);
	while (++i <= infos->options->precision)
	{
		infos->buffer[infos->buf_index] = '0';
		infos->buf_index++;
		infos->total_ret++;
	}
	infos->buf_index = infos->total_ret;
	return (0);
}

static int		start_insert_nb(uintmax_t nb, t_infos *infos, int base)
{
	infos->precision_zero = 0;
	if (infos->options->precision == -1)
	{
		infos->precision_zero = 1;
		infos->options->precision = 0;
	}
	if (infos->precision_zero == 0 && nb == 0)
	{
		if (base != 8 || (infos->options->opt_hashtag == 0))
		{
			infos->options->precision++;
			infos->options->field_width++;
		}
		else
			infos->precision_zero = 1;
	}
	return (0);
}

static int		mid_insert_nb(uintmax_t nb, t_infos *infos, int base, int maj)
{
	if (!infos->is_unsigned && base == 10 && (intmax_t)nb >= 0 && (infos->\
options->opt_space || infos->options->opt_plus))
		infos->options->field_width--;
	if (infos->tmp_str[0] == '-' && infos->options->\
precision > (int)ft_strlen(infos->tmp_str))
		infos->options->field_width--;
	if (infos->tmp_str[0] != '-' && infos->options->field_width > 0 && infos->\
options->opt_minus == 0 && infos->options->opt_space == 0 && infos->\
options->opt_plus == 0 && infos->options->opt_hashtag == 0)
		insert_field(infos);
	insert_flags(infos, base);
	insert_hashtag(infos, base, maj, nb);
	insert_precision_nb(infos);
	return (0);
}

int				insert_nb(uintmax_t nb, t_infos *infos, int base, int maj)
{
	start_insert_nb(nb, infos, base);
	fpf_llota_base(nb, infos, base, maj);
	infos->options->field_width -= (int)ft_strlen(infos->tmp_str) >= infos->\
options->precision ? ft_strlen(infos->\
tmp_str) : infos->options->precision;
	mid_insert_nb(nb, infos, base, maj);
	if (infos->precision_zero == 1 || nb != 0)
	{
		ft_strcat(infos->buffer + infos->buf_index, infos->tmp_str);
		infos->total_ret += ft_strlen(infos->tmp_str);
	}
	infos->buf_index = infos->total_ret;
	if (infos->options->field_width > 0 && infos->options->opt_minus == 1)
		insert_field(infos);
	infos->buf_index = infos->total_ret;
	return (0);
}
