/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:52:09 by mmervoye          #+#    #+#             */
/*   Updated: 2017/11/13 15:28:12 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}
