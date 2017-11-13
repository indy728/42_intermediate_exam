#include <stdio.h>

static int	max3(int a, int b, int c)
{
	a = a > b ? a : b;
	return (a > c ? a : c);
}

static int	max2(int a, int b)
{
	return (a > b ? a : b);
}

int	gold_gain(int **mine, int n)
{
	/* initialize a dummy 2D int array to the same size as "mine" */
	int		gg[n][n];
	int		i;
	int		j;

	/* special case if there is no mine or if "mine" is a 1x1 array */
	if (!mine || n == 0)
		return (0);
	if (n == 1)
		return (mine[0][0]);

	/* column 0 of new array is a duplicate of "mine" */
	i = -1;
	while (++i < n)
		gg[i][0] = mine[i][0];

	/* iterate down the columns to fill each cell with the value of
	   that location in "mine" plus the maximum value of any of the
	   cells which may have a path to it */
	j = 0;
	while (++j < n)
	{
		i = 0;
		/* case 0: row 0: only two possible paths to current cell */
		gg[i][j] = mine[i][j] + max2(
					gg[i][j - 1],
					gg[i + 1][j - 1]);

		/* case 1: rows 1 - (n - 1): three maximum of 3 possible paths */
		while (++i < n - 1)
		{
			gg[i][j] = mine[i][j] + max3(
						gg[i - 1][j - 1],
						gg[i][j - 1],
						gg[i + 1][j - 1]);
			/* the cells in the last column keep the max value of the 
			   current cell and the one above it */
			if (j == n - 1)
				gg[i][j] = max2(gg[i][j], gg[i - 1][j]);
		}
		
		/*case 2: row (n - 1): only two possible paths to current cell */
		gg[i][j] = mine[i][j] + max2(
					gg[i][j - 1],
					gg[i - 1][j - 1]);
		if (j == n - 1)
			gg[i][j] = max2(gg[i][j], gg[i - 1][j]);
		/* the final cell will contain the max value of the right-most column */ 
	}
	return (gg[n - 1][n - 1]);
}
