#include <stdio.h>

#define INFINITY 0x7FFFFFFF
#define VERTICES_COUNT 8
static int graph[][VERTICES_COUNT] = {{0, 12, 17, 15, 0, 0, 0, 0},
					{12, 0, 21, 0, 20, 0, 0, 0},
					{17, 21, 0, 14, 0, 24, 0, 0},
					{15, 0, 14, 0, 13, 19, 23, 22},
					{0, 20, 0, 13, 0, 0, 18, 0},
					{0, 0, 24, 19, 0, 0, 0, 0},
					{0, 0, 0, 23, 18, 0, 0, 16},
					{0, 0, 0, 22, 0, 0, 16, 0}}; /* adjacency matrix of the graph */

static int checkVertex(int colouredVertices[], int colouredVerticesCount, int vertexLabel){
	/*
	 *  this function checks if the 'vertexLabel' is coloured or not
	 *  if it is already coloured it returns 0 otherwise returns 1
	 *  */
	int i;
	for (i = 0; i < colouredVerticesCount; i++){
		if (colouredVertices[i] == vertexLabel){
			return 0;
		}
	}
	return 1;
}

static void primsAlgorithm(int graph[][VERTICES_COUNT], int mstEdges[][3]){
	int i, j, k, fillCount, minWeight, vertexNo1, vertexNo2;
	int verticesArr[VERTICES_COUNT];
	verticesArr[0] = 0; /* Selecting the initial node and colouring it */
	fillCount = 1;
	while (fillCount < VERTICES_COUNT){
		for (i = verticesArr[0], j = 0, minWeight = INFINITY; j < fillCount; i = verticesArr[++j]){
			for (k = 0; k < VERTICES_COUNT; k++){
				if (graph[i][k] != 0 && minWeight > graph[i][k] && checkVertex(verticesArr, fillCount, k)){
					/*
					 * the above condition states checks if theres an edge between vertices 'i' and 'k'
					 * secondly it checks whether the weight of the edges is less than the last eligible edge
					 * and lastly it checks whether 'k' is coloured or not (to check for cycle formation) and
					 * to eliminate the edges already selected
					 * */
					minWeight = graph[i][k];
					vertexNo1 = i;
					vertexNo2 = k;
				}
			}
		}
		verticesArr[fillCount] = vertexNo2;
		mstEdges[fillCount - 1][0] = vertexNo1;
		mstEdges[fillCount - 1][1] = vertexNo2;
		mstEdges[fillCount - 1][2] = minWeight;
		fillCount++;
	}
}

int main(){
	int i, weight;
	int mst[VERTICES_COUNT - 1][3];
	primsAlgorithm(graph, mst);
	for (i = 0, weight = 0; i < VERTICES_COUNT - 1; i++){
		printf("(%d, %d)-->%d\n", mst[i][0], mst[i][1], mst[i][2]);
		weight += mst[i][2];
	}
	printf("Total Cost: %d\n", weight);
	return 0;
}
