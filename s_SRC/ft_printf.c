/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 04:49:32 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

int		ft_printf(const char *format, ...)
{
	size_t		count;
	char		*p;
	va_list		ap;
	va_list		first_ap;
	st_format	spec[1];

	count = 0;
	va_start(ap, format);
	va_copy(first_ap, ap);
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
			ft_clean_struct(&spec[0]);
			p = parse_specifiers(&spec[0], p, ap);
			if (spec->type)
				count = count + parse_output(&spec[0], ap, first_ap);
			else if (*p != '%' && *p)
			{
				write(1, p, 1);
				count++;
			}
			else if (!*p)
				return (count);
			ft_clean_struct(&spec[0]);
		}
		p++;
	}
	va_end(ap);
	/* kek */
	return (count);
}
