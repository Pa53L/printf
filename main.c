/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/23 02:58:10 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int ac, char **av)
{
   ft_printf("{blue}%5$s{green}%4$s{red}%2$s{yellow}%1$s{orange}%6$s{pink}%3$s\n", "smack", "my", "bitch", "up", "prodigy", "forever");

   // PROBLEMS THAT WE HAVE
   printf("|||MINE: %d\n",     ft_printf("%.350f|", 1.e-57));
   printf("|||ORIGINAL: %d\n",    printf("%.350f|", 1.e-57));
   // printf("\n");
   // printf("|||MINE: %d\n",     ft_printf("%.f|%.f|%.f|%.f|%.f", 44.5, 44.4, 44.6, 44.50001, 44.5 + 1e-52));
   // printf("|||ORIGINAL: %d\n",    printf("%.f|%.f|%.f|%.f|%.f", 44.5, 44.4, 44.6, 44.50001, 44.5 + 1e-52));
   // printf("\n");
   printf("|||MINE: %d\n",     ft_printf("%|%%|%%%|%%%%"));
   printf("|||ORIGINAL: %d\n",    printf("%|%%|%%%|%%%%"));
   // printf("\n");
   // printf("|||MINE: %d\n",     ft_printf("% |% h|% hZ"));
   // printf("|||ORIGINAL: %d\n",    printf("% |% h|% hZ"));
   // printf("\n");
   // printf("|||MINE: %d\n",     ft_printf("%%-%|%%+%|%% %|%%#%"));
   // printf("|||ORIGINAL: %d\n",    printf("%%-%|%%+%|%% %|%%#%"));
   // printf("\n");
   // что нужно сделать
   // переделать makefile
   // проверить бонусы
   // дописать бонус
   // разобраться с процентами ебаными
   
   return 0;
}

// "%LLf", 42.5