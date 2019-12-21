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

size_t	out_str(st_format *spec, char *str)
{
	size_t len;
	size_t tmp_len;

	if (!str)
		str = NULL_STRING;
	len = ft_strlen(str);
	if (spec->accur >= 0)
		if (spec->accur < len)
			len = spec->accur;
	if (spec->width)
	{
		if (spec->width > len)
			spec->width = spec->width - len;
		else
			spec->width = 0;
	}
	tmp_len = spec->width;
	if (spec->minus == 0)
	{
		while (spec->width--)
			write(1, " ", 1);
		write(1, str, len);
	}
	else if (spec->minus == 1)
	{
		write(1, str, len);
		while (spec->width--)
			write(1, " ", 1);
	}
	return (len + tmp_len);
}
