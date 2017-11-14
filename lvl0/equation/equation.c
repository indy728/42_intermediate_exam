#include <stdio.h>

void	equation(int n)
{
	int flag = 0;
	int a = -1;
	int b;
	int c;
	
	while (++a <= 9)
	{
		b = -1;
		while (++b <= 9)
		{
			c = -1;
			while (++c <= 9)
			{
				if ((a + c) * 10 + b + a == n)
					printf("A = %d, B = %d, C = %d\n", a, b, c);
			}
		}
	}
}
