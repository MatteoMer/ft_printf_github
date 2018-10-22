/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_insert_strings.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:44:51 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/22 17:43:11 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					insert_char(char c, t_infos *infos)
{
	infos->options->field_width--;
	infos->buf_index = infos->total_ret;
	if (infos->options->field_width > 0 && infos->options->opt_minus == 0)
		insert_field(infos);
	infos->buffer[infos->buf_index] = c;
	infos->total_ret++;
	infos->buf_index++;
	if (infos->options->field_width > 0 && infos->options->opt_minus == 1)
		insert_field(infos);
	return (0);
}

int					insert_string(char *s, t_infos *infos)
{
	int			len;

	if (!s)
		s = "(null)";
	len = infos->options->precision == -1 ? ft_strlen(s) : infos->options->\
precision;
	if (infos->options->precision > (int)ft_strlen(s))
		len = ft_strlen(s);
	infos->options->field_width -= len;
	if (infos->options->field_width > 0 && infos->options->opt_minus == 0)
		insert_field(infos);
	while (len)
	{
		infos->buffer[infos->buf_index] = *s;
		len--;
		s++;
		infos->buf_index++;
		infos->total_ret++;
	}
	infos->buf_index = infos->total_ret;
	if (infos->options->field_width > 0 && infos->options->opt_minus == 1)
		insert_field(infos);
	return (0);
}
