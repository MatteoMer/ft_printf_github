/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer_conv.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 20:39:37 by mmervoye          #+#    #+#             */
/*   Updated: 2018/09/27 21:49:34 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				pf_conv_integer(t_options *opt, t_infos *infos, char *buffer)
{
	conv_pf_numeric(opt, infos, buffer, 10);
	return (0);
}

int				pf_conv_hexa(t_options *opt, t_infos *infos, char *buffer)
{
	opt->opt_space = 0;
	conv_pf_numeric(opt, infos, buffer, 16);
	return (0);
}