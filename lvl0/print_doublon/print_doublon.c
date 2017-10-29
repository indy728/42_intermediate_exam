#include <stdio.h>

#define I (astart + aflag * i)
#define J (bstart + bflag * j)

void	print_doublon(int *a, int na, int *b, int nb)
{
	int i = 0;
	int j = 0;
	int aflag = 1;
	int bflag = 1;
	int flag = 0;
	int astart = 0;
	int bstart = 0;

	if (na > 1 && a[0] > a[1])
	{
		astart = na - 1;
		aflag = -1;
	}
	if (nb > 1 && b[0] > b[1])
	{
		bstart = nb - 1;
		bflag = -1;
	}
	while (i < na && j < nb)
	{
		if (a[I] == b[J])
		{
			printf("%s%d", flag ? " ": "", a[I]);
			flag = 1;
			++i;
			++j;
		}
		else if (a[I] > b[J])
			++j;
		else
			++i;
	}
	printf("\n");
}
