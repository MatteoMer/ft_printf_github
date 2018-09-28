/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:47:53 by mmervoye          #+#    #+#             */
/*   Updated: 2018/09/27 21:24:14 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# define BUF_SIZE 2048


typedef struct			s_infos
{
	int					ret;
	va_list				*ap;
	int					index;
	int					buf_index;
	char				*format;
}						t_infos;

typedef struct			s_options
{
	int					opt_minus;
	int					opt_plus;
	int					opt_space;
	int					opt_zero;
	int					opt_hashtag;
	int					field_width;
	int					precision;
}						t_options;

typedef struct			s_dispatch
{
	char				character;
	int					(*ptr)(t_options *opt, t_infos *infos, char *buffer);
}						t_dispatch;


int			ft_printf(const char *format, ...);
void		init_infos(t_infos *infos, va_list *ap);
int			handler_printf(t_infos *infos, const char *format, char *buffer);
char		get_pf_field_char(t_options *opt);
void		get_opt(t_infos *infos, t_options *opt, char *format);
void		get_field(t_infos *infos, t_options *opt, char *format);
void		get_precision(t_infos *infos, t_options *opt, char *format);
int			pf_conv_integer(t_options *opt, t_infos *infos, char *buffer);
int			pf_conv_hexa(t_options *opt, t_infos *infos, char *buffer);
void		printf_dispatch
(t_infos *infos, t_options *opt, char *format, char *buffer);
int			conv_pf_numeric
(t_options *opt, t_infos *infos, char *buffer, int base);

#endif
