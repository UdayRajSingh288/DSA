#include <stdio.h>

static int num_arr[] = {76, 56, 44, 87, 22, 43, 34};
#define NUM_ARR_LEN (sizeof(num_arr) / sizeof(int))

static void swap(int *val1, int *val2){
	int tmp;
	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
	return;
}

static void heapify(int *arr, int arrLen, int ind){
	int largest, left, right;
	largest = ind;
	left = 2 * ind + 1;
	right = 2 * ind + 2;
	if (left < arrLen && arr[left] > arr[largest]){
		largest = left;
	}
	if (right < arrLen && arr[right] > arr[largest]){
		largest = right;
	}
	if (largest != ind){
		swap(arr + ind, arr + largest);
		heapify(arr, arrLen, largest);
	}
	return;
}

static void heapSort(int *arr, int arrLen){
	int i;
	for (i = arrLen / 2 - 1; i >= 0; i--){
		heapify(arr, arrLen, i);
	}
	for (i = arrLen - 1; i >= 0; i--){
		swap(arr, arr + i);
		heapify(arr, i, 0);
	}
	return;
}

int main(){
	int i;
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d ", num_arr[i]);
	}
	printf("\n");
	heapSort(num_arr, NUM_ARR_LEN);
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d ", num_arr[i]);
	}
	printf("\n");
	return 0;
}
