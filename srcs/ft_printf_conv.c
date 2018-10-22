/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:05:51 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/22 18:21:40 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			init_dispatch_2(t_dispatch *dispatch)
{
	dispatch[10].character = 'u';
	dispatch[10].ptr = conv_udecimal;
	dispatch[11].character = 'U';
	dispatch[11].ptr = conv_udecimal_upper;
	dispatch[12].character = 'c';
	dispatch[12].ptr = conv_character;
	dispatch[13].character = 's';
	dispatch[13].ptr = conv_strings;
	dispatch[14].character = 'C';
	dispatch[14].ptr = conv_unicode_character;
	dispatch[15].character = 'S';
	dispatch[15].ptr = conv_unicode_str;
	return (0);
}

static int			init_dispatch(t_dispatch *dispatch)
{
	dispatch[0].character = 'd';
	dispatch[0].ptr = conv_decimal;
	dispatch[1].character = 'i';
	dispatch[1].ptr = conv_decimal;
	dispatch[2].character = 'x';
	dispatch[2].ptr = conv_hexa_min;
	dispatch[3].character = 'b';
	dispatch[3].ptr = conv_binary_min;
	dispatch[4].character = 'X';
	dispatch[4].ptr = conv_hexa_maj;
	dispatch[5].character = 'B';
	dispatch[5].ptr = conv_binary_maj;
	dispatch[6].character = 'o';
	dispatch[6].ptr = conv_octal_min;
	dispatch[7].character = 'O';
	dispatch[7].ptr = conv_octal_maj;
	dispatch[8].character = 'D';
	dispatch[8].ptr = conv_decimal_upper;
	dispatch[9].character = 'p';
	dispatch[9].ptr = conv_pointer;
	init_dispatch_2(dispatch);
	return (0);
}

int					do_conv(t_infos *infos)
{
	t_dispatch		dispatch[16];
	int				i;
	int				ret;

	ret = 0;
	i = -1;
	init_dispatch((t_dispatch *)&dispatch);
	infos->is_unsigned = 0;
	while (++i < 16)
		if (dispatch[i].character == infos->format[infos->index])
			return (dispatch[i].ptr(infos));
	if (infos->format[infos->index] != 0)
	{
		ret = insert_char(infos->format[infos->index], infos);
		infos->index++;
	}
	return (ret);
}
