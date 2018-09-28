/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:52:50 by mmervoye          #+#    #+#             */
/*   Updated: 2018/09/28 14:48:35 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		insert_nb_buffer
(t_options *opt, char *buffer, int tab[2], t_infos *infos)
{
	char	nb_tab[17];
	int		len;
	int		i;

	i = 0;
	ft_strcpy(nb_tab, "0123456789abcdef");
	len = ft_numlen_base(tab[0], tab[1]) - 1;
	while (tab[0])
	{
		buffer[infos->buf_index + (len - i)] = nb_tab[tab[0] % tab[1]];
		i++;
		tab[0] /= tab[1];
	}
	return (len + 1);
}

int				conv_pf_numeric
(t_options *opt, t_infos *infos, char *buffer, int base)
{
	int		len;
	int		nb;
	int		tab[2];

	tab[0] = va_arg(*(infos->ap), int);
	tab[1] = base;
	len = ft_numlen_base(tab[0], tab[1]);
	if (opt->opt_space == 1)
	{
		buffer[infos->buf_index] = ' ';
		opt->field_width--;
		infos->buf_index++;
	}
	opt->field_width -= opt->precision - len > 0 ? opt->precision - len : 0;
	while (opt->opt_minus == 0 && len < opt->field_width)
	{
		buffer[infos->buf_index] = get_pf_field_char(opt);
		opt->field_width--;
		infos->buf_index++;
	}
	pf_insert_precision(opt->precision, len, infos, buffer);
	infos->buf_index += insert_nb_buffer(opt, buffer, tab, infos);
	return (0);
}
