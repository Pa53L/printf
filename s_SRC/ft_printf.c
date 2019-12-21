/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/21 21:26:17 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

int		ft_printf(const char *format, ...)
{
	va_list ap; /* объявляем указатель на безымянные аргументы */
	size_t count; /* для подсчета количества выведенных символов */
	int ival; /* for INT and CHAR */
	char *p; /* указатель на format */
	st_format spec[1]; /* новая структура */
	//Format_Type type;

	count = 0;
	va_start(ap, format); /* устанавливаем ap на 1-й аргумент без имени */
	p = (char *)format;
	while (*p)
	{
		ft_clean_struct(&spec[0]);
		if (*p != '%')
		{
			write(1, p, 1);
			count++;
		}
		if (*p == '%')
		{
			p++;
			p = ft_record_struct(&spec[0], p);
		}
		if(spec->type)
			count += ft_output(&spec[0], ap);
		p++;
	}
	va_end(ap);
	return (count);
}
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

