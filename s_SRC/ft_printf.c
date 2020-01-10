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
		if (*p != '%')
		{
			write(1, p, 1);
			count++;
		}
		else if (*p == '%' )
		{
			ft_clean_struct(&spec[0]);
			if (*(p + 1) != '\0')
				p++;
			else
			{
				va_end(ap);
				return (count);
			}
			p = ft_record_struct(&spec[0], p, ap);
			if (spec->type)
				count = count + ft_output(&spec[0], ap);
			else
				return (0);
			ft_clean_struct(&spec[0]);
		}
		p++;
	}
	va_end(ap);
	return (count);
}