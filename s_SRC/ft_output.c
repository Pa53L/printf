/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:53:31 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/22 12:43:15 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

size_t	ft_output(st_format *spec, va_list ap)
{
	char *str; /* для STRING */
	int ival; /* для CHAR и INT */
	size_t length;
	size_t temp_length;

	temp_length = 0;
	length = 0;
	/*
	printf("----------------------\n");
	printf("minus: %d\n", spec[0].minus);
	printf("plus: %d\n", spec[0].plus);
	printf("space: %d\n", spec[0].space);
	printf("sharp: %d\n", spec[0].sharp);
	printf("zero: %d\n", spec[0].zero);
	printf("width: %d\n", spec[0].width);
	printf("accuracy: %d\n", spec[0].accuracy);
	printf("size: %d\n", spec[0].size);
	printf("type: %c\n", spec[0].type);
	printf("----------------------\n");
	*/
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
		length = out_di(&spec[0], ap);
	}
	if (spec->type == 'p' || spec->type == 'x' || spec->type == 'X' || spec->type == 'o')
	{
		length = ft_output2(spec, ap);
	}
	return (length + temp_length);
}
