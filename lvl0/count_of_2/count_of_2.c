int	count_of_2(int n)
{
	int i = 1;
	int j = 0;
	int	k;
	
	/* checks each number from 2 to input n */
	while (++i <= n)
	{
		k = i;
		/* checks each decimal place for a 2 */
		while (k)
		{
			if (k % 10 == 2)
				++j;
			k /= 10;
		}
	}
	return (j);
}
