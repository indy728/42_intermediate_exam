static int	sum(int *arr, int n)
{
	int	i = 0;
	int sum = 0;

	while (++i < n)
	{
		sum += arr[i];
	}
	return (sum);
}

int	find_pivot(int *arr, int n)
{
	int i = 0;
	int l = 0;
	/* pivot starts at zero, r represents the sum of everything to the right of zero */
	int r = sum(arr, n);

	/* the problem says this will never be a case */
	if (!arr || n == 0)
		return (-1);

	if (l == r)
		return (0);
	/* iterate through one time [second time overall --> O(2n) == O(n)],
	   as we increment, l changes by the value at previous pivot location,
	   r changes by the value of the current pivot */
	while (++i < n)
	{		
		l += arr[i - 1];
		r -= arr[i];
		if (r == l)
			return (i);
	}
	return (-1);
}
