int	count_of_2(int n)
{
	int i = 2;
	int j = 0;
	int	k;
	
	while (i <= n)
	{
		k = i;
		while (k)
		{
			if (k % 10 == 2)
				++j;
			k /= 10;
		}
		++i;
	}
	return (j);
}
