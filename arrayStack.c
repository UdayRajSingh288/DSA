#include <stdio.h>

typedef struct Stack {
	int *arr;
	int top;
	int height;
} Stack;

static void push(Stack *stack, int val){
	if (stack->top == stack->height){
		printf("\nOverflow!\n");
	}
	else {
		stack->arr[stack->top] = val;
		(stack->top)++;
	}
	return;
}

static int pop(Stack *stack){
	int val;
	if (stack->top){
		(stack->top)--;
		val = stack->arr[stack->top];
	}
	else {
		val = 0xDEAF;
		printf("\nUnderflow!\n");
	}
	return val;
}

#define peek(stack) ((stack)->arr[(stack)->top - 1])

int main(){
	int arr[10];
	Stack new_stack;
	new_stack.arr = arr;
	new_stack.top = 0;
	new_stack.height = 10;
	push(&new_stack, 1543);
	printf("%d\n", peek(&new_stack));
	push(&new_stack, 6789);
	printf("%d\n", pop(&new_stack));
	return 0;
}
