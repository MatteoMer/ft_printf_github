/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_insert_unicode_char.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:24:11 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/19 14:06:57 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				insert_unicode_char(t_infos *infos, wchar_t c)
{
	uintmax_t		n;

	n = ft_numlen_base(c, 2);
	(void)infos;
	printf("%#lx-%#lx-%#lx-%#lx\n", 240 + n & PRINTF_WC_MASK_4, 128 + n & PRINTF_WC_MASK_2, 128 + n & PRINTF_WC_MASK_2, n & PRINTF_WC_MASK_1);
	return (0);
}
