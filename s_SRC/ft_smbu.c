/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smbu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 05:39:01 by erodd             #+#    #+#             */
/*   Updated: 2020/01/23 03:18:05 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*parse_mantis(unsigned long mantisa)
{
	char	*str;
	int		j;

	str = (char *)malloc(sizeof(char) * 65);
	str[64] = '\0';
	j = 0;
	while (j <= 63)
	{
		str[j] = '0';
		j++;
	}
	str = make_mantisa(str, mantisa);
	return (str);
}

char	*make_mantisa(char *str, unsigned long mantisa)
{
	char	bin_str[CHAR_BIT * sizeof(unsigned long) + 1];
	int		i;
	int		j;
	int		mem;
	char	tmp;

	mem = 0;
	i = 0;
	while (itobs(mantisa, bin_str)[i] != '\0')
	{
		j = 63;
		if (itobs(mantisa, bin_str)[i] == '1')
		{
			while (j >= 0)
			{
				tmp = str[j];
				str[j] = ((str[j] - '0') + (DG[i][j] - '0') + mem) % 10 + '0';
				mem = ((tmp - '0') + (DG[i][j] - '0') + mem) / 10;
				j--;
			}
		}
		i++;
	}
	return (str);
}

char	*itobs(unsigned long long n, char *ps)
{
	int			i;
	uint64_t	size;

	size = CHAR_BIT * sizeof(uint64_t);
	i = size - 1;
	while (i >= 0)
	{
		ps[i] = (01 & n) + '0';
		i--;
		n >>= 1;
	}
	ps[size] = '\0';
	return (ps);
}

void	fill_rigth_left(t_mult *m, char **a, char **b)
{
	m->str2 = *a;
	m->str1 = *b;
	m->len1 = ft_strlen(*a) - 1;
	m->len2 = ft_strlen(*b) - 1;
	//printf("AEAE %s\n", *a);
	//printf("BEBE %s\n", *b);
}

char	*str_no_prec(char sharp)
{
	char	*full_str;

	full_str = NULL;
	if (sharp)
	{
		if (!(full_str = (char *)malloc(sizeof(char) * 3)))
			return (NULL);
		full_str[0] = '0';
		full_str[1] = '.';
		full_str[2] = '\0';
	}
	else
	{
		if (!(full_str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		full_str[0] = '0';
		full_str[1] = '\0';
	}
	return (full_str);
}
