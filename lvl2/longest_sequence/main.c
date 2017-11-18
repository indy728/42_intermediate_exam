#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define BBLACK "\x1b[40m"
# define BRED "\x1b[41m"
# define BGREEN "\x1b[42m"
# define BYELLOW "\x1b[43m"
# define BBLUE "\x1b[44m"
# define BMAGENTA "\x1b[45m"
# define BCYAN "\x1b[46m"
# define BWHITE "\x1b[47m"
# define RESET "\x1b[0m"
# define CLEAR "\033c"
# define BOLD "\033[1m"

typedef struct 		s_node
{
	int value;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

struct s_node	*create_node(int value)
{
	struct s_node	*new = (struct s_node *)malloc(sizeof(struct s_node));
	new->value = value;
	new->right = NULL;
	new->left = NULL;
	return (new);
}

void	print_tree(t_node *root)
{
	if (root)
	{
		print_tree(root->left);
		printf("%d ", root->value);
		print_tree(root->right);
	}
}

int	longest_sequence(struct s_node *root);

int main()
{
	struct s_node	*root = create_node(10);
	struct s_node	*tmp = root;
	struct s_node	*split;
	int				ans;
	int				output;

	ans = 0;
	output = longest_sequence(NULL);
	printf(BOLD"NULL TEST\n"RESET""YELLOW"Expected: %d\n"GREEN"Output: %s%d\n", ans, output == ans ? GREEN : RED, output);
	ans = 1;
	output = longest_sequence(root);
	printf(BOLD"SINGLE NODE\n"RESET""YELLOW"Expected: %d\n"GREEN"Output: %s%d\n", ans, output == ans ? GREEN : RED, output);
	tmp->left = create_node(5);
	tmp = tmp->left;
	tmp->left = create_node(6);
	tmp->right = create_node(9);
	tmp->left->left = create_node(7);
	tmp->left->right = create_node(13);

	ans = 3;
	output = longest_sequence(root);
	printf(BOLD"EXAMPLE 1\n"RESET""YELLOW"Expected: %d\n"GREEN"Output: %s%d\n", ans, output == ans ? GREEN : RED, output);

	root->right = root->left;
	root->left = create_node(6);
	root->value = 5;
	tmp->value = 4;
	tmp->right->value = 3;
	tmp->right->right = create_node(2);
	tmp->left->value = 9;
	tmp->left->left->value = 3;
	tmp->left->right->value = 2;

	ans = 2;
	output = longest_sequence(root);
	printf(BOLD"EXAMPLE 2\n"RESET""YELLOW"Expected: %d\n"GREEN"Output: %s%d\n", ans, output == ans ? GREEN : RED, output);

	root->value = 30;
	root->left->value = 15;
	root->left->left = create_node(61);
	root->right = create_node(40);
	tmp = root->right;
	tmp->left = create_node(80);
	
	ans = 1;
	output = longest_sequence(root);
	printf(BOLD"EXAMPLE 3\n"RESET""YELLOW"Expected: %d\n"GREEN"Output: %s%d\n", ans, output == ans ? GREEN : RED, output);

	root->right = create_node(1);
	root->left = create_node(31);
	tmp = root->left;
	tmp->left = create_node(32);
	tmp->right = create_node(99);
	tmp = tmp->left;
	tmp->left = create_node(42);
	tmp->right = create_node(33);
	tmp = tmp->right;
	tmp->left = create_node(34);
	tmp->right = create_node(34);
	tmp = tmp->left;
	tmp->left = create_node(33);
	tmp->right = create_node(35);
	tmp = tmp->right;
	tmp->left = create_node(12);
	tmp->right = create_node(36);
	tmp->right->left = create_node(37);

	tmp = root->right;
	tmp->left = create_node(3);
	tmp->right = create_node(2);
	tmp = tmp->right;
	tmp->left = create_node(3);
	tmp->right = create_node(69);
	tmp = tmp->left;
	tmp->left = create_node(4);
	tmp->right = create_node(4);
	tmp = tmp->left;
	tmp->left = create_node(5);
	tmp->right = create_node(35);
	tmp = tmp->left;
	tmp->left = create_node(132);
	tmp->right = create_node(6);
	tmp = tmp->right;
	tmp->left = create_node(6);
	tmp->right = create_node(7);
	tmp->right->right = create_node(8);
	tmp->right->right->left = create_node(9);

	ans = 9;
	output = longest_sequence(root);
	printf(BOLD"BIG & WIDE\n"RESET""YELLOW"Expected: %d\n"GREEN"Output: %s%d\n", ans, output == ans ? GREEN : RED, output);
}
