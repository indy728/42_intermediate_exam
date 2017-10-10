int	sum_greater_than(int *arr, int q, int n)
{
	int sum = 0;

	while (++q < n)
		sum += arr[q];
	return (sum);
}

int	sum_less_than(int *arr, int q)
{
	int sum = 0;

	while (--q >= 0)
		sum += arr[q];
	return (sum);
}

int	find_pivot(int *arr, int n)
{
	int q = n / 2;
	int flag = 0;
	int less;
	int greater;
	int min = 0;
	int max = n;

	if (n < 3)
		return (-1);
	while(max - min > 1)
	{
		less = sum_less_than(arr, q);
		greater = sum_greater_than(arr, q, n);
		if (less < greater)
		{
			min = q;
			q = q + (max - q) / 2;
		}
		else if (less > greater)
		{
			max = q;
			q = min + (q - min) / 2;
		}
		else
			return (q);
	}
	return (-1);
}
