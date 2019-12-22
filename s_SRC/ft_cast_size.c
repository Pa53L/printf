/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:57:22 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/22 20:49:09 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

void	ft_cast_size(st_format *spec, va_list ap, long long *ival)
{
	if (spec->size == 3) /* h */
		*ival = (short)va_arg(ap, int);
	else if (spec->size == 4) /* hh */
		*ival = (char)va_arg(ap, int);
	else if(spec->size == 1) /* l */
		*ival = (long)va_arg(ap, long);
	else if(spec->size == 2) /* ll */
		*ival = (long long)va_arg(ap, long long);
	else if(spec->size == 5) /* L */
		*ival = (long long)va_arg(ap, long long);
	else if(spec->size == 0) /* без размера, простой INT */
		*ival = (int)va_arg(ap, int);
	return ;
}
