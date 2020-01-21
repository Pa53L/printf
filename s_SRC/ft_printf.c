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
	char		*str;
	va_list		fst_vl;
	va_list		vl;
	uint64_t	cnt;
	st_format	spec[1];

	cnt = 0;
	va_start(vl, format);
	va_copy(fst_vl, vl);
	str = (char *)format;
	while (*str)
	{
		if (*str == '{')
			str = parse_bcolor(str);
		if (*str == '\0')
			return (cnt);
		else if (*str != '%')
		{
			write(1, str, 1);
			cnt++;
		}
		else if (*str == '%')
		{
			str = parse_specifiers(spec, ++str, vl);
			if (spec->type)
				cnt = cnt + parse_output(spec, vl, fst_vl);
			else if (*str != '%' && *str)
			{
				write(1, str, 1);
				cnt++;
			}
			else if (!*str)
				return (cnt);
			ft_clean_struct(spec);
		}
		str++;
	}
	va_end(vl);
	return (cnt);
}
