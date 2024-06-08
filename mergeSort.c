#include <stdio.h>

static int num_arr[] = {45, 55, 65, 74, 32, 88, 65, 22};
#define NUM_ARR_LEN (sizeof(num_arr) / sizeof(int))

static void merge(int *arr, int headInd, int midInd, int tailInd){
	int tmpArr1[midInd - headInd + 2], tmpArr2[tailInd - midInd + 1], maxVal, i, j, k;
	maxVal = arr[midInd] + arr[tailInd] + 1;
	for (i = headInd, j = 0; i <= midInd; i++, j++){
		tmpArr1[j] = arr[i];
	}
	tmpArr1[j] = maxVal;
	for (i = midInd + 1, k = 0; i <= tailInd; i++, k++){
		tmpArr2[k] = arr[i];
	}
	tmpArr2[k] = maxVal;
	for (i = headInd, j = 0, k = 0; i <= tailInd; i++){
		if (tmpArr1[j] < tmpArr2[k]){
			arr[i] = tmpArr1[j];
			j++;
		}
		else {
			arr[i] = tmpArr2[k];
			k++;
		}
	}
	return;
}

static void mergeSort(int *arr, int headInd, int tailInd){
	int midInd;
	if (headInd < tailInd){
		midInd = (headInd + tailInd) / 2;
		mergeSort(arr, headInd, midInd);
		mergeSort(arr, midInd + 1, tailInd);
		merge(arr, headInd, midInd, tailInd);
	}
	return;
}

int main(){
	int i;
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d ", num_arr[i]);
	}
	printf("\n");
	mergeSort(num_arr, 0, NUM_ARR_LEN - 1);
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d ", num_arr[i]);
	}
	printf("\n");
	return 0;
}
