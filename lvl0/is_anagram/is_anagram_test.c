#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	is_anagram(char *a, char *b);

char	*ft_strdup(char *str)
{
	char *new = (char *)malloc(strlen(str) + 1);
	new = strcpy(new, str);
	return (new);
}

int main()
{
	char *s1;
	char *s2;

	s1 = ft_strdup("abcdef");
	s2 = ft_strdup("fabcde");
	printf("Output: %d, answer: %d\n", is_anagram(s1, s2), 1);
	s1 = ft_strdup("basiparachromatin");
	s2 = ft_strdup("marsipobranchiata");
	printf("Output: %d, answer: %d\n", is_anagram(s1, s2), 1);
	s1 = ft_strdup("abca");
	s2 = ft_strdup("bcab");
	printf("Output: %d, answer: %d\n", is_anagram(s1, s2), 0);
	return (0);
}
