/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:16:08 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/22 17:11:16 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					handle_printf(t_infos *infos)
{
	while (infos->buf_index <= 2048 && infos->format[infos->index])
	{
		if (infos->format[infos->index] != '%')
		{
			infos->buffer[infos->buf_index] = infos->format[infos->index];
			infos->buf_index++;
			infos->index++;
			infos->total_ret++;
		}
		else
			launch_conv(infos);
	}
	write(1, infos->buffer, infos->total_ret);
	return (infos->total_ret);
}

int					ft_printf(const char *format, ...)
{
	va_list		ap;
	t_infos		infos;
	char		*buffer;
	int			ret;

	ret = 0;
	if ((buffer = ft_strnew(2048)) == NULL)
		return (-1);
	va_start(ap, format);
	infos.ap = &ap;
	infos.total_ret = 0;
	infos.index = 0;
	infos.buf_index = 0;
	infos.format = (char *)format;
	infos.buffer = buffer;
	handle_printf(&infos);
	ret = infos.total_ret;
	free(infos.buffer);
	va_end(ap);
	return (ret);
}
