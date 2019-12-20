/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:01:18 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/18 20:13:23 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*is_type(st_format_spec *spec, char *p)
{
	if (*p == CHAR)
		spec->type = CHAR;
	else if (*p == STRING)
		spec->type = STRING;
	else if (*p == POINTER)
		spec->type = POINTER;
	else if (*p == DECIMAL)
		spec->type = DECIMAL;
	else if (*p == DECIMAL_2)
		spec->type = DECIMAL;
	else if (*p == OCTAL)
		spec->type = OCTAL;
	else if (*p == HEX)
		spec->type = HEX;
	else if (*p == BIG_HEX)
		spec->type = BIG_HEX;
	else if (*p == FLOAT)
		spec->type = FLOAT;
	return (p);
}
