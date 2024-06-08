#include <stdio.h>

static int num_arr[] = {3654, 1332, 7644, 1254, 9876, 2351, 1111};
#define NUM_ARR_LEN (sizeof(num_arr) / sizeof(int))

static void countSort(int *arr, int arr_len, int place){
	int freq[10] = {0};
	int tmp_arr[arr_len], i;
	for (i = 0; i < arr_len; i++){
		freq[(arr[i] / place) % 10]++;
	}
	for (i = 1; i < 10; i++){
		freq[i] += freq[i - 1];
	}
	for (i = arr_len - 1; i >= 0; i--){
		tmp_arr[--(freq[(arr[i] / place) % 10])] = arr[i];
	}
	for (i = 0; i < arr_len; i++){
		arr[i] = tmp_arr[i];
	}
	return;
}

static void radixSort(int *arr, int arr_len){
	int max, i;
	max = arr[0];
	for (i = 0; i < arr_len; i++){
		if (arr[i] > max){
			max = arr[i];
		}
	}
	for (i = 1; max / i > 0; i *= 10){
		countSort(arr, arr_len, i);
	}
	return;
}

int main(){
	int i;
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d  ", num_arr[i]);
	}
	printf("\n");
	radixSort(num_arr, NUM_ARR_LEN);
	for (i = 0; i < NUM_ARR_LEN; i++){
		printf("%d  ", num_arr[i]);
	}
	printf("\n");
	return 0;
}
