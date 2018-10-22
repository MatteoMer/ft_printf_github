/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer_conv.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:33:08 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/22 18:22:35 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					conv_pointer(t_infos *infos)
{
	unsigned long	tmp;

	tmp = va_arg(*(infos->ap), unsigned long);
	if (!tmp)
	{
		infos->options->field_width -= infos->options->opt_minus == 0 ? 3 : 2;
		if (infos->options->field_width >= 0 && (infos->options->\
opt_minus == 0) && infos->options->opt_zero == 0)
			insert_field(infos);
		ft_strcat(infos->buffer, "0x");
		infos->buf_index += 2;
		infos->total_ret += 2;
		if (infos->options->opt_zero == 1)
			insert_field(infos);
	}
	infos->options->opt_hashtag = 1;
	insert_nb(tmp, infos, 16, 0);
	infos->buf_index = infos->total_ret;
	infos->index++;
	return (0);
}
