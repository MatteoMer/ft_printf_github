/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:44:44 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/16 14:06:10 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					conv_decimal(t_infos *infos)
{
	uintmax_t		tmp;

	tmp = get_good_cast(infos);
	insert_nb(tmp, infos, 10, 0);
	infos->buf_index = ft_strlen(infos->buffer);
	infos->index++;
	return (0);
}

int					conv_hexa_min(t_infos *infos)
{
	uintmax_t		tmp;

	tmp = get_good_ucast(infos);
	insert_nb(tmp, infos, 16, 0);
	infos->buf_index = ft_strlen(infos->buffer);
	infos->index++;
	return (0);
}

int					conv_hexa_maj(t_infos *infos)
{
	uintmax_t		tmp;

	tmp = get_good_ucast(infos);
	insert_nb(tmp, infos, 16, 1);
	infos->buf_index = ft_strlen(infos->buffer);
	infos->index++;
	return (0);
}

int					conv_octal_min(t_infos *infos)
{
	uintmax_t		tmp;

	tmp = get_good_ucast(infos);
	insert_nb(tmp, infos, 8, 0);
	infos->buf_index = ft_strlen(infos->buffer);
	infos->index++;
	return (0);
}

int					conv_octal_maj(t_infos *infos)
{
	uintmax_t		tmp;

	tmp = get_good_ucast(infos);
	insert_nb(tmp, infos, 8, 1);
	infos->buf_index = ft_strlen(infos->buffer);
	infos->index++;
	return (0);
}
