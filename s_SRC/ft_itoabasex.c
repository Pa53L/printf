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

void	ft_itoabasex(st_format *spec, uint64_t i, char *s, int len)
{
	while (i > 0)
	{
		if (i < spec->base)
		{
			if (spec->type != 'X')
				(s[len] = IT[i]);
			else
				(s[len] = ITX[i]);
			return ;
		}
		else
		{
			if (spec->type != 'X')
				(s[len] = IT[i % spec->base]);
			else
				(s[len] = ITX[i % spec->base]);
		}
		i = i / spec->base;
		len--;
	}
	return ;
}
