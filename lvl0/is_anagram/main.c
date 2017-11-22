#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	is_anagram(char *a, char *b);

int main()
{
	char *s1;
	char *s2;

	s1 = strdup("abcdef");
	s2 = strdup("fabcde");
	printf("String 1: %s\nString2: %s\nOutput: %d\nAnswer: %d\n", s1, s2, is_anagram(s1, s2), 1);
	s1 = strdup("basiparachromatin");
	s2 = strdup("marsipobranchiata");
	printf("String 1: %s\nString2: %s\nOutput: %d\nAnswer: %d\n", s1, s2, is_anagram(s1, s2), 1);
	s1 = strdup(".123?.");
	s2 = strdup("?321..");
	printf("String 1: %s\nString2: %s\nOutput: %d\nAnswer: %d\n", s1, s2, is_anagram(s1, s2), 1);
	s1 = strdup("abca");
	s2 = strdup("bcab");
	printf("String 1: %s\nString2: %s\nOutput: %d\nAnswer: %d\n", s1, s2, is_anagram(s1, s2), 0);
	s1 = strdup("  123~~");
	s2 = strdup("~~31~ 2 ");
	printf("String 1: %s\nString2: %s\nOutput: %d\nAnswer: %d\n", s1, s2, is_anagram(s1, s2), 0);
	return (0);
}
