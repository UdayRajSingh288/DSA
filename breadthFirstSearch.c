#include <stdio.h>

static int graph[7][7] = {{0, 1, 1, 1, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0},
			{1, 1, 0, 0, 1, 1, 0}, {1, 1, 0, 0, 1, 1, 0},
			{0, 0, 1, 1, 0, 1, 1}, {0, 0, 1, 1, 1, 0, 1},
			{0, 0, 0, 0, 1, 1, 0}};
#define VERTICES_COUNT 7

static int colourNode(int queue[], int queueFillCount, int nodeLabel){
	int i;
	for (i = 0; i < queueFillCount; i++){
		if (queue[i] == nodeLabel){
			return 0;
		}
	}
	queue[i] = nodeLabel;
	return 1;
}

static void breadthFirstSearch(int graph[][VERTICES_COUNT], int spanningTree[][2]){
	/* A notable quirk: the output of this function is stored in
	 * the array 'spanningTree[][]', which is taken as an argument
	 * beacuse otherwise the output would have to be stored in a
	 * dynamic array, or a static array both of which are not to
	 * my taste
	 * dynamic array would require me to free it after use and a
	 * static array would take space and increase core size
	 * */
	int queueHead, queueTail, i, j;
	int queue[VERTICES_COUNT];
	queueHead = 0;
	queueTail = 1; /* Initialising variables for queue operations */
	i = 0; /* Initially selecting the first node given as a row in 2D array */
	queue[0] = 0; /* Colouring the initially selected node */
	while (queueTail < VERTICES_COUNT){
		for (j = 0; j < VERTICES_COUNT; j++){
			if (graph[i][j]){ /* If there exists an edges between i and j */
				if (colourNode(queue, queueTail, j)){ /* If node j was not coloured before node then colour it */
					spanningTree[queueTail - 1][0] = i;
					spanningTree[queueTail - 1][1] = j; /* Also add the edge between i and j to the spanning tree */
					queueTail++;
				}
			}
		}
		queueHead++; /* Discarding the last selected node */
		i = queue[queueHead];
	}
}

int main(){
	int i;
	int arr[VERTICES_COUNT - 1][2];
	breadthFirstSearch(graph, arr);
	for (i = 0; i < VERTICES_COUNT - 1; i++){
		printf("(%d, %d)\n", arr[i][0], arr[i][1]);
	}
	return 0;
}
