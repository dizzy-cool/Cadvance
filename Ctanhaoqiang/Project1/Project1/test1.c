#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/*int i = 8;
	printf("%d \n", ++i);
	printf("%d \n", --i);
	printf("%d \n", i++);
	printf("%d \n", i--);
	printf("%d \n", -i++);
	printf("%d \n", -i--);*/

	//int i = 5, j = 6, p, q;
	////p = (i++) + (i++) + (i++);
	////q = (++j) + (++j) + (++j);
	//////自加自减在整句结束后才会运算
	////printf("%d, %d, %d, %d", p, q, i, j);

	//float k = 6;
	//int  u = 5.0;
	////printf("double i / k = %f \n", i / k);
	////printf("int  i / j = %d \n", i / j);


	//printf("double u / 6 = %f \n", -20.0 / 7);
	//printf("double u / 6 = %f \n", -(20.0 / 7));
	//printf("double u / 6 = %f \n", (-20.0 / 7);
	//printf("int  u / j = %d \n", -20 / 7);

	//char a = 'A', b = 'B';
	//putchar(a);
	//int a = 25;
	//printf("%d\n", a);
	//printf("%1d\n", a);
	//int i = 8;
	////printf("%d\n%d\n%d\n%d\n%d\n%d\n", ++i, --i, i++, i--, -i++, -i--);
	//printf("%d\n", ++i);
	//printf("%d\n", --i);
	//printf("%d\n", i++);
	//printf("%d\n", i--);
	//printf("%d\n", -i++);
	//printf("%d\n", +);


	int n = 0;
	printf("input interger number :  ");
	scanf("%d",&n);
	switch (n) {
		case 1:  
		case 2:
		case 3:
		case 4:
		case 5: printf("周内\n");
			break;
		case 6:
		case 7:
			printf("周末\n");
			break;
		default:
			printf("error\n");
			break;
	}
	system("pause");
	return 0;
}