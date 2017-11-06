struct s_node
{
	int				value;
	struct s_node	*next;
};

int	is_looping(struct s_node *node)
{
	if (!node)
		return (0);

	struct s_node	*slow = node;
	struct s_node	*fast = node->next;

	while (slow && fast && fast->next)
	{
		if (slow == fast)
			return (1);
		fast = fast->next->next;
		slow = slow->next;
	}
	return (0);
}
