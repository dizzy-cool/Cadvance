#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	/*int a[5] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
*/
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("a_ptr=%#p,p_ptr=%#p\n", &a[4][2], &p[4][2]);
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	system("pause");
	return 0;
}

