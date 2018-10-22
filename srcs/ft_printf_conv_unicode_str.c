/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_unicode_str.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:47:54 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/22 16:16:03 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					conv_unicode_str(t_infos *infos)
{
	wchar_t		*str;

	str = va_arg(*(infos->ap), wchar_t *);
	if (!str)
		str = L"(null)";
	insert_unicode_str(infos, str);
	infos->index++;
	return (0);
}
