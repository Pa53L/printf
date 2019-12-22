#include "../h_HEAD/header.h"
#include <stdio.h>

size_t	ft_address(st_format *spec, uint64_t lval)
{
	char *tmp;
	char *newstr;
	char *pref;
	int base;
	int i;

	i = 0;
	base = 8;
	pref = "\0";
	if (spec->type == 'p' || spec->type == 'x' || spec->type == 'X')
		base = 16;
	if (spec->type == 'p')
		pref = "0x";
	/*if (spec->type == 'p' && lval == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}*/

	tmp = ft_itoabase(lval, base, tmp);
	if (spec->type == 'p')
		newstr = ft_strjoin(pref, tmp);
	else
		newstr = ft_strdup(tmp);
	
	if (spec->type == 'X')
	{
		while (newstr[i] != '\0')
		{
			if (newstr[i] >= 97 && newstr[i] <= 102)
				newstr[i] = newstr[i] - 32;
			i++;
		}
	}
	if (spec->width > ft_strlen(newstr) && spec->minus == 0)
	{
		while ((spec->width - ft_strlen(newstr)) > 0)
		{
			newstr = ft_strjoin(" ", newstr);
			free (newstr);
		}

	}
	else if (spec->width > ft_strlen(newstr) && spec->minus == 1)
	{
		while ((spec->width - ft_strlen(newstr)) > 0)
		{
			newstr = ft_strjoin(newstr, " ");
			free (newstr);
		}

	}
	write(1, newstr, ft_strlen(newstr));
	free (newstr);
	//printf("%d\n", spec->width);
	return (ft_strlen(newstr));
}
