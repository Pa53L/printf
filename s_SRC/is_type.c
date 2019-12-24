/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:01:18 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/21 15:28:18 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*is_type(st_format *spec, char *p)
{
	if (*p == CHAR)
		spec->type = 1;
	else if (*p == STRING)
		spec->type = 2;
	else if (*p == OCTAL)
		spec->type = 8;
	else if (*p == DECIMAL || *p == DECIMAL_2 || *p == UNSIGN)
		spec->type = 10;
	else if (*p == POINTER)
		spec->type = 16;
	else if (*p == HEX)
		spec->type = 16;
	else if (*p == BIG_HEX)
		spec->type = 16;
	else if (*p == FLOAT)
		spec->type = 32;
	return (p);
}
