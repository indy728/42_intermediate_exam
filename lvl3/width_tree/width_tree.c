struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};


int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}

/*The second parameter is to store the height of tree.
   Initially, we need to pass a pointer to a location with value
   as 0. So, function should be used as follows:
 
   int height = 0;
   struct node *root = SomeFunctionToMakeTree();
   int width = widthOpt(root, &height); */

int max_width(struct s_node *root, int *height)
{
/* lh --> Height of left subtree
 rh --> Height of right subtree */
	int lh = 0;
	int	rh = 0;

/* lwidth  --> width of left subtree
 rwidth  --> width of right subtree */
	int	lwidth = 0;
	int	rwidth = 0;
  
	if(!root)
	{
		*height = 0;
		 return (0);
	}

/* Get the heights of left and right subtrees in lh and rh
And store the returned values in lwidth and lwidth */
	lwidth = max_width(root->left, &lh);
	rwidth = max_width(root->right, &rh);

/* Height of current node is max of heights of left and
 right subtrees plus 1*/
	*height = ft_max(lh, rh) + 1;

	return ft_max(lh + rh + 1, ft_max(lwidth, rwidth));
}

int	width_tree(struct s_node *node)
{
	int	height = 0;

	return (max_width(node, &height));
}
