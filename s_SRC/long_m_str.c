/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_m_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 04:44:53 by erodd             #+#    #+#             */
/*   Updated: 2020/01/23 03:46:55 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_HEAD/header.h"

char	*make_rounding(char **str, int pres)
{
	char	*tmp;
		
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + pres + 1))))
		return (NULL);
	tmp = ft_fill_str(*(str), tmp, pres);
	ft_strdel(str);
	return (tmp);
}

char	*ft_fill_str(char *str, char *tmp, int pres)
{
	int		i;
	int		j;
	int		mem;

	i = 0;
	j = 0;
	
	while (str[i] != '.')
		tmp[i++] = str[j++];
	tmp[i++] = '.';
	j = i;
	while (pres-- > -1)
	{
		while (str[j] != '\0' && pres-- >= 0)
			tmp[i++] = str[j++];
		tmp[i++] = '0';
	}
	i--;
	if (str[i] >= '5')
		mem = 1;
	else
		mem = 0;
	tmp[i] = '\0';
	tmp = ft_rounding(tmp, mem);
	
	return (tmp);
}

char	*ft_rounding(char *str, int mem)
{
	int i;
	char *new_str;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == '.')
			i--;
		if (mem == 1 && str[i] >= '0' && str[i] < '9')
		{
			str[i] = ((str[i] - '0') + mem) + '0';
			mem = 0;
			break ;
		}
		else if (mem == 1 && str[i] == '9')
		{
			str[i] = '0';
			i--;
		}
		else
			break ;
	}
	new_str = str;
	if (i == -1 && mem == 1)
	{
		new_str = ft_strjoin("1", str);
		ft_strdel(&str);
	}
	return (new_str);
}

char	*make_dot(char **str, unsigned short exponent)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1))))
		return (NULL);
	//tmp[ft_strlen(*str) + 1] = '\0';
	if ((*str)[i] == '0')
		i++;
	while (i <= ((exponent - 16383) * 0.301 + 1))
		tmp[j++] = (*str)[i++];
	tmp[j] = '.';
	j++;
	while ((*str)[i] != '\0')
		tmp[j++] = (*str)[i++];
	tmp[j] = '\0';
	//write(1, "\n\nBBB\n\n", 7);
	//write(1, tmp, ft_strlen(tmp));
	ft_strdel(str);
	return (tmp);
}

char	*make_dot_zero(char **str, unsigned short exponent)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	j = 2;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 3))))
		return (NULL);
	
	tmp[0] = '0';
	tmp[1] = '.';
	while ((*str)[i] != '\0')
	{
		tmp[j] = (*str)[i];
		i++;
		j++;
	}
	tmp[ft_strlen(*str) + 2] = '\0';
	//write(1, "\n\nAAA\n\n", 7);
	//write(1, tmp, ft_strlen(tmp));
	ft_strdel(str);
	return (tmp);
}
