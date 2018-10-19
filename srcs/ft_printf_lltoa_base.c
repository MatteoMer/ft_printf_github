/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lltoa_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:07:35 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/19 12:43:45 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lltoa_usefull(int *neg, uintmax_t *nb, int *len)
{
	*neg = 1;
	*nb *= -1;
	*len += 1;
}

void		fpf_llota_base(uintmax_t nb, t_infos *infos, int base, int maj)
{
	char		base_tab[17];
	int			len;
	int			i;
	int			neg;

	neg = 0;
	len = 0;
	ft_bzero(infos->tmp_str, 128);
	i = 0;
	ft_strcpy(base_tab, "0123456789abcdef");
	if (maj)
		ft_strcpy(base_tab, "0123456789ABCDEF");
	if (!infos->is_unsigned && base == 10 && (intmax_t)nb < 0)
		lltoa_usefull(&neg, &nb, &len);
	len += ft_numlen_base(nb, base);
	while (i < len)
	{
		infos->tmp_str[len - i - 1] = base_tab[nb % base];
		i++;
		nb /= base;
	}
	if (neg)
		infos->tmp_str[0] = '-';
	infos->tmp_str[i] = 0;
}
