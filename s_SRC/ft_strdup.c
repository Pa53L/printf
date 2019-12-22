#include "../h_HEAD/header.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	if (!(dup = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
