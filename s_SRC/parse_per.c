/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:31:23 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:56:32 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

int		parse_per(st_format *spec, va_list vl)
{
	int		strlen;
	char	*str;
	int		i;

	str = NULL;
	strlen = spec->width;
	if (strlen > 1)
		str = record_per(spec, strlen);
	else
	{
		write(1, "%", 1);
		return (1);
	}
	write(1, str, strlen);
	free(str);
	return (strlen);
}
