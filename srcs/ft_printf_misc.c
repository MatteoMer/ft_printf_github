/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:23:31 by mmervoye          #+#    #+#             */
/*   Updated: 2018/09/27 19:52:20 by mmervoye         ###   ########.fr       */
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
	if (opt->opt_zero == 1 && opt->opt_minus == 0)
		return ('0');
	return (' ');
}
