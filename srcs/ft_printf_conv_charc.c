/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_charc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:37:27 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/16 16:23:31 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					conv_character(t_infos *infos)
{
	char		c;

	if (!(infos->options->l_flags[0] == 'l' && infos->options->l_flags[1] == 0))
	{
		c = (unsigned char)va_arg(*(infos->ap), int);
		infos->index++;
		return (insert_char(c, infos));
	}
	infos->index++;
	return (0);
}

int					conv_strings(t_infos *infos)
{
	char		*s;

	if (!(infos->options->l_flags[0] == 'l' && infos->options->l_flags[1] == 0))
	{
		s = va_arg(*(infos->ap), char *);
		infos->index++;
		return (insert_string(s, infos));
	}
	infos->index++;
	return (0);
}
