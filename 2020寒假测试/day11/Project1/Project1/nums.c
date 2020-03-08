#include <stdio.h> 
#include <stdlib.h>


int findUnsortedSubarray(int* nums, int numsSize);


int main() {

	int nums[] = { 2,6,4,8,10,9,15 };
	int numSize = sizeof(nums) / sizeof(nums[0]);
	printf("%d \n", numSize);
	for (int i = 0; i < numSize; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	int ans = 0;
	ans = findUnsortedSubarray(nums, numSize);

	printf("%d \n", ans);
	system("pause");
	return 0;
}

int findUnsortedSubarray(int* nums, int numsSize) {
	int start = 0, end = 0;
	int i = 0, j = 1;
	//¼ì²âÉıĞòÅÅĞò
	for (i = 0; i < numsSize - 1; i++) {
		if (nums[i] > nums[i + 1]) {
			start = i;
			end = start + 1;
			while ((start + j) < numsSize - 1) {
				
				if (nums[start + j] > nums[start + j + 1]) {
					j++;
					end = start + j;
					break;
				}
				j++;
			}
			break;
		}
	}
	if (start == end) {
		return 0;
	}
	else {
		return (end - start + 1);
	}
}