/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_unicode_char.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:21:27 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/19 13:23:59 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				conv_unicode_character(t_infos *infos)
{
	wchar_t		tmp;

	tmp = va_arg(*(infos->ap), wchar_t);
	insert_unicode_char(infos, tmp);
	return (0);
}
