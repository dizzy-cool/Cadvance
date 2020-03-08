#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
	int i = 0;
	int j = 0;
	int newSize = numsSize;
	for ( i = 0; i < numsSize; i++) {
		if (nums[i] == val) {
			nums[i] = nums[i + 1];
			int temp = nums[i];
			for ( j =  i; j < numsSize  ; j++) {
				
				nums[j] = nums[j + 1];
			}
			nums[numsSize - 1] = temp;
			newSize--;
		}
	}
	for (i = 0; i < newSize; i++) {
		printf("%d ", nums[i]);
	}
	return newSize;
	
}

int d2p1(void) {
	
	int nums[8] = { 1, 2, 0, 2, 5, 0, 0, 0};
	int newSize = 0;
	newSize = removeElement(nums, 8, 0);
	
	system("pause");
	return 0;
}