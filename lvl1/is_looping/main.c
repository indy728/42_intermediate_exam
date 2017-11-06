#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
	int				value;
	struct s_node	*next;
};

int	is_looping(struct s_node *node);

struct s_node	*create_node(int value)
{
	struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
	new->value = value;
	new->next = NULL;
	return (new);
}

int main()
{
	struct s_node *root;
	struct s_node *tmp;
	struct s_node *loop;
	int				il;

	root = create_node(1);
	root->next = create_node(2);
	tmp = root->next;
	tmp->next = create_node(3);
	tmp = tmp->next;
	loop = tmp;
	tmp->next = create_node(4);
	tmp = tmp->next;
	tmp->next = create_node(5);
	tmp = tmp->next;
	tmp->next = create_node(6);
	tmp = tmp->next;
	tmp->next = loop;

	il = is_looping(root);
	printf(BOLD"EXAMPLE 1:\n"RESET);
	printf(YELLOW"Expected: "BOLD"1\n"RESET);
	printf("%sOutput: "BOLD"%d\n"RESET, il ? GREEN : RED, il);
	
	root->value = 12;
	loop = root->next;
	loop->value = 150;
	tmp = loop->next;
	tmp->value = 30;
	tmp = tmp->next;
	tmp->value = 50;
	tmp = tmp->next;
	tmp->value = 345;
	tmp = tmp->next;
	tmp->value = 120;
	tmp->next = create_node(200);
	tmp->next->next = loop;

	il = is_looping(root);
	printf(BOLD"EXAMPLE 2:\n"RESET);
	printf(YELLOW"Expected: "BOLD"1\n"RESET);
	printf("%sOutput: "BOLD"%d\n"RESET, il ? GREEN : RED, il);
	
	tmp->next = NULL;

	il = is_looping(root);
	printf(BOLD"EXAMPLE 3:\n"RESET);
	printf(YELLOW"Expected: "BOLD"0\n"RESET);
	printf("%sOutput: "BOLD"%d\n"RESET, il ? RED : GREEN, il);
	
	loop->next->value = 14;
	loop->next->next = loop->next;

	il = is_looping(root);
	printf(BOLD"EXAMPLE 4:\n"RESET);
	printf(YELLOW"Expected: "BOLD"1\n"RESET);
	printf("%sOutput: "BOLD"%d\n"RESET, il ? GREEN : RED, il);
	
}
