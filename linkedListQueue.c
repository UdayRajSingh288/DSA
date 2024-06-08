#include <stdio.h>

typedef struct Node {
	int val;
	struct Node *next;
} Node;

typedef struct Queue {
	Node *head_node;
	Node *tail_node;
	int count;
	int length;
} Queue;

static void enqueue(Queue *queue, Node *node){
	if (queue->count == queue->length){
		printf("\nOverflow!\n");
	}
	else {
		(queue->count)++;
		node->next = NULL;
		if (queue->tail_node){
			(queue->tail_node)->next = node;
			queue->tail_node = node;
		}
		else {
			queue->head_node = node;
			queue->tail_node = node;
		}
	}
	return;
}

static int dequeue(Queue *queue){
	int val;
	if (queue->head_node){
		val = (queue->head_node)->val;
		if (queue->head_node == queue->tail_node){
			queue->head_node = NULL;
			queue->tail_node = NULL;
			queue->count = 0;
		}
		else {
			(queue->count)--;
			queue->head_node = (queue->head_node)->next;
		}
	}
	else {
		val = 0xDEAF;
		printf("\nUnderflow!\n");
	}
	return val;
}

int main(){
	Queue new_queue;
	Node node1, node2, node3;
	new_queue.head_node = NULL;
	new_queue.tail_node = NULL;
	new_queue.count = 0;
	new_queue.length = 10;
	node1.val = 3636;
	node2.val = 7789;
	node3.val = 4561;
	enqueue(&new_queue, &node1);
	enqueue(&new_queue, &node2);
	enqueue(&new_queue, &node3);
	printf("%d\n", dequeue(&new_queue));
	printf("%d\n", dequeue(&new_queue));
	printf("%d\n", dequeue(&new_queue));
	return 0;
}
