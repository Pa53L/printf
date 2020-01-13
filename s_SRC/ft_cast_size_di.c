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

void	ft_cast_size_di(st_format *spec, va_list ap, long long *ival)
{
	if (spec->size == 3)
		*ival = (short)va_arg(ap, int);
	else if (spec->size == 4)
		*ival = (char)va_arg(ap, int);
	else if (spec->size == 1)
		*ival = (long)va_arg(ap, long);
	else if (spec->size == 2)
		*ival = (long long)va_arg(ap, long long);
	else if (spec->size == 5)
		*ival = (long long)va_arg(ap, long long);
	else if (spec->size == 0)
		*ival = (int)va_arg(ap, int);
	return ;
}
