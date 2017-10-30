#include <stdlib.h>

struct s_node
{
	void			*content;
	struct s_node	*next;
};

struct s_queue
{
	struct s_node	*first;
	struct s_node	*last;
};

int				isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}

struct s_queue	*init(void)
{
	struct s_queue	*new = (struct s_queue *)malloc(sizeof(struct s_queue));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void			*dequeue(struct s_queue *queue)
{
	struct s_node	*node;
	void			*content;
	
	if (isEmpty(queue))
		return (NULL);
	node = queue->first;
	queue->first = node->next;
	if (!queue->first)
		queue->last = NULL;
	content = node->content;
	free(node);
	return (content);
}

void			enqueue(struct s_queue *queue, void *content)
{
	struct s_node	*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->content = content;
	new->next = NULL;
	if (queue->last)
		queue->last->next = new;
	else
		queue->first = new;
	queue->last = new;
}

void			*peek(struct s_queue *queue)
{
	if (isEmpty(queue))
		return (NULL);
	return (queue->first->content);
}
