/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:53:31 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/19 21:17:56 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t	ft_output(st_format_spec *spec, va_list ap)
{
	char *str; /* для STRING */
	int ival; /* для CHAR и INT */
	size_t length;
	size_t temp_length;

	temp_length = 0;
	length = 0;
	if (spec->type == 's')
	{
		str = va_arg(ap, char *);
		length = out_str(&spec[0], str);
	}
	if (spec->type == 'c')
	{
		ival = va_arg(ap, int);
		length = out_chr(&spec[0], ival);
	}
	if (spec->type == 'd' || spec->type == 'i')
	{
		ival = va_arg(ap, int);
		length = out_di(&spec[0], ival);
	}
	return (length + temp_length);
}
