#include <stdio.h>

static int num_arr[] = {56, 76, 43, 89, 66};
#define NUM_ARR_LEN (sizeof(num_arr) / sizeof(int))

static void selectionSort(int arr[], int arr_len){
	int i, j, k, tmp;
	if (arr_len <= 1){
		return;
	}
	else {
		for (i = 0; i < arr_len - 1; i++){
			for (j = i + 1, k = i; j < arr_len; j++){
				if (arr[j] < arr[k]){
					k = j;
				}
			}
			if (k != i){
				tmp = arr[k];
				arr[k] = arr[i];
				arr[i] = tmp;
			}
		}
		return;
	}
}

int main(){
	int i;
	printf("%d\n", NUM_ARR_LEN);
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d  ", num_arr[i]);
	}
	printf("\n");
	selectionSort(num_arr, NUM_ARR_LEN);
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d  ", num_arr[i]);
	}
	printf("\n");
	return 0;
}
