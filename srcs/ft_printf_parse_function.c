/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_function.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 20:11:49 by mmervoye          #+#    #+#             */
/*   Updated: 2018/09/28 14:17:40 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				get_opt(t_infos *infos, t_options *opt, char *format)
{
	int				i;

	i = infos->index + 1;
	while (1)
	{
		if (format[i] == '+')
			opt->opt_plus = 1;
		else if (format[i] == '-')
			opt->opt_minus = 1;
		else if (format[i] == ' ')
			opt->opt_space = 1;
		else if (format[i] == '0')
			opt->opt_zero = 1;
		else if (format[i] == '#')
			opt->opt_hashtag = 1;
		else
			break ;
		i++;
	}
	infos->index = i;
}

void				get_field(t_infos *infos, t_options *opt, char *format)
{
	int			nb;
	int			i;

	nb = 0;
	i = infos->index;
	while (ft_isdigit(format[i]))
	{
		if (nb)
			nb *= 10;
		nb += format[i] - 48;
		i++;
	}
	opt->field_width = nb;
	infos->index = i;
}

void				get_precision(t_infos *infos, t_options *opt, char *format)
{
	int			i;
	int			nb;

	if (format[infos->index] != '.')
		return ;
	nb = 0;
	i = infos->index + 1;
	while (ft_isdigit(format[i]))
	{
		if (nb)
			nb *= 10;
		nb += format[i] - 48;
		i++;
	}
	opt->precision = nb;
	infos->index = i;

}

void				get_length_modifier(t_infos *infos, t_options *opt, char *format)
{
	infos->index -= 1;
	while (format[++(infos->index)])
	{
		if (format[infos->index] == 'l' && format[infos->index + 1] != 'l')
			opt->opt_l = 1;
		else if (format[infos->index] == 'l' && format[infos->index + 1] == 'l')
		{
			opt->opt_ll = 1;
			infos->index++;
		}
		else if (format[infos->index] == 'h' && format[infos->index + 1] != 'h')
		{
			opt->opt_h = 1;
			infos->index++;
		}
		else if (format[infos->index] == 'h' && format[infos->index + 1] == 'h')
			opt->opt_hh = 1;
		else if (format[infos->index] == 'j')
			opt->opt_j = 1;
		else if (format[infos->index] == 'z')
			opt->opt_z = 1;
		else
			break ;
	}
}
