#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int Atoi(const char *str) {
	assert(str != NULL);
	char ret = 0;
	while (*str >= '0' && *str <= '9') {
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return ret;
}
char* Strncat(char* destion, const char* source, size_t num) {
	assert(destion != NULL && source != NULL);
	int i = 0;
	size_t count = 0;
	while (destion[i] != '\0') {
		i++;

	}
	for (count = 0; count < num; count++) {
		destion[i + count] = source[count];
		}
	destion[i + count] = '\0';
	return destion;
}
char* Strncpy(char* destion, const char* source, size_t num) {
	assert(destion != NULL && source != NULL);
	size_t i = 0;
	for (i = 0; i < num; i++) {
		destion[i] = source[i];
	}
	destion[i] = '\0';
	return destion;
}

void findSingleNum(int arr[], int num, int* res) {
	//按位异或法
	//1.将所有的元素按位异或,得到的是狗a^狗b
	int ret = 0;
	int i = 0;
	for (; i < num; i++) {
		ret = ret ^ arr[i];
	}
	printf("%d\n", ret);
	// 此时 sum 的值就等价于 num1 ^ num2, 这个整数中一定存在某个比特位 为 1
	//2.将a^b结果中的 1 bit位,将原数组分为两类,能保证两个数组中各有一个singleNum

	int pos = 0;
	for (; pos < 32; pos++) {
		if ((ret & (1 << pos)) != 0) {
			break;
		}
	}
	//3.在进行数组中寻找单个 singleNum
	//    按照 pos 位置的元素是 1 还是 0 把整个数组分成两个部分, 分别进行按位异或
	for (i = 0; i < num; i++) {
		if ((arr[i] & (1 << pos)) == 0) {  // 优先级顺序  ! >算术运算符  > 关系运算符 > && > || > 赋值运算符
											//   其中       关系运算符 >    按位& ^ | && ||
			res[0] = res[0] ^ arr[i];
		}
		else {
			res[1] = res[1] ^ arr[i];
		}
	}
}
void BubbleSort(int* arr, int num) {
	int bound = 0;
	int i = 0;
	//[0 bound)   是已经排序的区间
	//[bound num) 是未排序的区间

	for (bound = 0; bound < num; bound++) {
		for (i = num - 1; i > bound; i--) {
			if (arr[i] < arr[i - 1]) {
				int temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
			}
		}
	}
}


int* findSingleDog(int* arr,int num,int* res) {

	BubbleSort(arr, num);
	int count = 0;
	int i = 0;
	
	if (arr[i] != arr[i + 1]) {
		res[count] = arr[i]; 
		count++;
	}
	if (arr[num - 1] != arr[num - 2]) {
		res[count] = arr[num-1];
		count++;
	}
	if (count >= 2) {
		return res;
	}
	
	i = 1;
	while (i < num - 1 && count < 2) {
		if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1]) {
			res[count] = arr[i];
			count++;
		}
		i++;
	}
	return res;
	
}

int main(void) {
	/*char str[100] = " ";
	while (1) {
		printf("请输入含数字的字符串:\n");
		scanf("%s", str);
		int n = Atoi(str);
		printf("%d\n", n);
	}*/

	//char str1[20];
	//char str2[20];
	//strcpy(str1, "To be ");
	//strcpy(str2, "or not to be");
	//Strncat(str1, str2, 14);
	//printf("%s\n", str1);

	//char str1[] = "To be or not to be";
	//char str2[40];
	//char str3[40];

	///* copy to sized buffer (overflow safe): */
	//Strncpy(str2, str1, sizeof(str2));

	///* partial copy (only 5 chars): */
	//Strncpy(str3, str2, 5);
	//str3[5] = '\0';   /* null character manually added */

	//puts(str1);
	//puts(str2);
	//puts(str3);


	int arr[] = { 1, 3, 4, 1, 3, 5 };
	int res[2] = { 0, 0 };
	findSingleNum(arr, sizeof(arr) / sizeof(arr[0]), res);
	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	printf("%d %d", res[0], res[1]);
	system("pause");
	return 0;
}