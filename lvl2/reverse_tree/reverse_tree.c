struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

/*	This is a simple problem designed I think just to test
	understanding of BST data structure and recursion. The
	solution goes all the way to the bottom of the tree on
	each side, swaps the left and right nodes, and then 
	executes the swap back up the tree.*/

void reverse_tree(struct s_node *root)
{
	if (root)
	{
		struct s_node	*tmp;

		reverse_tree(root->left);
		reverse_tree(root->right);
		tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}
}

/*	The order does not matter. The solution below will
	also work: 

void reverse_tree(struct s_node *root)
{
	if (root)
	{
		struct s_node	*tmp;

		tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		reverse_tree(root->left);
		reverse_tree(root->right);
	}
} */
