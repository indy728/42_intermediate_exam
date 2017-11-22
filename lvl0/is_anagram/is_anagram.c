int	is_anagram(char *a, char *b)
{
	int	*checka[127 - 32] = {0};
	int	*checkb[127 - 32] = {0};
	int	i = -1;

	/* include checks for whether a string is passed or not
	   if both strings are null, should return 1*/
	while (a && a[++i])
		checka[a[i] - 32]++;
	i = -1;
	while (b && b[++i])
		checkb[b[i] - 32]++;
	i = -1;
	while (++i < 127 - 32)
	{
		if (checka[i] != checkb[i])
			return (0);
	}
	return (1);
}
