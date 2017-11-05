int	is_anagram(char *a, char *b)
{
	int	*checka[127 - 32] = {0};
	int	*checkb[127 - 32] = {0};
	int	i = -1;

	while (a[++i])
		checka[a[i] - 32]++;
	i = -1;
	while (b[++i])
		checkb[b[i] - 32]++;
	i = -1;
	while (++i < 127 - 33)
	{
		if (checka[i] != checkb[i])
			return (0);
	}
	return (1);
}
