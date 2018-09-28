/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:50:44 by mmervoye          #+#    #+#             */
/*   Updated: 2018/09/27 21:32:00 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				do_printf(t_infos *infos, const char *format)
{
	char			buffer[BUF_SIZE + 1];

	infos->index = 0;
	infos->buf_index = 0;
	ft_bzero((void *)buffer, BUF_SIZE + 1);
	while (infos->index < BUF_SIZE && format[infos->index])
	{
		if (format[infos->index] != '%')
		{
			buffer[infos->buf_index] = format[infos->index];
			infos->index++;
			infos->buf_index++;
		}
		else
			infos->index += handler_printf(infos, format, (char *)buffer);
	}
	write(1, buffer, ft_strlen(buffer));
	return (infos->index);
}

int						ft_printf(const char *format, ...)
{
	int				tmp_ret;
	t_infos			infos;
	va_list			ap;

	va_start(ap, format);
	tmp_ret = 0;
	init_infos(&infos, &ap);
	while (*format)
		format += do_printf(&infos, format);
	return (infos.ret);
}
