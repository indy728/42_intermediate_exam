#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct s_node {
	int				value;
	struct s_node	**nodes;
};

struct s_node	*create_node(int value)
{
	struct s_node	*new = (struct s_node *)malloc(sizeof(struct s_node));
	new->value = value;
	new->nodes = NULL;
	return (new);
}

int	height_tree(struct s_node *root);

int main()
{
	printf("Test 0: root = NULL: %d\n", height_tree(NULL));

	struct s_node	*root1 = create_node(42);
	printf("Test 1: just the root: %d\n", height_tree(root1));

	struct s_node	*root2 = create_node(2);
	root2->nodes = malloc(sizeof(struct s_node *) * 3);
	struct s_node	*r1 = create_node(2);
	struct s_node	*r2 = create_node(2);
	struct s_node	*l1 = create_node(2);
	root2->nodes[2] = NULL;
	root2->nodes[1] = r1;
	root2->nodes[0] = l1;
	r1->nodes = malloc(sizeof(struct s_node *) * 2);
	r1->nodes[1] = NULL;
	r1->nodes[0] = r2;
	printf("Test 2: one left, two right: %d\n", height_tree(root2));
	

	return (0);
}
