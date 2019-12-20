#include "../h_HEAD/header.h"

char	*check_format_specification(char *p)
{
	size_t i;
	size_t n;
	char *new_p;
	char *old_p;

	i = 0;
	n = 0;
	if (!p)
		return NULL;
	old_p = p;
	while (*p != '%' && *p != '\0' && *p++ != '\n')
		i++;
	if(!(new_p = (char *)malloc(sizeof(char) * (i + 1))) || !(i + 1))
		return NULL;
	while (n < i)
	{
		new_p[n] = old_p[n];
		n++;
	}
	new_p[n] = '\0';
	return (new_p);
}
