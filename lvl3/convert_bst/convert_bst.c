#include <stdlib.h>

typedef struct		s_node {
	int           	value;
	struct s_node 	*right;
	struct s_node 	*left;
}					t_node;
 
t_node	*to_list(t_node *root)
{
    // Base case
    if (!root)
        return root;
 
    // Convert the left subtree and link to root
    if (root->left)
    {
        t_node *left = to_list(root->left);
		while(left->right)
			left = left->right;
        left->right = root;
        root->left = left;
    }
    // Convert the right subtree and link to root
    if (root->right)
    {
        t_node *right = to_list(root->right);
		while (right->left)
			right = right->left;
        right->left = root;
        root->right = right;
    }
    return root;
}
 
struct s_node	*convert_bst(struct s_node *root)
{
	t_node	*end;

    if (!root)
        return root;
    root = to_list(root);
	end = root;
    while (root->left)
        root = root->left;
	while (end->right)
		end = end->right;
	end->right = root;
	root->left = end;
    return (root);
} 
