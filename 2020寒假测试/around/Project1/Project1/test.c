#include <stdio.h>
#include <stdlib.h>

void rotate(int* nums, int numsSize, int k) {
	int temp = 0;
	for (int i = 0; i < k; i++) {
		temp = nums[numsSize - 1];
		for (int j = (numsSize-1); j > 0 ; j--) {
			nums[j] = nums[j - 1];
		}
		nums[0] = temp;
	}
}


int main(void) {
	
	int nums[7] = { 1, 2, 3, 4, 5, 6,7 };
	rotate(nums, 7, 2);
	for (int i = 0; i < 7; i++) {
		printf("%d ", nums[i]);
	}

	system("pause");
	return 0;
}