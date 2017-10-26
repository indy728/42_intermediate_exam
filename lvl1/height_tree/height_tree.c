struct s_node {
	int				value;
	struct s_node	**nodes;
};

int	ft_max(int a, int b)
{
	return (a >= b ? a : b);
}

int	go_deeper(struct s_node *node, int height)
{
	int	max;
	int i;
	struct s_node **arr;

	max = height;
	arr = node->nodes;
	if (!arr)
		return (height);
	i = -1;
	while (arr[++i])
		max = ft_max(max, go_deeper(arr[i], height + 1));
	return (max);
}

int height_tree(struct s_node *root)
{
	if (!root)
		return (-1);
	return (go_deeper(root, 0));
}
