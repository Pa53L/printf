/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/23 02:55:44 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

void		printf_printf(char *str, uint64_t *cnt)
{
	write(1, str, 1);
	(*cnt)++;
	return ;
}

uint64_t	printf_body(st_format *spec, char *str, va_list vl, va_list fst_vl)
{
	uint64_t	cnt;
	int i;

	i = '1';
	cnt = 0;
	//write(1, str, ft_strlen(str));
	//write(1, "\n\n", 2);
	while (*str)
	{
		if (*str == '{')
			str = parse_bcolor(str);
		else if (*str != '%')
			printf_printf(str, &cnt);
		else if (*str == '%')
		{
			//write(1, &i, 1);
			str = parse_specifiers(spec, ++str, vl);
			
			if (spec->type)
			{
				cnt = cnt + parse_output(spec, vl, fst_vl);
				//write(1, &i, 1);
			}
			else if (*str != '%' && *str)
				printf_printf(str, &cnt);
			
		}
		if (!*str)
			return (cnt);
		str++;
		
		//write(1, str, 1);
		//write(1, "\n\n\n", 3);
		i++;
	}
	return (cnt);
}

int			ft_printf(const char *format, ...)
{
	char		*str;
	va_list		fst_vl;
	va_list		vl;
	uint64_t	cnt;
	st_format	spec[1];

	va_start(vl, format);
	va_copy(fst_vl, vl);
	str = (char *)format;
	cnt = printf_body(spec, str, vl, fst_vl);
	va_end(vl);
	return (cnt);
}
