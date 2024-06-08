#include <stdio.h>

static int num_arr[] = {65, 66, 45, 22, 34, 56, 76};
#define NUM_ARR_LEN (sizeof(num_arr) / sizeof(int))

static int sequentialSearch(int *arr, int arrLen, int element){
	int i;
	for (i = 0; i < arrLen; i++){
		if (arr[i] == element){
			return 1;
		}
	}
	return 0;
}

int main(){
	int num;
	num = 70;
	if (sequentialSearch(num_arr, NUM_ARR_LEN, num)){
		printf("%d Found!\n", num);
	}
	else {
		printf("%d Not Found!\n", num);
	}
	num = 76;
	if (sequentialSearch(num_arr, NUM_ARR_LEN, num)){
		printf("%d Found!\n", num);
	}
	else {
		printf("%d Not Found!\n", num);
	}
	return 0;
}
