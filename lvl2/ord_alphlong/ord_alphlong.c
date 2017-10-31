#include "ord_alphlong.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		t_tree	*arr[1024];
		int		i = -1;
		char	*str = av[1];

		while (++i < 1024)
			arr[i] = NULL;
		i = -1;
		while (str[++i])
		{
			if ((i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t') &&
					(('a' <= str[i] && str[i] <= 'z') ||
					 ('A' <= str[i] && str[i] <= 'Z') ||
					 ('0' <= str[i] && str[i] <= '9')))
			{
				insert(&arr[oa_strlen(str, i)], create_node(str, i));
			}
		}
		i = -1;
		while (++i < 1024)
		{
			if (arr[i])
			{
				g = 0;
				print_tree(arr[i]);
				write(1, "\n", 1);
				destroy_tree(arr[i]);
			}
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
