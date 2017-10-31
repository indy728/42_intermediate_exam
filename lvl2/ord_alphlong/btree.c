#include "ord_alphlong.h"

void	insert(t_tree **root, t_tree *new)
{
	if (!*root)
		*root = new;
	else
	{
		int value = get_value((*root)->str, new->str);
		
		if (value < 0)
			insert(&(*root)->left, new);
		else
			insert(&(*root)->right, new);
	}
}

void	print_tree(t_tree *root)
{
	if (root)
	{
		print_tree(root->left);
		if (g)
			ft_putstr(" ");
		ft_putstr(root->str);
		g++;
		print_tree(root->right);
	}
}

void	destroy_tree(t_tree *root)
{
	if (root)
	{
		destroy_tree(root->left);
		destroy_tree(root->right);
		free(root->str);
		free(root);
	}
}

t_tree	*create_node(char *str, int i)
{
	t_tree	*new = (t_tree *)malloc(sizeof(t_tree));
	new->str = oa_strdup(str, i);
	new->left = NULL;
	new->right = NULL;
	return (new);
}
