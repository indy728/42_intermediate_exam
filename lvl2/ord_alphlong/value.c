#include "ord_alphlong.h"

static int	alpha_val(char c)
{
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 9);
	else if ('A' <= c && c <= 'Z')
		return (c - 'A' + 9);
	else
		return (c - '0');
}

int	get_value(char *root, char *new)
{
	int		i = -1;
	int		rval;
	int		nval;

	while (root[++i])
	{
		rval = alpha_val(root[i]);	
		nval = alpha_val(new[i]);
		if (rval > nval)
			return (-1);
		else if (rval < nval)
			return (1);
	}
	return (1);
}
