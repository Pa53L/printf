/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:53:31 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:57:45 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

int	parse_output(st_format *spec, va_list vl, va_list fst_vl)
{
	int			i;
	uint64_t	cnt;

	i = 0;
	cnt = 0;
	if (spec->dollar > 1)
		parse_bdollar(spec->dollar, vl);
	while (i < BLYAT_SIZE)
	{
		if (spec->type == TYPES[i])
		{
			cnt = BLYAT[i](spec, vl);
			break ;
		}
		i++;
	}
	if (i == 5)
		cnt = BLYAT[i](spec, vl);
	(spec->dollar == 0) ? va_copy(fst_vl, vl) : va_copy(vl, fst_vl);
	ft_clean_struct(spec);
	return (cnt);
}
