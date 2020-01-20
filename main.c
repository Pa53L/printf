/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/21 00:20:24 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_HEAD/header.h"

int		main()
{
   ft_printf("{green}");
	// printf("|||MINE: %d\n",     ft_printf("{red}%12s {green}%5s{neon}", "hello, world!", "no color"));
	// printf("|||ORIGINAL: %d\n",    printf("%12s", "hello, world!"));
	// printf("\n");
   // printf("|||MINE: %d\n", ft_printf("%*3d", 5, 0));
   // printf("|||ORIGINAL: %d\n",    printf("%*3d", 5, 0));
   // printf("\n");
   // printf("|||MINE: %d\n",     ft_printf("%-+f|%-f|%-#f|%f|%+#f|%+f", 0., 0., 0., 0., -0., -0));
   // printf("|||ORIGINAL: %d\n",    printf("%-+f|%-f|%-#f|%f|%+#f|%+f", 0., 0., 0., 0., -0., -0));
   // printf("\n");
   printf("|||MINE: %d\n",     ft_printf("%.350f|%.350f|%.350f|%.350f|%.350f", 1.e-1, 1.e-2, 1.e-18, 1.e-57, 1.e-201));
   printf("|||ORIGINAL: %d\n",    printf("%.350f|%.350f|%.350f|%.350f|%.350f", 1.e-1, 1.e-2, 1.e-18, 1.e-57, 1.e-201));
   printf("\n");
   // printf("|||MINE: %d\n",     ft_printf("%d", -10));
   // printf("|||ORIGINAL: %d\n",    printf("%d", -10));
   /*
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
