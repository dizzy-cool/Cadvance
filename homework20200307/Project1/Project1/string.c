#include <stdio.h>
#include <stdlib.h>

void Strcat(char* a, const char* b) {
	int count = 0;
	while (a[count] != '\0') {
		count++;
	}
	int i = 0;
	while (b[i] != '\0') {
		a[count + i] = b[i];
		i++;
	}
	a[count + i] = '\0';
	
}

void Strcpy(char* a, const char* b) {
	int i = 0;
	while (b[i] != '\0') {
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
}
int Strlen(char* a) {
	int i = 0;
	while (a[i] != '\0') {
		i++;
	}
	return i ;
}

int main(void) {
	char a[100] = "hehe";
	char b[100] = "haha";

	int n = 0;
	n = Strlen(a);
	printf("%d\n", n);
	
	system("pause");
	return 0;
}