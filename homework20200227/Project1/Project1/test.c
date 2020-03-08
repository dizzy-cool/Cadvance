#include <stdio.h>
#include <stdlib.h>

#define ROW  3
#define COL  3

//����ʵ���ַ���ѭ�����ƺ�,�ж����ַ���2���Ƿ�һ��
//1.���ж�����1λ�����
//2. ���Ϸ���1
void rotate(int* nums, int numsSize, int k) {  //���Ƴ���
	int temp = 0;
	for (int i = 0; i < k; i++) {
		temp = nums[numsSize - 1];
		for (int j = (numsSize - 1); j > 0; j--) {
			nums[j] = nums[j - 1];
		}
		nums[0] = temp;
	}
}

void rotateLeft(int* nums, int numsSize, int k) {  //���Ƴ���
	int temp = 0;
	for (int i = 0; i < k; i++) {
		temp = nums[0];
		for (int j = 0; j < numsSize; j++) {
			nums[j] = nums[j+1];
		}
		nums[numsSize-1] = temp;
	}
}
int retResult(int* s1, int* s2, int sSize) {
	int i = 0;
	for (i = 0; i < sSize; i++) {
		if (s1[i] != s2[i]) {
			return 0;
		}
	}
	return 1;
}

int stringReverse(int* s1, int* s2,int sSize) {
	int i = 0;
	int ret = 0;
	for (i = 0; i < sSize; i++) {
		ret = retResult(s1, s2, sSize);
		if (ret == 1) {
			return 1;
		}
		else {
			rotateLeft(s1, sSize, 1);
		}
	}
	return 0;
}
//�Ⱥ���Ѱ����ӽ���ֵ(���ַ�)
//������Ѱ��
int DigitalMatrixFinding(int matrix[ROW][COL], int find) {
	
	int rLow = 0, rHigh = ROW - 1;
	int cLow = 0, cHigh = COL - 1;
	int rMid =  0;
	int cMid =  (cLow + cHigh) / 2;
	while (rLow <= rHigh) {
		while (cLow <= cHigh) {
			cMid = (cLow + cHigh) / 2;
			if (matrix[rMid][cMid] == find) {
				return 1;
			}
			else if (matrix[rMid][cMid] < find) {
				cLow = cMid + 1;
			}
			else {
				cHigh = cMid - 1;
			}
		}
		rMid = (rLow + rHigh) / 2;
			if (matrix[rMid][cMid] == find) {
				return 1;
			}
			else if (matrix[rMid][cMid] < find) {
				rLow = rMid + 1;
			}
			else {
				rHigh = rMid - 1;
			}
	}
	
	
	return 0;
}
int main(void) {
	
	int s1[5] = {'A', 'A', 'B', 'C', 'D'};
	int s2[5] = { 'B','C','D', 'A','A'};
	int s3[5] = { 'A', 'A', 'B', 'C', 'D' };
	int result = 0;

	int matrix[ROW][COL] = { {1,2,3}, {2,3,4} ,{3,4,5} };
	result = DigitalMatrixFinding(matrix, 2);
	if (result == 1) {
		printf("����!");
	}
	else {
		printf("������!\n");
	}

	/*result = stringReverse(s1, s2, 5);
	if (result == 1) {
		printf("S1��S2���ַ�����ת\n");
	}
	else {
		printf("S1��S2û��ϵ\n");
	}*/
	/*rotateLeft(s3, 5, 2);
	for (int i = 0; i < 5; i++) {
		printf("%c ", s3[i]);
	}*/

	
	system("pause");
	return 0;
}