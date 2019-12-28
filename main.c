/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/24 07:09:24 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_HEAD/header.h"

int		main()
{
	printf("|MMM: %d\n", ft_printf("% 10.5d", 42));
	printf("|III: %d\n", printf("% 10.5d", 42));
	printf("\n");
	// printf("|M: %d\n", ft_printf("%-10.5d", 4242));
   // printf("|I: %d\n",    printf("%-10.5d", 4242));
   // printf("\n");
	// printf("|M: %d\n", ft_printf("hello, %s.", "gavin"));
   // printf("|I: %d\n",    printf("hello, %s.", "gavin"));
	// printf("\n");
	// printf("|M: %d\n", ft_printf("%-#23o|%-023o|%#023o|%-#23o", 0U, 0U, 0U, 0));
   // printf("|I: %d\n",    printf("%-#23o|%-023o|%#023o|%-#23o", 0U, 0U, 0U, 0));
   // printf("\n");
   // printf("|M: %d\n", ft_printf("%.x|%-.x|%#.x|%0.x", 0U, 0U, 0U, 0U));
   // printf("|I: %d\n", printf("%.x|%-.x|%#.x|%0.x", 0U, 0U, 0U, 0U));
   // printf("\n");
   // printf("|M: %d\n", ft_printf("%-#23.x|%-023.x|%#023.x|%-#023.x", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX));
   // printf("|I: %d\n", printf("%-#23.x|%-023.x|%#023.x|%-#023.x", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX));
   // printf("\n");
   // printf("|M: %d\n", ft_printf("%23X|%-23X|%#X|%023X", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX));
   // printf("|I: %d\n", printf("%23X|%-23X|%#X|%023X", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX));
   // printf("\n");
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