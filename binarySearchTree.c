#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int numVal;
	struct Node *leftChild;
	struct Node *rightChild;
} Node;

static void addNode(Node **, int);
static void deleteTree(Node *);
static void deleteNode(Node **, int);
static Node *reassignNode(Node *);
static void inOrderTraversal(Node *);

int main(){
	int choice, numVal;
	Node *root;
	root = NULL;
	while (1){
		printf("\n1. ADD NODE\n2. DELETE NODE\n3. IN ORDER TRAVERSAL\n4. EXIT\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter the number: ");
				scanf("%d", &numVal);
				addNode(&root, numVal);
				break;
			case 2:
				printf("\nEnter the number: ");
				scanf("%d", &numVal);
				deleteNode(&root, numVal);
				break;
			case 3:
				inOrderTraversal(root);
				break;
			case 4:
				deleteTree(root);
				return 0;
			default:
				printf("\nINVALID INPUT!\n");
		}
	}
}

static void addNode(Node **root, int numVal){
	Node *newNode, *ptr1, *ptr2;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->numVal = numVal;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	if (*root){
		ptr1 = *root;
		while (ptr1){
			ptr2 = ptr1;
			if (ptr1->numVal > newNode->numVal){
				ptr1 = ptr1->leftChild;
			}
			else {
				ptr1 = ptr1->rightChild;
			}
		}
		if (ptr2->numVal > newNode->numVal){
			ptr2->leftChild = newNode;
		}
		else {
			ptr2->rightChild = newNode;
		}
	}
	else {
		*root = newNode;
	}
	return;
}

static void deleteTree(Node *ptr){
	if (ptr){
		deleteTree(ptr->leftChild);
		deleteTree(ptr->rightChild);
		free(ptr);
	}
	return;
}

static void deleteNode(Node **root, int numVal){
	Node *ptr1, *ptr2;
	ptr1 = *root;
	ptr2 = NULL;
	while (ptr1){
		if (numVal < ptr1->numVal){
			ptr2 = ptr1;
			ptr1 = ptr1->leftChild;
		}
		else if (numVal > ptr1->numVal){
			ptr2 = ptr1;
			ptr1 = ptr1->rightChild;
		}
		else {
			break;
		}
	}
	if (ptr1){
		if (!ptr2){
			*root = reassignNode(ptr1);
		}
		else {
			if (ptr2->leftChild == ptr1){
				ptr2->leftChild = reassignNode(ptr1);
			}
			else {
				ptr2->rightChild = reassignNode(ptr1);
			}
		}
		free(ptr1);
	}
	return;
}

/*
static Node *reassignNode(Node *curNode){
	if (curNode->leftChild && curNode->rightChild){
		(curNode->leftChild)->leftChild = reassignNode(curNode->leftChild);
		(curNode->leftChild)->rightChild = curNode->rightChild;
		return curNode->leftChild;
	}
	else if (curNode->leftChild){
		return curNode->leftChild;
	}
	else if (curNode->rightChild){
		return curNode->rightChild;
	}
	else {
		return NULL;
	}
}
*/

static void inOrderTraversal(Node *ptr){
	if (ptr){
		inOrderTraversal(ptr->leftChild);
		printf("%d ", ptr->numVal);
		inOrderTraversal(ptr->rightChild);
	}
	return;
}
