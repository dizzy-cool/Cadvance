#include <stdio.h>
#include <stdlib.h>

char* toLowerCase(char* str) {

	for (; *str; str++) {
		if ((*str <= 'Z') && (*str >= 'A')) {

			*str  = (*str) + ('a' - 'A');
		}
	}
	return str;
}


int main(void) {
	
	char str[] = "HELLO BABY";
	printf("%s \n", str);

	toLowerCase(str);
	printf("%s\n", str);

	system("pause");
	return 0;
}

