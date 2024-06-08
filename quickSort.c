#include <stdio.h>

static int num_arr[] = {34, 55, 33, 65, 76, 54, 33};
#define NUM_ARR_LEN (sizeof(num_arr) / sizeof(int))

static int partition(int *arr, int headInd, int tailInd){
	int i, j, tmp;
	for (i = headInd, j = headInd; i < tailInd; i++){
		if (arr[i] < arr[tailInd]){
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
			j++;
		}
	}
	tmp = arr[j];
	arr[j] = arr[tailInd];
	arr[tailInd] = tmp;
	return j;
}

static void quickSort(int *arr, int headInd, int tailInd){
	int midInd;
	if (headInd < tailInd){
		midInd = partition(arr, headInd, tailInd);
		quickSort(arr, headInd, midInd - 1);
		quickSort(arr, midInd + 1, tailInd);
	}
	return;
}

int main(){
	int i;
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d ", num_arr[i]);
	}
	printf("\n");
	quickSort(num_arr, 0, NUM_ARR_LEN - 1);
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d ", num_arr[i]);
	}
	printf("\n");
	return 0;
}
