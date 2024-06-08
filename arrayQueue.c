#include <stdio.h>

typedef struct Queue {
	int *arr;
	int head;
	int tail;
	int length;
} Queue;

static void enqueue(Queue *queue, int val){
	if (queue->tail == queue->length){
		printf("\nOverflow!\n");
	}
	else {
		queue->arr[queue->tail] = val;
		(queue->tail)++;
	}
	return;
}

static int dequeue(Queue *queue){
	int val;
	if (queue->head < queue->tail){
		val = queue->arr[queue->head];
		(queue->head)++;
	}
	else {
		printf("\nUnderflow!\n");
		val = 0xDEAF;
	}
	return val;
}

int main(){
	int arr[10];
	Queue new_queue;
	new_queue.arr = arr;
	new_queue.head = 0;
	new_queue.tail = 0;
	new_queue.length = 10;
	enqueue(&new_queue, 8876);
	enqueue(&new_queue, 6543);
	enqueue(&new_queue, 6821);
	printf("%d\n", dequeue(&new_queue));
	printf("%d\n", dequeue(&new_queue));
	printf("%d\n", dequeue(&new_queue));
	return 0;
}
