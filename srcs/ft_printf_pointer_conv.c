/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer_conv.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:33:08 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/19 12:46:38 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					conv_pointer(t_infos *infos)
{
	unsigned long	tmp;

	tmp = va_arg(*(infos->ap), unsigned long);
	if (tmp)
	{
		infos->options->opt_hashtag = 1;
		insert_nb(tmp, infos, 16, 0);
		infos->buf_index = infos->total_ret;
	}
	else
		insert_string("0x0", infos);
	infos->index++;
	return (0);
}
