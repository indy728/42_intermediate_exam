typedef struct		s_node
{
	int value;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}

/*	The variable names should make this pretty straightforward. Passing
	the address of 'n' to the recursive function allows the value of n 
	to be changed at any given time in the recursion since it's just 
	accessing memory. 'n' will never decrease and will never get larger 
	than the current sequence. */

void	penetrate_deep(t_node *last, t_node *this, int seq, int *n)
{
	if (this)
	{
		seq = (this->value - last->value == 1) ? seq + 1 : 1;
		*n = ft_max(*n, seq);
		penetrate_deep(this, this->left, seq, n);
		penetrate_deep(this, this->right, seq, n);
	}
}

int	longest_sequence(struct s_node *node)
{
	int	n = 1;

	if (!node)
		return (0);
	penetrate_deep(node, node->left, 1, &n);
	penetrate_deep(node, node->right, 1, &n);
	return (n);
}
