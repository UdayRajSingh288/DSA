#include <stdio.h>

#define MARK 0x80000000
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

static int notMakesCycle(int graph[][VERTICES_COUNT], int vertexLabel1, int vertexLabel2, int lastVertexLabel){
	/*
	 * Bhagwan ke liye mujhse ye function explain krne ko mat kaho
	 * Copy kitaab leke bhi nahi samjha paunga
	 * bas naam se samajh jao
	 * agar cycle ban rha hai to 0
	 * nahi ban rha to 1
	 */
	int i, status;
	for (i = 0; i < VERTICES_COUNT; i++){
		if (graph[vertexLabel1][i] == MARK){
			if (i == vertexLabel2){
				return 0;
			}
			else {
				if (lastVertexLabel == i){
					continue;
				}
				status = notMakesCycle(graph, i, vertexLabel2, vertexLabel1);
				if (!status){
					return status;
				}
			}
		}
	}
	return 1;
}

static void kruskalsAlgorithm(int graph[][VERTICES_COUNT], int mstEdges[][3]){
	int i, j, minWeight, vertexNo1, vertexNo2, fillCount;
	fillCount = 0;
	while (fillCount < VERTICES_COUNT - 1){
		for (i = 0, minWeight = INFINITY; i < VERTICES_COUNT; i++){
			for (j = 0; j < i; j++){
				if (graph[i][j] != 0 && minWeight > graph[i][j] && notMakesCycle(graph, i, j, i)){
					/*
					 * the above condition checks whether there is an edge
					 * if the edge has less weight than the last legible edge
					 * if the edges creates a cycle or if the edge is already selected
					 * */
					minWeight = graph[i][j];
					vertexNo1 = i;
					vertexNo2 = j;
				}
			}
		}
		mstEdges[fillCount][0] = vertexNo1;
		mstEdges[fillCount][1] = vertexNo2;
		mstEdges[fillCount][2] = minWeight;
		graph[vertexNo1][vertexNo2] = MARK; /* colouring the edge (i.e. connected vertices) */
		graph[vertexNo2][vertexNo1] = MARK;
		fillCount++;
	}
	return;
}

int main(){
	int i, weight;
	int mst[VERTICES_COUNT - 1][3];
	kruskalsAlgorithm(graph, mst);
	weight = 0;
	for (i = 0; i < VERTICES_COUNT - 1; i++){
		printf("(%d, %d)-->%d\n", mst[i][0], mst[i][1], mst[i][2]);
		weight += mst[i][2];
	}
	printf("Total Cost: %d\n", weight);
	return 0;
}
