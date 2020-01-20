/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabasex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:53:11 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/20 23:46:36 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

void ft_itoabasex(unsigned long long value, char *str, uint8_t base, char type, int len)
{
	while (value > 0)
	{
		if (value < base)
		{
			if (type != 'X')
				str[len] = ITOA[value];
			else
				str[len] = ITOAX[value];
			return ;
		}
		else
		{
			if (type != 'X')
				str[len] = ITOA[value % base];
			else
				str[len] = ITOAX[value % base];
		}
		value = value / base;
		len--;
	}
	return ;
}
