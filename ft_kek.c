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

#include "h_HEAD/header.h"

int		ft_printf(const char *format, ...)
{	
	char *p;
	va_list ap;
	va_list ap_2;
	size_t count;
	int i;
	st_format spec[1];

	count = 0;
	i = 0;
	va_start(ap, format); /* устанавливаем ap на 1-й аргумент без имени */
	p = (char *)format;
	while (*p)
	{
		if (*p != '%')
		{
			write(1, p, 1);
			count++;
		}
		else if (*p == '%')
		{
			va_arg(ap, int);
			va_copy(ap_2, ap);
			i = va_arg(ap_2, int);
			write(1, &i, 1);
		}
		p++;
	}
	va_end(ap);
	return (count);
}

int		main()
{
	ft_printf("%\n", 'm', 'k');
}