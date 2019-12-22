/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/22 22:57:09 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_HEAD/header.h"

int		main()
{
	printf("M: %d\n", ft_printf("%23ld|%-23ld|%+23ld|% 23ld|%023ld", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX));
	printf("\n");
	printf("I: %d\n",    printf("%23ld|%-23ld|%+23ld|% 23ld|%023ld", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX));
	printf("\n");

	return (0);
}
/*
   printf("----------------------\n");
   printf("minus: %d\n", spec[0].minus);
   printf("plus: %d\n", spec[0].plus);
   printf("space: %d\n", spec[0].space);
   printf("sharp: %d\n", spec[0].sharp);
   printf("zero: %d\n", spec[0].zero);
   printf("width: %d\n", spec[0].width);
   printf("accuracy: %d\n", spec[0].accuracy);
   printf("size: %d\n", spec[0].size);
   printf("type: %c\n", spec[0].type);
   printf("----------------------\n");
   */
