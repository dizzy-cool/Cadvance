#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int  canConstruct(char * ransomNote, char * magazine) {
	//char nowWord[100] = "0";
	//for (int i = 0; ransomNote[i] != '\0'; i++) {
	//	nowWord[i] = ransomNote[i];
	//}
	int nums_Note = strlen(ransomNote);
	int nums_magazine = strlen(magazine);
	//printf("%d ", nums_Note);
	//printf("%d ", nums_magazine);
	int times = 0;
	for (int i = 0; ransomNote[i] != '\0'; i++) {
		for (int j = 0; magazine[j] != '\0'; j++) {
			if (ransomNote[i] == magazine[j]) {
				//*(magazine + j) = '*';									//让已经验证过的给标志
				times++;
				break;
			}
		}
	}
	if (times == nums_Note) {
		return 1;
	}
	else
		return 0;

}

int main(void) {
	
	char* ransomNote = "aa";
	char* magazine = "a2a";
	printf("%s \n", ransomNote);
	printf("%s \n", magazine);
	
	int judge = canConstruct(ransomNote, magazine);
	if (judge == 1) {
		printf("true \n");
	}
	else
		printf("false \n");

	system("pause");
	return 0;
}