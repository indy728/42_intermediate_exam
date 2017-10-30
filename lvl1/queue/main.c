#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define RESET "\x1b[0m"

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue *init(void);
void *dequeue(struct s_queue *queue);
void enqueue(struct s_queue *queue, void *content);
void *peek(struct s_queue *queue);
int isEmpty(struct s_queue *queue);

int main()
{
	struct s_queue	*queue = NULL;

	printf("Initializing queue.");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".\n");
	queue = init();
	printf("Is the queue empty? %s\n", isEmpty(queue) ? "YES" : "NO");
	sleep(2);
	printf("enqueueing to queue: content = 'a'\n");
	enqueue(queue, strdup("a"));
	sleep(1);
	printf("Is the queue empty? %s\n", isEmpty(queue) ? "YES" : "NO");
	sleep(2);
	printf("Peek the top: %s\n", isEmpty(queue) ? "NULL" : (char *)peek(queue));
	sleep(2);
	printf("enqueueing to queue: content = 'b'\n");
	enqueue(queue, strdup("b"));
	sleep(1);
	printf("enqueueing to queue: content = 'c'\n");
	enqueue(queue, strdup("c"));
	sleep(1);
	printf("enqueueing to queue: content = 'd'\n");
	enqueue(queue, strdup("d"));
	sleep(1);
	printf("enqueueing to queue: content = 'e'\n");
	enqueue(queue, strdup("e"));
	sleep(1);
	printf("enqueueing to queue: content = 'f'\n");
	enqueue(queue, strdup("f"));
	sleep(2);
	printf("Peek the top: %s\n", isEmpty(queue) ? "NULL" : (char *)peek(queue));
	sleep(2);
	printf("dequeueing element from queue: %s\n", (char *)dequeue(queue));
	sleep(1);
	printf("dequeueing element from queue: %s\n", (char *)dequeue(queue));
	sleep(1);
	printf("dequeueing element from queue: %s\n", (char *)dequeue(queue));
	sleep(1);
	printf("Is the queue empty? %s\n", isEmpty(queue) ? "YES" : "NO");
	sleep(2);
	printf("Peek the top: %s\n", isEmpty(queue) ? "NULL" : (char *)peek(queue));
	sleep(2);
	printf("dequeueing element from queue: %s\n", (char *)dequeue(queue));
	sleep(1);
	printf("dequeueing element from queue: %s\n", (char *)dequeue(queue));
	sleep(1);
	printf("dequeueing element from queue: %s\n", (char *)dequeue(queue));
	sleep(1);
	printf("Is the queue empty? %s\n", isEmpty(queue) ? "YES" : "NO");
	sleep(2);
	printf("Peek the top: %s\n", isEmpty(queue) ? "NULL" : (char *)peek(queue));
	sleep(2);
	printf("COMPLETE\n");
}
