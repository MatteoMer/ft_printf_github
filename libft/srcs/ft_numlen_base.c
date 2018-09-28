/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:07:27 by mmervoye          #+#    #+#             */
/*   Updated: 2018/09/27 21:10:45 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_numlen_base(int nb, int base)
{
	int			i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}