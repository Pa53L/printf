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

char	*ft_record_struct(st_format *spec, char *p, va_list ap)
{
	if (*p == '-' || *p == '+' || *p == ' ' || *p == '#' || *p == '0')
		p = is_flag(&spec[0], p);
	if ((*p >= '1' && *p <= '9') || *p == '*')
		p = is_width(&spec->width, ap, p);
	if ((*p == '.' && *(p + 1)) || (*p == '.' && *(p + 1) == '*'))
		p = is_accuracy(&spec->accur, ap, p);
	if (*p == 'l' || *p == 'L' || *p == 'h')
		p = is_size(&spec->size, p);
	if (*p > '$')
		p = is_type(&spec->type, p);
	return (p);
}
// printf("----------------------\n");
// printf("minus: %d\n", spec[0].minus);
// printf("plus: %d\n", spec[0].plus);
// printf("space: %d\n", spec[0].space);
// printf("sharp: %d\n", spec[0].sharp);
// printf("zero: %d\n", spec[0].zero);
// printf("width: %d\n", spec[0].width);
// printf("accuracy: %d\n", spec[0].accur);
// printf("size: %d\n", spec[0].size);
// printf("type: %c\n", spec[0].type);
// printf("----------------------\n");