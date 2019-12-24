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

void	ft_cast_size_poxu(st_format *spec, va_list ap, unsigned long long *ival)
{
	if (spec->size == 3) /* h */
		*ival = (unsigned short)va_arg(ap, int);
	else if (spec->size == 4) /* hh */
		*ival = (unsigned char)va_arg(ap, int);
	else if(spec->size == 1) /* l */
		*ival = va_arg(ap, unsigned long);
	else if(spec->size == 2) /* ll */
		*ival = va_arg(ap, unsigned long long);
	else if(spec->size == 0) /* без размера, простой INT */
		*ival = va_arg(ap, unsigned int);
	return ;
}
