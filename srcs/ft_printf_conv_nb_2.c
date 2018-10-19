/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_nb_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:38:56 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/19 12:36:50 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					conv_binary_min(t_infos *infos)
{
	uintmax_t		tmp;

	tmp = get_good_ucast(infos);
	insert_nb(tmp, infos, 2, 0);
	infos->buf_index = ft_strlen(infos->buffer);
	infos->index++;
	return (0);
}

int					conv_binary_maj(t_infos *infos)
{
	uintmax_t		tmp;

	tmp = get_good_ucast(infos);
	insert_nb(tmp, infos, 2, 1);
	infos->buf_index = ft_strlen(infos->buffer);
	infos->index++;
	return (0);
}

int					conv_decimal_upper(t_infos *infos)
{
	long int		tmp;

	tmp = va_arg(*(infos->ap), long int);
	insert_nb(tmp, infos, 10, 0);
	infos->buf_index = ft_strlen(infos->buffer);
	infos->index++;
	return (0);
}

int					conv_udecimal(t_infos *infos)
{
	uintmax_t		tmp;

	infos->is_unsigned = 1;
	tmp = get_good_ucast(infos);
	insert_nb(tmp, infos, 10, 0);
	infos->buf_index = ft_strlen(infos->buffer);
	infos->index++;
	return (0);
}

int					conv_udecimal_upper(t_infos *infos)
{
	uintmax_t		tmp;

	infos->is_unsigned = 1;
	tmp = va_arg(*(infos->ap), unsigned long int);
	insert_nb(tmp, infos, 10, 0);
	infos->buf_index = ft_strlen(infos->buffer);
	infos->index++;
	return (0);
}
