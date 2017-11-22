typedef struct		s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

void	count_nodes(t_node *root, int *nodes)
{
	if (root)
	{
		*nodes++;
		count_nodes(root->left);
		count_nodes(root->right);
	}
}

int	splittable(t_node *root, int nodes, int sub, int *spl)
{
	if (!root)
		return (0);
	else
	{
		splittable(root->left, nodes - 1, sub + 1, spl);
		splittable(root->right, nodes - 1, sub + 1, spl);

	}

}

int	can_split(struct s_node *root)
{
	int		spl = 0;
	int		nodes = 0;

	if (!root)
		return (0);
	count_nodes(root, &nodes);
	if (nodes % 2)
		return (0);
	splittable(root, nodes, sub, &spl);
	return (spl ? 1 : 0);
}
