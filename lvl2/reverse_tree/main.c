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
	struct s_node	*right;
	struct s_node	*left;
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

void	reverse_tree(struct s_node *root);

int main()
{
	struct s_node	*root = create_node(92);
	struct s_node	*tmp = root;
	struct s_node	*split;
	
	tmp->left = create_node(85);
	tmp = tmp->left;
	tmp->left = create_node(79);
	tmp = tmp->left;
	tmp->right = create_node(10);
	tmp = tmp->right;
	tmp->left = create_node(39);
	tmp = tmp->left;
	tmp->left = create_node(35);
	tmp = tmp->left;
	tmp->left = create_node(96);

	tmp = root;
	tmp->right = create_node(26);
	tmp = tmp->right;
	tmp->right = create_node(64);
	split = tmp->right;
	split->left = create_node(40);
	split->right = create_node(78);
	
	tmp = split->right;
	tmp->right = create_node(85);
	tmp->left = create_node(2);
	tmp->right->right = create_node(51);
	tmp = tmp->left;
	tmp->left = create_node(33);
	tmp->left->right = create_node(55);
	tmp->right = create_node(11);
	tmp->right->left = create_node(99);

	split = split->left;
	split->left = create_node(88);
	split->right = create_node(10);
	
	tmp = split->left;
	tmp->left = create_node(12);
	tmp->left->left = create_node(58);
	tmp->right = create_node(55);
	tmp = tmp->right;
	tmp->left = create_node(58);
	tmp->right = create_node(41);
	
	tmp = split->right;
	tmp->left = create_node(52);
	tmp->right = create_node(87);
	tmp->right->right = create_node(31);
	tmp = tmp->left;
	tmp->left = create_node(22);
	tmp->right = create_node(35);


	printf(BOLD"BIG TREE:\n"RESET""MAGENTA);
	print_tree(root);
	printf("\n"RESET);
	printf(BOLD"REVERSE:\n"RESET""CYAN);
	reverse_tree(root);
	print_tree(root);
	printf("\n"RESET);

}
