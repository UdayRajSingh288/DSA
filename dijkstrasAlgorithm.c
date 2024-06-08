#include <stdio.h>

#define VERTICES_COUNT 8
#define INFINITY 0x7FFFFFFF

static int graph[][VERTICES_COUNT] = {{0, 12, 17, 15, 0, 0, 0, 0},
					{12, 0, 21, 0, 20, 0, 0, 0},
					{17, 21, 0, 14, 0, 24, 0, 0},
					{15, 0, 14, 0, 13, 19, 23, 22},
					{0, 20, 0, 13, 0, 0, 18, 0},
					{0, 0, 24, 19, 0, 0, 0, 0},
					{0, 0, 0, 23, 18, 0, 0, 16},
					{0, 0, 0, 22, 0, 0, 16, 0}}; /* adjacency matrix of the graph */

/*
static int previouslyNotSelected(int selectedVertices[], int fillCount, int vertex){
	int i;
	for (i = 0; i < fillCount; i++){
		if (selectedVertices[i] == vertex){
			return 0;
		}
	}
	return 1;
}
*/

static int colourVertex(int costArr[], int colouredVertices[], int fillCount){
	int i, selectedVertex, selectedVertexWeight;
	selectedVertexWeight = INFINITY;
	for (i = 0; i < VERTICES_COUNT; i++){
		if (!colouredVertices[i] && costArr[i] < selectedVertexWeight){
			selectedVertex = i;
			selectedVertexWeight = costArr[i];
		}
	}
	colouredVertices[selectedVertex] = 1; /* Colour the selected vertex */
	return selectedVertex;
}

static void dijkstrasAlgorithm(int graph[][VERTICES_COUNT], int minCostArr[]){
	int colouredVertices[VERTICES_COUNT] = {0};
	int colouredVerticesCount, selectedVertex, i;
	colouredVertices[0] = 1;
	colouredVerticesCount = 1;
	for (i = 0; i < VERTICES_COUNT; i++){
		if (i == 0){	/* If i is at the initially selected vertex */
			minCostArr[i] = 0;
		}
		else if (graph[0][i]){	/* If the currently selected vertex is connected to the initially selected vertex directly */
			minCostArr[i] = graph[0][i];
		}
		else {
			minCostArr[i] = INFINITY;
		}
	}
	while (colouredVerticesCount < VERTICES_COUNT){
		selectedVertex = colourVertex(minCostArr, colouredVertices, colouredVerticesCount);
		colouredVerticesCount++;
		for (i = 0; i < VERTICES_COUNT; i++){
			if (graph[selectedVertex][i] && (graph[selectedVertex][i] + minCostArr[selectedVertex]) < minCostArr[i]){ /* If an edge exists and the
																     combined cost of the selected
																     vertex and of the vertex
																     between is less than the
																     previous cost */
				minCostArr[i] = graph[selectedVertex][i] + minCostArr[selectedVertex]; /* Update cost */
			}
		}
	}
	return;
}

int main(){
	int minimumCosts[VERTICES_COUNT], i;
	dijkstrasAlgorithm(graph, minimumCosts);
	for (i = 0; i < VERTICES_COUNT; i++){
		printf("Cost of node %d from node 0 is %d\n", i, minimumCosts[i]);
	}
	return 0;
}
