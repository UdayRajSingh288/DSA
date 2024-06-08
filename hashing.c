#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
} Node;

static void insert(Node *nodes_arr, int val){
	Node *new_node;
	int rem;
	rem = val % 10;
	if (nodes_arr[rem].val == -1){
		nodes_arr[rem].val = val;
		printf("%d stored at home node!\n", val);
	}
	else {
		new_node = (Node *)malloc(sizeof(Node));
		new_node->val = val;
		new_node->next = nodes_arr[rem].next;
		nodes_arr[rem].next = new_node;
		printf("%d stored in chain!\n", val);
	}
	return;
}

static void cleanup(Node *nodes_arr){
	int i;
	Node *ptr1, *ptr2;
	for (i = 0; i < 10; i++){
		ptr1 = nodes_arr[i].next;
		while (ptr1){
			ptr2 = ptr1->next;
			free(ptr1);
			ptr1 = ptr2;
		}
	}
	return;
}

int main(){
	Node nodes_arr[10];
	int i;
	for (i = 0; i < 10; i++){
		nodes_arr[i].val = -1;
		nodes_arr[i].next = NULL;
	}
	insert(nodes_arr, 89);
	insert(nodes_arr, 87);
	insert(nodes_arr, 88);
	insert(nodes_arr, 69);
	insert(nodes_arr, 66);
	insert(nodes_arr, 78);
	insert(nodes_arr, 68);
	insert(nodes_arr, 55);
	cleanup(nodes_arr);
	return 0;
}
