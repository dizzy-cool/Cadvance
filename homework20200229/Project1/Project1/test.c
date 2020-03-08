#include <stdio.h>
#include <stdlib.h>

//定义规则
typedef int(*Cmp)(int, int);

int Less(int x, int y) {
	return x < y ? 1 : 0;
}
int Greater(int x, int y) {
	return x > y ? 1 : 0;
}

void bubbleSort(int arr[], int size, Cmp cmp) {
	int bound = 0;
	for (bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			if (cmp(arr[cur - 1], arr[cur])) {
				int temp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = temp;
			}
		}
	}
}

int main1(void) {
	
	int aa[10] = { 10,9,8,7,6,5,4,3,2,1 };
	bubbleSort(aa, 10, Greater);
	for (int i = 0; i < 10; i++) {
		printf("%d ", aa[i]);
	}
	system("pause");
	return 0;
}