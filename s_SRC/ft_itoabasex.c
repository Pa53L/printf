/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabasex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:53:11 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:54:52 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

void	ft_itoabasex(unsigned long long ival, char *str, int base, char type, int len)
{
	while (ival > 0)
	{
		if (ival < base)
		{
			if (type != 'X')
				str[len] = ITOA[ival];
			else
				str[len] = ITOAX[ival];
			return ;
		}
		else
		{
			if (type != 'X')
				str[len] = ITOA[ival % base];
			else
				str[len] = ITOAX[ival % base];
		}
		ival = ival / base;
		len--;
	}
	return ;
}
