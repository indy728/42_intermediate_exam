#include <stdlib.h>

typedef struct		s_node 
{
	int           	data;
	struct s_node	*next;
	struct s_node	*other;
}					t_node;

static t_node	*duplicate_list(t_node *node)
{
	t_node	*new = NULL;
	
	if (node)
	{
		new = (t_node *)malloc(sizeof(t_node));
		new->data = node->data + 1;
		new->other = NULL;
		new->next = duplicate_list(node->next);
	}
	return (new);
}

static void				set_other(t_node *new, t_node *old, t_node *other, t_node *set)
{
	while (old && !set->other)
	{
		if (old == other->other)
			set->other = new;
		new = new->next;
		old = old->next;
	}
}

t_node 			*clone_list(t_node *node)
{
	t_node	*dupe = duplicate_list(node);
	t_node	*old = node;
	t_node	*new = dupe;

	while (old)
	{
		if (old->other)
			set_other(dupe, node, old, new);
		old = old->next;
		new = new->next;
	}
	return (dupe);
}
