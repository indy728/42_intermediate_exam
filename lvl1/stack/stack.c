#include <stdlib.h>
#include <unistd.h> //////////////////

struct s_node
{
	void			*content;
	struct s_node	*next;
};

struct s_stack
{
	struct s_node	*top;
};

int				isEmpty(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}

struct s_stack	*init(void)
{
	struct s_stack	*new = (struct s_stack *)malloc(sizeof(struct s_stack));
	new->top = NULL;
	return (new);
}

void			*pop(struct s_stack *stack)
{
	struct s_node	*node;
	void			*content;
	
	if (isEmpty(stack))
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	content = node->content;
	free(node);
	return (content);
}

void			push(struct s_stack *stack, void *content)
{
	struct s_node	*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void			*peek(struct s_stack *stack)
{
	if (isEmpty(stack))
		return (NULL);
	return (stack->top->content);
}
