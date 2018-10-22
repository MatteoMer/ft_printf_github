/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_misc_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:20:22 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/22 16:21:33 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_wcharlen(wchar_t c)
{
	unsigned int	tmp;

	tmp = ft_numlen_base(c, 2);
	if (tmp < 8)
		return (1);
	else if (tmp < 12)
		return (2);
	else if (tmp < 17)
		return (3);
	else
		return (4);
}
