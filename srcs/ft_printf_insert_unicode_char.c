/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_insert_unicode_char.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:24:11 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/22 18:21:56 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_wchar_1oct(t_infos *infos, wchar_t c)
{
	infos->options->field_width -= 1;
	if (infos->options->opt_minus == 0)
		insert_field(infos);
	insert_wchar(infos, 0 + (PRINTF_WC_MASK_0 & c));
	if (infos->options->opt_minus == 1)
		insert_field(infos);
}

static void		put_wchar_2oct(t_infos *infos, wchar_t c)
{
	infos->options->field_width -= 2;
	if (infos->options->opt_minus == 0)
		insert_field(infos);
	insert_wchar(infos, 192 + ((PRINTF_WC_MASK_2 & c) >> 6));
	insert_wchar(infos, 128 + (PRINTF_WC_MASK_1 & c));
	if (infos->options->opt_minus == 1)
		insert_field(infos);
}

static void		put_wchar_3oct(t_infos *infos, wchar_t c)
{
	infos->options->field_width -= 3;
	if (infos->options->opt_minus == 0)
		insert_field(infos);
	insert_wchar(infos, 224 + ((PRINTF_WC_MASK_4 & c) >> 12));
	insert_wchar(infos, 128 + ((PRINTF_WC_MASK_3 & c) >> 6));
	insert_wchar(infos, 128 + (PRINTF_WC_MASK_1 & c));
	if (infos->options->opt_minus == 1)
		insert_field(infos);
}

static void		put_wchar_4oct(t_infos *infos, wchar_t c)
{
	infos->options->field_width -= 4;
	if (infos->options->opt_minus == 0)
		insert_field(infos);
	insert_wchar(infos, 240 + ((PRINTF_WC_MASK_6 & c) >> 18));
	insert_wchar(infos, 128 + ((PRINTF_WC_MASK_5 & c) >> 12));
	insert_wchar(infos, 128 + ((PRINTF_WC_MASK_3 & c) >> 6));
	insert_wchar(infos, 128 + (PRINTF_WC_MASK_1 & c));
	if (infos->options->opt_minus == 1)
		insert_field(infos);
}

int				insert_unicode_char(t_infos *infos, wchar_t c)
{
	uintmax_t		len;

	len = ft_numlen_base(c, 2);
	if (len < 8 && __mb_cur_max >= 1)
		put_wchar_1oct(infos, c);
	else if (len < 12 && __mb_cur_max >= 2)
		put_wchar_2oct(infos, c);
	else if (len < 17 && __mb_cur_max >= 3)
		put_wchar_3oct(infos, c);
	else if (__mb_cur_max == 4)
		put_wchar_4oct(infos, c);
	else
		infos->total_ret = -1;
	return (0);
}
