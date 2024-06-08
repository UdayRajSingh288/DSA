#include <stdio.h>

typedef struct CircularQueue {
	int *arr;
	int head;
	int tail;
	int length;
	int fillCount;
} CircularQueue;

static void enqueue(CircularQueue *circularQueue, int val){
	if (circularQueue->fillCount == circularQueue->length){
		printf("\nOverflow!\n");
	}
	else {
		(circularQueue->fillCount)++;
		circularQueue->arr[circularQueue->tail] = val;
		if (circularQueue->tail == circularQueue->length - 1){
			circularQueue->tail = 0;
		}
		else {
			(circularQueue->tail)++;
		}
	}
	return;
}

static int dequeue(CircularQueue *circularQueue){
	int val;
	if (circularQueue->fillCount){
		(circularQueue->fillCount)--;
		val = circularQueue->arr[circularQueue->head];
		if (circularQueue->head == circularQueue->length - 1){
			circularQueue->head = 0;
		}
		else {
			(circularQueue->head)++;
		}
	}
	else {
		printf("\nUnderflow!\n");
	}
	return val;
}

int main(){
	int arr[10];
	CircularQueue circularQueue;
	circularQueue.arr = arr;
	circularQueue.length = 10;
	circularQueue.head = 0;
	circularQueue.tail = 0;
	circularQueue.fillCount = 0;
	enqueue(&circularQueue, 7896);
	enqueue(&circularQueue, 8879);
	printf("%d\n", dequeue(&circularQueue));
	printf("%d\n", dequeue(&circularQueue));
	return 0;
}
