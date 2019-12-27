#include "../h_HEAD/header.h"

char	*is_type(char *type, char *p)
{
	int i;
	char *tmp_p;

	i = 0;
	tmp_p = NULL;
	while (i < 10)
	{
		if (*p == TYPES[i])
			*type = *p;
		i++;
	}
	if(!*type)
	{
		tmp_p = p;
		while (*tmp_p)
		{
			if (*tmp_p == '%')
			{
				*type = '%';
				p = tmp_p;
				break;
			}
			tmp_p++;
		}
	}
	return (p);
}