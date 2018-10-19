/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_launch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:47:49 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/17 16:51:53 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					launch_conv(t_infos *infos)
{
	t_options	options;

	infos->options = &options;
	init_opt(&options);
	get_options(infos);
	do_conv(infos);
	return (0);
}
