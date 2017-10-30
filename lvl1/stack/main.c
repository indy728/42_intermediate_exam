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

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void);
void *pop(struct s_stack *stack);
void push(struct s_stack *stack, void *content);
void *peek(struct s_stack *stack);
int isEmpty(struct s_stack *stack);

int main()
{
	struct s_stack	*stack = NULL;

	printf("Initializing stack.");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".\n");
	stack = init();
	printf("Is the stack empty? %s\n", isEmpty(stack) ? "YES" : "NO");
	sleep(2);
	printf("Pushing to stack: content = 'a'\n");
	push(stack, strdup("a"));
	sleep(1);
	printf("Is the stack empty? %s\n", isEmpty(stack) ? "YES" : "NO");
	sleep(2);
	printf("Peek the top: %s\n", isEmpty(stack) ? "NULL" : (char *)peek(stack));
	sleep(2);
	printf("Pushing to stack: content = 'b'\n");
	push(stack, strdup("b"));
	sleep(1);
	printf("Pushing to stack: content = 'c'\n");
	push(stack, strdup("c"));
	sleep(1);
	printf("Pushing to stack: content = 'd'\n");
	push(stack, strdup("d"));
	sleep(1);
	printf("Pushing to stack: content = 'e'\n");
	push(stack, strdup("e"));
	sleep(1);
	printf("Pushing to stack: content = 'f'\n");
	push(stack, strdup("f"));
	sleep(2);
	printf("Peek the top: %s\n", isEmpty(stack) ? "NULL" : (char *)peek(stack));
	sleep(2);
	printf("Popping element from stack: %s\n", (char *)pop(stack));
	sleep(1);
	printf("Popping element from stack: %s\n", (char *)pop(stack));
	sleep(1);
	printf("Popping element from stack: %s\n", (char *)pop(stack));
	sleep(1);
	printf("Is the stack empty? %s\n", isEmpty(stack) ? "YES" : "NO");
	sleep(2);
	printf("Peek the top: %s\n", isEmpty(stack) ? "NULL" : (char *)peek(stack));
	sleep(2);
	printf("Popping element from stack: %s\n", (char *)pop(stack));
	sleep(1);
	printf("Popping element from stack: %s\n", (char *)pop(stack));
	sleep(1);
	printf("Popping element from stack: %s\n", (char *)pop(stack));
	sleep(1);
	printf("Is the stack empty? %s\n", isEmpty(stack) ? "YES" : "NO");
	sleep(2);
	printf("Peek the top: %s\n", isEmpty(stack) ? "NULL" : (char *)peek(stack));
	sleep(2);
	printf("COMPLETE\n");
}
