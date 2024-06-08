#include <stdio.h>

#define VERTICES_COUNT 8

static int graph[][VERTICES_COUNT] = {{0, 12, 17, 15, 0, 0, 0, 0},
					{12, 0, 21, 0, 20, 0, 0, 0},
					{17, 21, 0, 14, 0, 24, 0, 0},
					{15, 0, 14, 0, 13, 19, 23, 22},
					{0, 20, 0, 13, 0, 0, 18, 0},
					{0, 0, 24, 19, 0, 0, 0, 0},
					{0, 0, 0, 23, 18, 0, 0, 16},
					{0, 0, 0, 22, 0, 0, 16, 0}}; /* adjacency matrix of the graph */

static void floydWarshalsAlgorithm(int graph[][VERTICES_COUNT]){
	int selectedVertex, reachableNode, reachableNodeIndirect;
	for (selectedVertex = 0; selectedVertex < VERTICES_COUNT; selectedVertex++){
		for (reachableNode = 0; reachableNode < VERTICES_COUNT; reachableNode++){
			if (graph[selectedVertex][reachableNode]){
				for (reachableNodeIndirect = 0; reachableNodeIndirect < VERTICES_COUNT; reachableNodeIndirect++){
					if (graph[reachableNode][reachableNodeIndirect] && (!graph[selectedVertex][reachableNodeIndirect] || (graph[selectedVertex][reachableNode] + graph[reachableNode][reachableNodeIndirect]) < graph[selectedVertex][reachableNodeIndirect])){
						graph[selectedVertex][reachableNodeIndirect] = graph[selectedVertex][reachableNode] + graph[reachableNode][reachableNodeIndirect];
						graph[reachableNodeIndirect][selectedVertex] = graph[selectedVertex][reachableNodeIndirect];
					}
				}
			}
		}
	}
	return;
}

int main(){
	int i, j;
	floydWarshalsAlgorithm(graph);
	for (i = 0; i < VERTICES_COUNT; i++){
		for (j = 0; j < VERTICES_COUNT; j++){
			printf("(%d, %d)->%d ", i, j, graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}
