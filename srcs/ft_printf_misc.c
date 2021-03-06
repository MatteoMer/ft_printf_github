/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:42:40 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/22 18:23:42 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t				get_good_cast(t_infos *infos)
{
	char		*flags_l;

	flags_l = (char *)infos->options->l_flags;
	if (flags_l[2] != 0)
		return (va_arg(*(infos->ap), uintmax_t));
	else if (flags_l[0] == 'l' && flags_l[1] == 0)
		return (va_arg(*(infos->ap), long));
	else if (flags_l[0] == 'l' && flags_l[1] == 'l')
		return (va_arg(*(infos->ap), long long));
	else if (flags_l[0] == 'h' && flags_l[1] == 'h')
		return ((char)va_arg(*(infos->ap), int));
	else if (flags_l[0] == 'h' && flags_l[1] == 0)
		return ((short)va_arg(*(infos->ap), int));
	else if (flags_l[0] == 'z' && flags_l[1] == 0)
		return (va_arg(*(infos->ap), ssize_t));
	else if (flags_l[0] == 'j' && flags_l[1] == 0)
		return (va_arg(*(infos->ap), intmax_t));
	else if (flags_l[0] == 'z' && flags_l[1] != 0)
		return (va_arg(*(infos->ap), uintmax_t));
	else if (flags_l[0] == 'j' && flags_l[1] != 0)
		return (va_arg(*(infos->ap), uintmax_t));
	else
		return (va_arg(*(infos->ap), int));
}

uintmax_t				get_good_ucast(t_infos *infos)
{
	char		*flags_l;

	flags_l = (char *)infos->options->l_flags;
	if (flags_l[2] != 0)
		return (va_arg(*(infos->ap), uintmax_t));
	else if (flags_l[0] == 'l' && flags_l[1] == 0)
		return (va_arg(*(infos->ap), unsigned long));
	else if (flags_l[0] == 'l' && flags_l[1] == 'l')
		return (va_arg(*(infos->ap), unsigned long long));
	else if (flags_l[0] == 'h' && flags_l[1] == 'h')
		return ((unsigned char)va_arg(*(infos->ap), unsigned int));
	else if (flags_l[0] == 'h' && flags_l[1] == 0)
		return ((unsigned short)va_arg(*(infos->ap), unsigned int));
	else if (flags_l[0] == 'z' && flags_l[1] == 0)
		return (va_arg(*(infos->ap), size_t));
	else if (flags_l[0] == 'j' && flags_l[1] == 0)
		return (va_arg(*(infos->ap), uintmax_t));
	else if (flags_l[0] == 'z' && flags_l[1] != 0)
		return (va_arg(*(infos->ap), uintmax_t));
	else if (flags_l[0] == 'j' && flags_l[1] != 0)
		return (va_arg(*(infos->ap), uintmax_t));
	else
		return (va_arg(*(infos->ap), unsigned int));
}

int						insert_field(t_infos *infos)
{
	int			i;

	i = 0;
	while (i < infos->options->field_width)
	{
		if (infos->options->opt_minus == 1 || infos->options->precision > 0)
			infos->buffer[infos->buf_index + i] = ' ';
		else
			infos->buffer[infos->buf_index + i] = infos->\
options->opt_zero == 1 ? '0' : ' ';
		i++;
		infos->total_ret++;
	}
	infos->buf_index = infos->total_ret;
	infos->options->field_width = 0;
	return (0);
}

int						insert_wchar(t_infos *infos, wchar_t c)
{
	infos->buffer[infos->buf_index] = c;
	infos->buf_index++;
	infos->total_ret++;
	return (0);
}

int						ft_wstrlen(wchar_t *wstr)
{
	int				len;
	unsigned int	tmp;

	len = 0;
	while (*wstr)
	{
		tmp = ft_numlen_base(*wstr++, 2);
		if (tmp < 8)
			len += 1;
		else if (tmp < 12)
			len += 2;
		else if (tmp < 17)
			len += 3;
		else
			len += 4;
	}
	return (len);
}
