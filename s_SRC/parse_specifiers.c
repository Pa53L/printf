/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:23:20 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 22:31:38 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*is_flag(st_format *spec, char *p)
{
	while (*p == '-' || *p == '+' || *p == ' ' || *p == '#' || *p == '0')
	{
		if (spec->minus == 0 && *p == '-')
			spec->minus = 1;
		else if (spec->plus == 0 && *p == '+')
			spec->plus = 1;
		else if (spec->sharp == 0 && *p == '#')
			spec->sharp = 2;
		else if (spec->zero == 0 && *p == '0')
			spec->zero = 1;
		else if (spec->space == 0 && *p == ' ')
			spec->space = 1;
		p++;
	}
	return (p);
}

char	*is_width(st_format *spec, va_list ap, char *p)
{
	spec->width = atoi(p);
	if (*p == '*')
	{
		spec->width = va_arg(ap, int);
		p++;
	}
	else
		while (*p >= '0' && *p <= '9')
			p++;
	if (*p == '$')
	{
		spec->dollar = spec->width;
		spec->width = 0;
		p++;
	}
	return (p);
}

char	*is_accuracy(st_format *spec, va_list ap, char *p)
{
	spec->accur = 0;
	if (*(p + 1))
		p++;
	else
		return (p);
	spec->accur = atoi(p);
	if (*p == '*')
	{
		spec->accur = va_arg(ap, int);
		p++;
	}
	else
		while (*p >= '0' && *p <= '9')
			p++;
	return (p);
}

char	*is_size(short *size, char *p)
{
	if (*p == 'l' || *p == 'z')
	{
		*size = 1;
		if (*(p + 1) == 'l')
			*size = 2;
	}
	if (*p == 'h')
	{
		*size = 3;
		if (*(p + 1) == 'h')
			*size = 4;
	}
	if (*p == 'L')
		*size = 5;
	while (*p == 'l' || *p == 'L' || *p == 'h' || *p == 'z')
		p++;
	return (p);
}

char	*is_type(st_format *spec, char *p)
{
	int i;
	char *tmp_p;

	i = 0;
	tmp_p = NULL;
	while (i < TYPES_SIZE)
	{
		if (*p == TYPES[i])
			spec->type = *p;
		i++;
	}
	if (!spec->type)
	{
		tmp_p = p;
		while (*tmp_p)
		{
			if (*tmp_p == '%')
			{
				spec->type = '%';
				p = tmp_p;
				break ;
			}
			tmp_p++;
		}
	}
	return (p);
}

char	*parse_specifiers(st_format *spec, char *p, va_list ap)
{
	if (*(p + 1) == '\0')
		return (p);
	else
		p++;
	if (*p == '-' || *p == '+' || *p == ' ' || *p == '#' || *p == '0')
		p = is_flag(&spec[0], p);
	if (*p == '*' || (*p >= '1' && *p <= '9'))
		p = is_width(&spec[0], ap, p);
	if (spec->width == 0 && (*p == '*' || (*p >= '1' && *p <= '9')))
		p = is_width(&spec[0], ap, p);
	if ((*p == '.' && *(p + 1)) || (*p == '.' && *(p + 1) == '*'))
		p = is_accuracy(&spec[0], ap, p);
	if (*p == 'l' || *p == 'L' || *p == 'h' || *p == 'z')
		p = is_size(&spec->size, p);
	if (*p > '$')
		p = is_type(&spec[0], p);
	return (p);
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
	printf("DOLLAR: %d\n", spec[0].dollar);
	printf("size: %d\n", spec[0].size);
	printf("type: %c\n", spec[0].type);
	printf("----------------------\n");
	*/
