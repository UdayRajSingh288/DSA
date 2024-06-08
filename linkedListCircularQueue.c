#include <stdio.h>

typedef struct Node {
	int val;
	struct Node *next;
} Node;

typedef struct CircularQueue {
	Node *headNode;
	Node *tailNode;
	int fillCount;
	int length;
}
