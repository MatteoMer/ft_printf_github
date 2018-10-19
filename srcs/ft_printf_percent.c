/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:08:40 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/19 12:47:05 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_attr(char c)
{
	if (c == '#' || c == '0' || c == ' ' || c == '-' || c == '+')
		return (1);
	return (0);
}

void			init_opt(t_options *options)
{
	options->opt_minus = 0;
	options->opt_plus = 0;
	options->opt_space = 0;
	options->opt_zero = 0;
	options->opt_hashtag = 0;
	options->field_width = 0;
	options->precision = -1;
	ft_bzero(options->l_flags, 3);
}

static int		get_nb(t_infos *infos)
{
	int			nb;

	nb = 0;
	while (ft_isdigit(infos->format[infos->index]))
	{
		nb *= 10;
		nb += infos->format[infos->index] - '0';
		infos->index++;
	}
	return (nb);
}

static void		get_length_flag(t_infos *infos, t_options *opt, char *format)
{
	char		c;
	int			i;

	i = 0;
	opt->l_flags[0] = 0;
	opt->l_flags[1] = 0;
	opt->l_flags[2] = 0;
	while (format[infos->index])
	{
		c = format[infos->index];
		if (!(c == 'h' || c == 'l' || c == 'j' || c == 'z'))
			break ;
		else if (i < 3)
		{
			opt->l_flags[i] = c;
			i++;
		}
		infos->index++;
	}
}

int				get_options(t_infos *infos)
{
	infos->index += 1;
	while (is_attr(infos->format[infos->index]) && infos->format[infos->index])
	{
		if (infos->format[infos->index] == '#')
			infos->options->opt_hashtag = 1;
		if (infos->format[infos->index] == '0')
			infos->options->opt_zero = 1;
		if (infos->format[infos->index] == ' ')
			infos->options->opt_space = 1;
		if (infos->format[infos->index] == '-')
			infos->options->opt_minus = 1;
		if (infos->format[infos->index] == '+')
			infos->options->opt_plus = 1;
		infos->index++;
	}
	infos->options->field_width = get_nb(infos);
	if (infos->format[infos->index] == '.')
	{
		infos->index++;
		infos->options->precision = get_nb(infos);
	}
	get_length_flag(infos, infos->options, infos->format);
	return (0);
}
