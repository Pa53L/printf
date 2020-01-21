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

void	ft_itoabasex(uint64_t i, char *s, int base, char type, int len)
{
	while (i > 0)
	{
		if (i < base)
		{
			(type != 'X') ? (s[len] = IT[i]) : (s[len] = ITX[i]);
			return ;
		}
		else
			(type != 'X') ? (s[len] = IT[i % base]) : (s[len] = ITX[i % base]);
		i = i / base;
		len--;
	}
	return ;
}
