/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 20:17:55 by mmervoye          #+#    #+#             */
/*   Updated: 2018/09/28 13:45:42 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				init_struct(t_dispatch *dispatch)
{
	dispatch[0].character = 'd';
	dispatch[0].ptr = &pf_conv_integer;
	dispatch[1].character = 'i';
	dispatch[1].ptr = &pf_conv_integer;
	dispatch[2].character = 'x';
	dispatch[2].ptr = &pf_conv_hexa;
	dispatch[3].character = 'b';
	dispatch[3].ptr = &pf_conv_binary;
}

void					printf_dispatch
(t_infos *infos, t_options *opt, char *format, char *buffer)
{
	t_dispatch			dispatch[4];
	int					i;

	i = 0;
	init_struct((t_dispatch *)&dispatch);
	while (i < 4)
	{
		if (dispatch[i].character == format[infos->index])
		{
			dispatch[i].ptr(opt, infos, buffer);
			return ;
		}
		i++;
	}
	ft_putstr_fd("ft_printf: No such conversion: `", 2);
	ft_putnbr_fd(format[infos->index], 2);
	ft_putendl_fd("'", 2);
}
