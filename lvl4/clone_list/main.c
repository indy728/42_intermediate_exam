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
	int 			data;
	struct s_node	*next;
	struct s_node	*other;
};

static struct s_node	*create_node(int value)
{
	struct s_node	*new = (struct s_node *)malloc(sizeof(struct s_node));
	new->data = value;
	new->next = NULL;
	new->other = NULL;
	return (new);
}

struct s_node	*clone_list(struct s_node *node);

void			print_list(struct s_node *node)
{
	int	i = 0;
	while (node)
	{
		printf(MAGENTA"%s%d"RESET"/"CYAN, i++ ? " " : "",  node->data);
		if (node->other)
			printf("%d", node->other->data);
		else
			printf("(null)");
		printf(RESET);
		node = node->next;
	}
	printf("\n");
}

int main()
{
	struct s_node	*zero = create_node(89);
	struct s_node	*one = create_node(243);
	struct s_node	*two = create_node(993);
	struct s_node	*three = create_node(548);
	struct s_node	*four = create_node(624);
	struct s_node	*five = create_node(581);
	struct s_node	*six = create_node(210);
	struct s_node	*seven = create_node(361);
	struct s_node	*eight = create_node(653);
	struct s_node	*nine = create_node(42);

	printf(BOLD"NULL TEST:\n"RESET);
	printf(GREEN"Expected:\n");
	print_list(NULL);
	printf(RESET);
	printf(YELLOW"Output:\n");
	print_list(clone_list(NULL));
	printf(RESET"\n");
	
	printf(BOLD"ONE-NODE TEST:\n"RESET);
	printf(GREEN"Expected:\n");
	print_list(zero);
	printf(RESET);
	printf(YELLOW"Output:\n");
	print_list(clone_list(zero));
	printf(RESET"\n");

	zero->next = one;
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = six;
	six->next = seven;
	seven->next = eight;
	eight->next = nine;

	zero->other = one;
	one->other = five;
	two->other = one;
	four->other = four;
	five->other = nine;
	seven->other = three;
	nine->other = nine;

	printf(BOLD"TEN-NODE TEST:\n"RESET);
	printf(GREEN"Expected:\n");
	print_list(zero);
	printf(RESET);
	printf(YELLOW"Output:\n");
	print_list(clone_list(zero));
	printf(RESET"\n");

	return (0);
}
