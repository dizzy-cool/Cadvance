#include <stdio.h>
#include <stdlib.h>

#define PEOPLE_NUM 5

void PrintYang(void) {
	int a[100] = { 1 };
	int i = 0,j = 0,k = 0;
	for (i = 0; i < 10; i++) {
		
		for (j = i; j > 0; j--) {
			a[j] = a[j] + a[j - 1];
			
		}
		while (a[k] ) {
			printf("%d ", a[k]);
			k++;
		}
		printf("\n");
		k = 0;
	}
}

void JapanKiller(void) {
	int sus = 0;
	for (sus = 'A'; sus <= 'D'; sus++) {
		if ((sus != 'A') + (sus == 'C') + (sus == 'D') + (sus != 'D') == 3) {
			printf("凶手是 %c !\n", sus);
		}
	}
}



void skipRank(void) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= PEOPLE_NUM; a++) {
		for (b = 1; b <= PEOPLE_NUM; b++) {
			for (c = 1; c <= PEOPLE_NUM; c++) {
				for (d = 1; d <= PEOPLE_NUM; d++) {
					for (e = 1; e <= PEOPLE_NUM; e++) {
						if ((a == 3 && b != 2) || (a != 3 && b == 2)) {
							if ((b == 2 && e != 4) || (b != 2 && e == 4)) {
								if ((c == 1 && d != 2) || (c != 1 && d == 2)) {
									if ((d == 3 && c != 5) || (d != 3 && c == 5)) {
										if ((a == 1 && e != 4) || (a != 1 && e == 4)) {
											//筛选唯一符合的顺序
											if (a != b && a != c && a != d && a != e
												&& b != c && b != d && b != e
												&& c != d && c != e
												&& d != e) {
												printf("名次排名如下: a = %d ,b = %d ,c = %d ,d = %d , e = %d\n", a, b, c, d, e);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
int main(void) {
	
	//PrintYang();
	JapanKiller();
	system("pause");
	return 0;
}