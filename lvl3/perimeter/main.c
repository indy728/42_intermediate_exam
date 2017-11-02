#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct s_node {
	int value;
	struct s_node	*right;
	struct s_node	*left;
};

struct s_node	*create_node(int value)
{
	struct s_node	*new = (struct s_node *)malloc(sizeof(struct s_node));
	new->value = value;
	new->right = NULL;
	new->left = NULL;
	return (new);
}

void	perimeter(struct s_node *root);

int main()
{
	struct s_node	*root = create_node(92);
	struct s_node	*tmp = root;
	struct s_node	*split;

	printf("NULL TEST: *NB: instructions unclear, should just a newline be printed?*\n");
	printf("Expected: v\n\n");
	printf("Output: v\n");
	perimeter(NULL);
	printf("SINGLE NODE:\n");
	printf("Expected: v\n92\n");
	printf("Output: v\n");
	perimeter(root);
}
