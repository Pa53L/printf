
#include "../h_HEAD/header.h"

char	*is_flag(st_format_spec *spec, char *p)
{
	while (*p == '-' || *p == '+' || *p == ' ' || *p == '#' || *p == '0')
	{
		if (spec->minus == 0 && *p == '-')
			spec->minus = 1;
		else if (spec->plus == 0 && *p == '+')
			spec->plus = 1;
		else if (spec->sharp == 0 && *p == '#')
			spec->sharp = 1;
		else if (spec->zero == 0 && *p == '0')
			spec->zero = 1;
		else if (spec->space == 0 && *p == ' ')
			spec->space = 1;
		p++;
	}
	return (p);
}
