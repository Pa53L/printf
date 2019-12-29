/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_accuracy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:56:50 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/23 20:57:00 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*ft_strnew_num(st_format *spec, unsigned long long ival, int len)
{
	unsigned long strlen;
	char *str;
	int i;

	i = 0;
	strlen = spec->width + spec->space + spec->plus + spec->sign + len;
	if (spec->accur > 0)
		strlen = strlen + spec->accur;
	printf("for malloc : %d\n", strlen + 1);
	str = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!str)
		return (NULL);
	if (spec->minus == 0)
	{
		while (spec->width > 0)
		{
			str[i] = ' ';
			spec->width--;
			i++;
		}
	}
	if (spec->plus || spec->sign)
	{
		if(spec->sign)
			str[i] = '-';
		else
			str[i] = '+';
		i++;
	}
	while (spec->accur > 0)
	{
		str[i] = '0';
		spec->accur--;
		i++;
	}
	i = i + len - 1;
	printf("i is: [%d]\n", i);
	printf("end of str is : [%d]\n", strlen);
	printf("spec->width : %d\n", spec->width);
	str[strlen] = '\0';
	/* ОПОРА ВСЕЯ РУСИ ЗДЕСЬ *////////////
	if (ival == 0 && len > 0)			//
	{									//
		str[i] = '0';					//
		return (str);					//
	}									//
	while (ival > 0)					//
	{									//
		if (ival < 10)					//
		{								//
			str[i] = ITOA[ival];		//
			ival -= ival;				//
		}								//
		else							//
			str[i] = ITOA[ival % 10];	//
		ival /= 10;						//
		i--;							//
	}									//
	/* ОПОРА ЗАКОНЧИЛАСЬ *////////////////
	if (spec->minus == 1)
	{
		i = len;
		while (spec->width > 0)
		{
			str[i] = ' ';
			spec->width--;
			i++;
		}
	}
	return (str);
}
