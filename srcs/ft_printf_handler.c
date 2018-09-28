/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:22:54 by mmervoye          #+#    #+#             */
/*   Updated: 2018/09/28 14:57:08 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				init_opt(t_options *opt)
{
	opt->opt_hashtag = 0;
	opt->opt_minus = 0;
	opt->opt_plus = 0;
	opt->opt_space = 0;
	opt->opt_zero = 0;
	opt->field_width = 0;
	opt->precision = -1;
	opt->opt_l = 0;
	opt->opt_ll = 0;
	opt->opt_h = 0;
	opt->opt_hh = 0;
	opt->opt_j = 0;
	opt->opt_z = 0;
}

int				handler_printf(t_infos *infos, const char *format, char *buffer)
{
	t_options		opt;

	init_opt(&opt);
	get_opt(infos, &opt, (char *)format);
	get_field(infos, &opt, (char *)format);
	get_precision(infos, &opt, (char *)format);
	get_length_modifier(infos, &opt, (char *)format);
	printf_dispatch(infos, &opt, (char *)format, buffer);
	return (1);
}
