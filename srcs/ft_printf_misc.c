/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:23:31 by mmervoye          #+#    #+#             */
/*   Updated: 2018/09/28 15:07:12 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				init_infos(t_infos *infos, va_list *ap)
{
	infos->ap = ap;
	infos->ret = 0;
}

char				get_pf_field_char(t_options *opt)
{
	if (opt->opt_zero == 1 && opt->opt_minus == 0 && opt->precision == -1)
		return ('0');
	return (' ');
}

int					pf_insert_precision
(int precision, int len, t_infos *infos, char *buffer)
{
	int				ret;

	ret = precision - len;
	while (precision > len)
	{
		buffer[infos->buf_index] = '0';
		infos->buf_index++;
		precision--;
	}
	return (ret);
}
