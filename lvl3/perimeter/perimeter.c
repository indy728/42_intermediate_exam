#include <stdio.h>

struct s_node {
	int 			value;
	struct s_node	*right;
	struct s_node	*left;
};

void	print_left(struct s_node *root)
{
	if (root)
	{
		if (root->left || root->right)
		{
			printf(" %d", root->value);
			print_left(root->left);
		}
	}
}

void	print_right(struct s_node *root)
{
	if (root)
	{
		if (root->left || root->right)
		{
			print_right(root->right);
			printf(" %d", root->value);
		}
	}
}

void	print_bottom(struct s_node *root)
{
	if (root)
	{
		print_bottom(root->left);
		if (!root->left && !root->right)
			printf(" %d", root->value);
		print_bottom(root->right);
	}
}

void	perimeter(struct s_node *root)
{
	if (!root)
	{
		printf("\n");
		return ;
	}
	printf("%d", root->value);
	print_left(root->left);
	print_bottom(root->left);
	print_bottom(root->right);
	print_right(root->right);
	printf("\n");
}
