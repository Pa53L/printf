/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/23 19:21:43 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct struct_specifer
{
	short size;
	short type;
} st_format;

int		ft_kek(st_format *p)
{	
	p->size = 12;
	return (0);
}

int		main()
{
	st_format spec;
	st_format *p;

	p = &spec;
	p->size = 32;
	printf("%d\n", p->size);
	ft_kek(p);
	printf("%d\n", p->size);
	return (0);
}