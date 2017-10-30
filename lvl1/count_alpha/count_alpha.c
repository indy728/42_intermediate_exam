#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int		abc[26] = {0};
		char	*str = av[1];
		int		i = -1;
		int 	flag = 0;

		while (str[++i])
		{
			if ('a' <= str[i] && str[i] <= 'z')
				abc[str[i] - 'a'] += 1;
			else if ('A' <= str[i] && str[i] <= 'Z')
				abc[str[i] - 'A'] += 1;
		}
		i = -1;
		while (str[++i])
		{
			if ('a' <= str[i] && str[i] <= 'z' && abc[str[i] - 'a'])
			{
				printf("%s%d%c", flag ? ", " : "", abc[str[i] - 'a'], str[i]);
				flag = 1;
				abc[str[i] - 'a'] = 0;
			}
			else if ('A' <= str[i] && str[i] <= 'Z' && abc[str[i] - 'A'])
			{
				printf("%s%d%c", flag ? ", " : "", abc[str[i] - 'A'], str[i] - 'A' + 'a');
				flag = 1;
				abc[str[i] - 'A'] = 0;
			}
		}
	}
	printf("\n");
	return (0);
}
