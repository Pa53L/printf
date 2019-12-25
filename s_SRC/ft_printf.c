/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/23 19:21:43 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

int		ft_printf(const char *format, ...)
{
	char *p;
	va_list ap;
	size_t count;
	st_format spec[1];

	count = 0;
	va_start(ap, format); /* устанавливаем ap на 1-й аргумент без имени */
	p = (char *)format;
	while (*p)
	{
		if (*p != '\0' && *p != '%')
		{
			write(1, p, 1);
			count++;
		}
		if (*p == '%' )
		{
			ft_clean_struct(&spec[0]);
			if (*(p + 1) != '\0')
				p++;
			else
			{
				va_end(ap);
				return (count);
			}
			p = ft_record_struct(&spec[0], p);
		}
		if(spec->type)
			count += ft_output(&spec[0], ap);
			ft_clean_struct(&spec[0]);
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
		printf("accuracy: %d\n", spec[0].accur);
		printf("size: %d\n", spec[0].size);
		printf("type: %c\n", spec[0].type);
		printf("----------------------\n");
		*/