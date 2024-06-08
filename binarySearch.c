#include <stdio.h>

static int num_arr[] = {23, 24, 27, 45, 55, 66, 67, 69, 78};
#define NUM_ARR_LEN (sizeof(num_arr) / sizeof(int))

static int binarySearch(int *arr, int arrLen, int element){
	int leftInd, rightInd, midInd;
	leftInd = 0;
	rightInd = arrLen - 1;
	while (leftInd <= rightInd){
		midInd = (rightInd + leftInd) / 2;
		if (element == arr[midInd]){
			return 1;
		}
		else if (element < arr[midInd]){
			rightInd = midInd - 1;
		}
		else {
			leftInd = midInd + 1;
		}
	}
	return 0;
}

int main(){
	int num;
	num = 65;
	if (binarySearch(num_arr, NUM_ARR_LEN, num)){
		printf("%d Found!\n", num);
	}
	else {
		printf("%d Not Found!\n", num);
	}
	num = 66;
	if (binarySearch(num_arr, NUM_ARR_LEN, num)){
		printf("%d Found!\n", num);
	}
	else {
		printf("%d Not Found!\n", num);
	}
	return 0;
}
