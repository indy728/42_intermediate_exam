#include "ord_alphlong.h"

int	oa_strlen(char *str, int i)
{
	int		j = 0;
	char	*tmp = str + i;
	while (tmp[j] && tmp[j] != ' ' && tmp[j] != '\t')
		++j;
	return (j);
}

char	*oa_strdup(char *str, int i)
{
	int		len = oa_strlen(str, i);
	char	*dup = (char *)malloc(len + 1);
	int		j = -1;

	dup[len] = 0;
	while (++j < len)
		dup[j] = str[i + j];
	return (dup);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
