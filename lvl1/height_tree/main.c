#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define RESET "\x1b[0m"

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
	int ans;
	ans = height_tree(NULL);
	printf("Test 0: root = NULL: %s%d"RESET"\n", ans == -1 ? GREEN : RED, ans);

	struct s_node	*root1 = create_node(42);
	ans = height_tree(root1);
	printf("Test 1: just the root: %s%d"RESET"\n", ans == 0 ? GREEN : RED, ans);

	struct s_node	*root2 = create_node(2);
	root2->nodes = malloc(sizeof(struct s_node *) * 3);
	struct s_node	*r1 = create_node(52);
	struct s_node	*r2 = create_node(11);
	struct s_node	*l1 = create_node(34);
	root2->nodes[2] = NULL;
	root2->nodes[1] = r1;
	root2->nodes[0] = l1;
	r1->nodes = malloc(sizeof(struct s_node *) * 2);
	r1->nodes[1] = NULL;
	r1->nodes[0] = r2;
	ans = height_tree(root2);
	printf("Test 2: one left, two right: %s%d"RESET"\n", ans == 2 ? GREEN : RED, ans);
	
	struct s_node	*r3 = create_node(13);
	struct s_node	*l2a = create_node(1);
	struct s_node	*l2b = create_node(99);
	r2->nodes = malloc(sizeof(struct s_node *) * 2);
	l1->nodes = malloc(sizeof(struct s_node *) * 3);
	r2->nodes[1] = NULL;
	r2->nodes[0] = r3;
	l1->nodes[2] = NULL;
	l1->nodes[1] = l2b;
	l1->nodes[0] = l2a;
	ans = height_tree(root2);
	printf("Test 3: example tree: %s%d"RESET"\n", ans == 3 ? GREEN : RED, ans);
	
	return (0);
}
