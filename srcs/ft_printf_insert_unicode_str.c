/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_insert_unicode_str.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:16:46 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/22 18:22:14 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			insert_single_char_wstr(t_infos *infos, wchar_t c, int len)
{
	if (len == 1 && __mb_cur_max >= 1)
		insert_wchar(infos, 0 + (PRINTF_WC_MASK_0 & c));
	else if (len == 2 && __mb_cur_max >= 2)
	{
		insert_wchar(infos, 192 + ((PRINTF_WC_MASK_2 & c) >> 6));
		insert_wchar(infos, 128 + (PRINTF_WC_MASK_1 & c));
	}
	else if (len == 3 && __mb_cur_max >= 3)
	{
		insert_wchar(infos, 224 + ((PRINTF_WC_MASK_4 & c) >> 12));
		insert_wchar(infos, 128 + ((PRINTF_WC_MASK_3 & c) >> 6));
		insert_wchar(infos, 128 + (PRINTF_WC_MASK_1 & c));
	}
	else if (__mb_cur_max == 4)
	{
		insert_wchar(infos, 240 + ((PRINTF_WC_MASK_6 & c) >> 18));
		insert_wchar(infos, 128 + ((PRINTF_WC_MASK_5 & c) >> 12));
		insert_wchar(infos, 128 + ((PRINTF_WC_MASK_3 & c) >> 6));
		insert_wchar(infos, 128 + (PRINTF_WC_MASK_1 & c));
	}
	else
		infos->total_ret = -1;
	return (0);
}

static int			insert_wstr(t_infos *infos, wchar_t *str, int len)
{
	int			tmp_len;

	while (len)
	{
		tmp_len = ft_wcharlen(*str);
		insert_single_char_wstr(infos, *str, tmp_len);
		len -= tmp_len;
		str++;
	}
	return (0);
}

int					insert_unicode_str(t_infos *infos, wchar_t *str)
{
	int				len;
	int				tmp_len;

	len = ft_wstrlen(str);
	if (infos->options->precision >= 0 && infos->options->precision < len)
	{
		len = 0;
		while ((len + (tmp_len = ft_wcharlen(str[0]))) <= infos->\
options->precision)
			len += tmp_len;
	}
	infos->options->field_width -= len;
	if (infos->options->field_width > 0 && infos->options->opt_minus == 0)
		insert_field(infos);
	insert_wstr(infos, str, len);
	if (infos->options->field_width > 0 && infos->options->opt_minus == 1)
		insert_field(infos);
	return (0);
}
