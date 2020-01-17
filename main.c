/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/17 20:18:51 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_HEAD/header.h"

int		main()
{
   // ft_printf("{red}");
	// printf("|||MINE: %d\n",     ft_printf("{red}%12s {green}%5s{neon}", "hello, world!", "no color"));
	// printf("|||ORIGINAL: %d\n",    printf("%12s", "hello, world!"));
	// printf("\n");
	// printf("|||MINE: %d\n",     ft_printf("{red}%Lf", 1024.1234567899));
	// printf("|||MINE: %d\n",     ft_printf("{green}%Lf", 1024.1234567899));
	// printf("|||MINE: %d\n",     ft_printf("{blue}%Lf", 1024.1234567899));
	// printf("|||MINE: %d\n",     ft_printf("{yellow}%Lf", 1024.1234567899));
	// printf("|||MINE: %d\n",     ft_printf("{orange}%Lf", 1024.1234567899));
	// printf("|||MINE: %d\n",     ft_printf("{pink}%Lf", 1024.1234567899));
	// printf("|||MINE: %d\n",     ft_printf("{neon}%Lf", 1024.1234567899));
   // printf("|||MINE: %d\n", ft_printf("%*3d", 5, 0));
   // printf("|||ORIGINAL: %d\n",    printf("%*3d", 5, 0));
   // printf("\n");
   // printf("|||MINE: %d\n", ft_printf("%.f", -958.125));
   // printf("|||ORIGINAL: %d\n",    printf("%.f", -958.125));
   /*
   printf("\n");
   printf("|||MINE: %d\n", ft_printf("% 5.3f", 7.3));
   printf("|||ORIGINAL: %d\n",    printf("% 5.3f", 7.3));
   printf("\n");
   printf("|||MINE: %d\n", ft_printf("% 05.3f", 7.3));
   printf("|||ORIGINAL: %d\n",    printf("% 05.3f", 7.3));
   printf("\n");
   printf("|||MINE: %d\n", ft_printf("% 05.0f", -7.3));
   printf("|||ORIGINAL: %d\n",    printf("% 05.0f", -7.3));
   printf("\n");
   printf("|||MINE: %d\n", ft_printf("% -5.3f", 7.3));
   printf("|||ORIGINAL: %d\n",    printf("% -5.3f", 7.3));
   printf("\n");
   printf("|||MINE: %d\n", ft_printf("% -5.0f", 7.3));
   printf("|||ORIGINAL: %d\n",    printf("% -5.0f", 7.3));
   */
   return (0);
}
/*
Соответственно, побитовое произведение чисел 31 и 17 даст 17, так как 31 это 00011111 , а 17 это 00010001

00011111
00010001
↓↓↓↓↓↓↓↓
00010001
*/

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
/*
char *itobs(unsigned long long n, char *ps)
{
   int i;
   const static unsigned long long size = CHAR_BIT * sizeof(unsigned long long);
   for (i = size - 1; i >= 0; i--, n >>= 1)
      ps[i] = (01 & n) + '0';
   ps[size] = '\0';
   return (ps);
}
*/
