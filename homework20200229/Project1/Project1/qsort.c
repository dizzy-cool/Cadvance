#include <stdio.h>
#include <stdlib.h>

int values[] = { 155, 26, 2, 55, 465 };

//int cmpfunc(const void * a, const void * b)
//{
//	return (*(int*)b - *(int*)a);
//}
int cmpfunc(int* a, int* b) {
	return *b - *a;
}

int main()
{
	int n;

	printf("排序之前的列表：\n");
	for (n = 0; n < 5; n++) {
		printf("%d ", values[n]);
	}

	qsort(values, 5, sizeof(int), cmpfunc);

	printf("\n排序之后的列表：\n");
	for (n = 0; n < 5; n++) {
		printf("%d ", values[n]);
	}
	system("pause");
	return(0);
}