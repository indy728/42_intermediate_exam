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

void	print_tree(struct s_node *root)
{
	if (root)
	{
		print_tree(root->left);
		printf("%d ", root->value);
		print_tree(root->right);
	}
}

void	print_list_n(struct s_node *root, int n)
{
	struct s_node	*tmp = root;
	int				i = 0;

	printf(BOLD"Printing circular list %d times: \n"RESET, n);
	while (tmp && i < n)
	{
		printf(CYAN"%d "RESET, tmp->value);
		tmp = tmp->right;
		if (tmp == root)
			++i;
	}
	printf("\n");
}

void	insert(struct s_node **root, struct s_node *new)
{
	if (!*root)
		*root = new;
	else
	{
		int value = (*root)->value - new->value;
		
		if (value > 0)
			insert(&(*root)->left, new);
		else
			insert(&(*root)->right, new);
	}
}

struct s_node	*convert_bst(struct s_node *bst);

int main()
{
	struct s_node	*root = create_node(4);
	struct s_node	*tmp = root;
	struct s_node	*split;

	insert(&root, create_node(2));
	insert(&root, create_node(6));
	insert(&root, create_node(1));
	insert(&root, create_node(3));
	insert(&root, create_node(5));
	insert(&root, create_node(7));
	insert(&root, create_node(8));
	insert(&root, create_node(10));
	insert(&root, create_node(9));

	printf(BOLD"In order tree:\n"RESET""MAGENTA);
	print_tree(root);
	printf("\n"RESET);
	print_list_n(convert_bst(root), 10);
}
