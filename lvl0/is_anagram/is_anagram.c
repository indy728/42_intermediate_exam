int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		++i;
	return (i);
}

int	find(char *str, char c)
{
	int i = -1;

	while (str[++i])
	{
		if (str[i] == c)
		{
			str[i] = 10;
			return (1);
		}
	}
	return (0);
}

int	is_anagram(char *a, char *b)
{
	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	int i = -1;
	while (a[++i])
	{
		if (!find(b, a[i]))
			return (0);
	}
	return (1);
}
