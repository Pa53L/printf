/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:53:58 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:55:18 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t		parse_chr(st_format *spec, va_list vl)
{
	uint32_t		i;
	char			ch;
	char			*str;

	ch = (char)va_arg(vl, int);
	if (spec->width > 1)
	{
		if (!(str = (char*)malloc(sizeof(char) * (spec->width))))
			return (0);
	}
	else
	{
		write(1, &ch, 1);
		return (1);
	}

	str[spec->width - 1] = '\0';
	i = spec->width - 1;
	if (spec->minus == 1)
	{
		while (i > 0)
			str[i--] = ' ';
	}
	str[i--] = ch;
	if (spec->minus == 0)
	{
		while (i > 0)
			str[i--] = ' ';
		str[i] = ' ';
	}

	/*
	str[--spec->width] = '\0';
	i = spec->width;
	if (spec->minus == 1)
		while (i > 0)
			str[i--] = ' ';
	str[i--] = ch;
	if (spec->minus == 0)
	{
		while (i > 0)
			str[i--] = ' ';
		str[i] = ' ';
	}
	*/
	write(1, str, spec->width);
	free(str);
	return (spec->width);
}
