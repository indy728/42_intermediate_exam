#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct s_node
{
	int				value;
	struct s_node	**next;
};

void	fill_nodes(struct s_node *x)
{
	int i = -1;

	while (x->next[++i])
	{

	}
}

int main()
{
	struct s_node	*top = (struct s_node *)malloc(sizeof(struct s_node));

	top->value = 1;
	top->next = (struct s_node **)malloc(sizeof(struct s_node *) * 4);
	top->next[3] = NULL;
	fill_nodes(top);

}
