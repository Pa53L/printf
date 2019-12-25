/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:31:23 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/21 18:38:24 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t	out_per(st_format *spec)
{
	char *str_width;

	str_width = NULL;
	if (spec->width)
	{
		if (spec->width > 1)
			spec->width--;
		else
			spec->width = 0;
	}
	if (spec->width > 1)
		str_width = ft_strnew_width(&spec[0]);
	if (spec->width && spec->minus == 0)
		write(1, str_width, spec->width);
	write(1, "%", 1);
	if (spec->width && spec->minus == 1)
		write(1, str_width, spec->width);
	if (str_width)
		free(str_width);
	return (spec->width + 1);
}