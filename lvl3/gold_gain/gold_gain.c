#include <stdlib.h>

static int	max3(int a, int b, int c)
{
	if (a < b)
		return (b < c ? c : b);
	return (a < c ? c : a);
}

static int	max2(int a, int b)
{
	return (a > b ? a : b);
}

int	gold_gain(int **mine, int n)
{
	int		gg[n][n];
	int		i;
	int		j;

	if (!mine || n == 0)
		return (0);
	if (n == 1)
		return (mine[0][0]);
	i = -1;
	while (++i < n)
		gg[i][0] = mine[i][0];
	j = 0;
	while (++j < n - 1)
	{
		i = 0;
		gg[i][j] = mine[i][j] + max2(
					gg[i][j - 1],
					gg[i + 1][j - 1]);
		while (++i < n - 1)
		{
			gg[i][j] = mine[i][j] + max3(
						gg[i - 1][j - 1],
						gg[i][j - 1],
						gg[i + 1][j - 1]);
		}
		gg[i][j] = mine[i][j] + max2(
					gg[i][j - 1],
					gg[i - 1][j - 1]);
	}
	i = 0;
	gg[i][j] = mine[i][j] + max2(
				gg[i][j - 1],
				gg[i + 1][j - 1]);
	while (++i < n - 1)
	{
		gg[i][j] = mine[i][j] + max3(
					gg[i - 1][j - 1],
					gg[i][j - 1],
					gg[i + 1][j - 1]);
		gg[i][j] = max2(gg[i][j], gg[i - 1][j]);
	}
	gg[i][j] = mine[i][j] + max2(
				gg[i][j - 1],
				gg[i - 1][j - 1]);
	gg[i][j] = max2(gg[i][j], gg[i - 1][j]);
	return (gg[i][j]);
}
