/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:23:20 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/23 19:18:26 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*is_size(st_format *spec, char *p)
{
	if(*p == 'l' || *p == 'L' || *p == 'h')
	{
		if (*p == 'l')
		{
			spec->size = 1;
			if (*(p + 1) == 'l')
				spec->size = 2;
		}
		if (*p == 'h')
		{
			spec->size = 3;
			if (*(p + 1) == 'h')
				spec->size = 4;
		}
		if (*p == 'L')
			spec->size = 5;
		while (*p == 'l' || *p == 'L' || *p == 'h')
			p++;
	}
	return (p);
}

char	*is_type(st_format *spec, char *p)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (*p == TYPES[i])
			spec->type = *p;
		i++;
	}
	return (p);
}

char	*ft_record_struct(st_format *spec, char *p)
{
	char *tmp_p;

	tmp_p = NULL;

	/* is flag */
	while (*p == '-' || *p == '+' || *p == ' ' || *p == '#' || *p == '0')
	{
		if (spec->minus == 0 && *p == '-')
			spec->minus = 1;
		else if (spec->plus == 0 && *p == '+')
			spec->plus = 1;
		else if (spec->sharp == 0 && *p == '#')
			spec->sharp = 1;
		else if (spec->zero == 0 && *p == '0')
			spec->zero = 1;
		else if (spec->space == 0 && *p == ' ')
			spec->space = 1;
		p++;
	}

	/* is width */
	if(*p >= '0' && *p <= '9')
	{
		spec->width = atoi(p);
		while (*p >= '0' && *p <= '9')
			p++;
	}

	/* is accurc */
	if (*p == '.' && *(p + 1))
	{
		spec->accur = 0;
		if (*(p + 1))
			p++;
		spec->accur += atoi(p);
		while (*p >= '0' && *p <= '9')
			p++;
	}
	p = is_size(&spec[0], p);
	p = is_type(&spec[0], p);
	if(!spec->type)
	{
		tmp_p = p;
		while (*tmp_p)
		{
			if (*tmp_p == '%')
			{
				spec->type = '%';
				p = tmp_p;
				break;
			}
			tmp_p++;
		}
	}
	return (p);
}