#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {
	
	int i = 0; 
	if (target < nums[0]) {
		return 0;
	}
	else if (target > nums[numsSize - 1]) {
		return numsSize ;
	}
	for (; i < numsSize; i++) {
		if (nums[i] == target) {
			return i;
		}
		else if ((nums[i - 1] < target) && nums[i] > target) {
			return i;
		}
	}
}

int main(void) {
	int nums[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int t = searchInsert(nums, 10, 8);
	printf(" the target is %d \n", t);
	system("pause");
	return 0;
}