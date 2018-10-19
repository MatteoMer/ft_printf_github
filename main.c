/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:20:22 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/19 13:34:20 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <locale.h>
# include <limits.h>

int					main(int argc, char **argv)
{
	int			ret1;
	int			ret2;
	char		str = "coucou";
	
	//ft_printf("%.0p, %.p\n", str, str);
	setlocale(LC_ALL, "");
	ft_printf("%C\n", L"😃");
	return (0);
}
