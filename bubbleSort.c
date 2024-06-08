#include <stdio.h>

static int num_arr[] = {56, 76, 43, 89, 66};
#define NUM_ARR_LEN (sizeof(num_arr) / sizeof(int))

static void bubbleSort(int *arr, int arr_len){
	int i, j, tmp;
	if (arr_len <= 1){
		return;
	}
	else {
		for (i = 0; i < arr_len; i++){
			for (j = 0; j < arr_len - i - 1; j++){
				if (arr[j] > arr[j + 1]){
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
		return;
	}
}

int main(){
	int i;
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d  ", num_arr[i]);
	}
	printf("\n");
	bubbleSort(num_arr, NUM_ARR_LEN);
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d  ", num_arr[i]);
	}
	printf("\n");
	return 0;
}
