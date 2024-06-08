#include <stdio.h>

static int num_arr[] = {22, 54, 65, 33, 45, 68};
#define NUM_ARR_LEN (sizeof(num_arr) / sizeof(int))

static void insertionSort(int *arr, int arr_len){
	int i, j, tmp;
	if (arr_len <= 1){
		return; /* Already sorted */
	}
	else {
		for (i = 1; i < arr_len; i++){
			for (j = i; j >= 1; j--){
				if (arr[j] < arr[j - 1]){
					tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tmp;
				}
				else {
					break;
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
	insertionSort(num_arr, NUM_ARR_LEN);
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d  ", num_arr[i]);
	}
	printf("\n");
	return 0;
}
