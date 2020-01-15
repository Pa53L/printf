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

char	*is_flag(st_format *spec, char *str)
{
	while (*str == '-' || *str == '+' || *str == ' ' || *str == '#' \
		|| *str == '0')
	{
		if (spec->minus == 0 && *str == '-')
			spec->minus = 1;
		else if (spec->plus == 0 && *str == '+')
			spec->plus = 1;
		else if (spec->sharp == 0 && *str == '#')
			spec->sharp = 2;
		else if (spec->zero == 0 && *str == '0')
			spec->zero = 1;
		else if (spec->space == 0 && *str == ' ')
			spec->space = 1;
		str++;
	}
	return (str);
}

char	*is_width(st_format *spec, char *str, va_list vl)
{
	if (*str == '*')
	{
		if ((spec->width = va_arg(vl, int)) < 0)
			spec->width = 0;
		str++;
	}
	else
	{
		if ((spec->width = atoi(str)) < 0)
			spec->width = 0;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	if (*str == '$')
	{
		spec->dollar = spec->width;
		spec->width = 0;
		str++;
	}
	return (str);
}

char	*is_accuracy(int *accur, char *str, va_list vl)
{
	*accur = 0;
	if (!*str)
		return (str);
	if (*str == '*')
	{
		if ((*accur = va_arg(vl, int)) < 0)
			*accur = 0;
		str++;
	}
	else
	{
		if ((*accur = atoi(str)) < 0)
			*accur = 0;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	return (str);
}

char	*is_size(char *size, char *str)
{
	if (*str == 'h')
	{
		*size = 1;
		if (*(str + 1) == 'h')
			*size = 2;
	}
	else if (*str == 'l' || *str == 'z')
	{
		*size = 3;
		if (*(str + 1) == 'l')
			*size = 4;
	}
	else if (*str == 'L')
		*size = 5;
	while (*str == 'l' || *str == 'L' || *str == 'h' || *str == 'z')
		str++;
	return (str);
}

char	*is_type(char *type, char *str)
{
	int		i;
	char	*tmp_str;

	i = 0;
	tmp_str = NULL;
	while (i < TYPES_SIZE)
		if (*str == TYPES[i++])
			*type = *str;
	if (!*type)
	{
		tmp_str = str - 1;
		while (*tmp_str++)
			if (*tmp_str == '%')
			{
				*type = '%';
				str = tmp_str;
				break ;
			}
	}
	return (str);
}

char	*parse_specifiers(st_format *spec, char *str, va_list vl)
{
	if (!*str)
		return (str);
	ft_clean_struct(spec);
	if (*str == '-' || *str == '+' || *str == ' ' || *str == '#' || *str == '0')
		str = is_flag(spec, str);
	if (*str == '*' || (*str >= '1' && *str <= '9'))
		str = is_width(spec, str, vl);
	if ((*str == '*' || (*str >= '1' && *str <= '9')) && spec->width == 0)
		str = is_width(spec, str, vl);
	if (*str == '.')
		str = is_accuracy(&spec->accur, ++str, vl);
	if (*str == 'l' || *str == 'L' || *str == 'h' || *str == 'z')
		str = is_size(&spec->size, str);
	if (*str > '$')
		str = is_type(&spec->type, str);
	return (str);
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
