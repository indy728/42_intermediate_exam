#include <stdio.h>

int	count_of_2(int n);

char	separate[71] = "----------------------------------------------------------------------";

int main()
{
	int	arr[] = { -2147483648, -5, 0, 2, 12, 25, 42, 128, 1024, 424242 }; 
	int	result[] = {0, 0, 0, 1, 2, 9, 15, 32, 308, 314541};
	int	i = -1;

	printf("%s\n\n", separate);
	while (++i < 10)
	{
		printf("input: %d\noutput: %d\nresult: %s\n\n%s\n\n", arr[i],
				count_of_2(arr[i]),
				count_of_2(arr[i]) == result[i] ?
				"\x1b[32mPASS\x1b[0m" :
				"\x1b[31mFAIL\x1b[0m" ,
				separate);
	}
	return (0);
}
