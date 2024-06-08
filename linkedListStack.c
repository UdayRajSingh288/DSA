#include <stdio.h>

typedef struct Node {
	int val;
	struct Node *next;
} Node;

typedef struct Stack {
	int top;
	int height;
	Node *top_node;
} Stack;

static void push(Stack *stack, Node *node){
	if (stack->top == stack->height){
		printf("\nOverflow!\n");
	}
	else {
		node->next = stack->top_node;
		stack->top_node = node;
		(stack->top)++;
	}
	return;
}

static int pop(Stack *stack){
	int val;
	if (stack->top){
		(stack->top)--;
		val = (stack->top_node)->val;
		stack->top_node = (stack->top_node)->next;
	}
	else {
		val = 0xDEAF;
		printf("\nUnderflow!\n");
	}
	return val;
}

#define peek(stack) (((stack)->top_node)->val)

int main(){
	Stack new_stack;
	Node node1, node2, node3;
	new_stack.top = 0;
	new_stack.height = 10;
	new_stack.top_node = NULL;
	node1.val = 2346;
	node2.val = 7762;
	node3.val = 9765;
	push(&new_stack, &node1);
	printf("%d\n", peek(&new_stack));
	push(&new_stack, &node2);
	printf("%d\n", peek(&new_stack));
	push(&new_stack, &node3);
	printf("%d\n", pop(&new_stack));
	return 0;
}
