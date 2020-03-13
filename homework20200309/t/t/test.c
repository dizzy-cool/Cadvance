#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* Memcpy(void* dest, const void* src) {
	assert(dest != NULL && src != NULL);

	char* cdest = (char*)dest;
	char* csrc = (char*)src;

	while (*csrc != '\0') {
		*cdest = *csrc;
		cdest++;
		csrc++;
	}
	*cdest = '\0';
	return dest;
}

char* Strcpy(char* dest, const char* src) {
	assert(dest != NULL && src != NULL);
	
	char* result = dest;
	while (*src != '\0') {
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return result;
}

void* Memmove(void* dest, const void* src, size_t num) {
	assert(dest != NULL && src != NULL);
	char* cdest = (char*)dest;
	char* csrc = (char*)src;
	
	if (csrc < cdest && cdest < csrc + num) {
		//从后往前拷贝
		char* pdest = cdest + num - 1;
		char* psrc = csrc + num - 1;
		for (size_t i = 0; i < num; i++) {
			*pdest = *psrc;
			pdest--;
			psrc--;
		}
	}
	else {
		Memcpy(dest, src);
	}
	return dest;
}

const char* Strstr(const char* str1, const char* str2) {
	//避免违法内存
	assert(str1 != NULL && str2 != NULL);

	if (*str2 == '\0') {
		//此时说明str2是一个空字符串
		return NULL;
	}
	
	const char* black = str1;
	while (*black != '\0') {
		const char* red = black;
		const char* sub = str2;
		
		while((*red == *sub) && *red != '\0' && *sub != '\0' ) {
			//三个结束条件
			//1. *red *sub不一样
			//2. red到头未找到
			//3. sub到头找到
			red++;
			sub++;
		}
		if (*sub == '\0') {//if顺序不可调换
			return black;	//sub到头,找到子字符串
		}
		if (*red == '\0') { //red到头没找到子字符串
			return NULL;
		}
		black++;		//继续处理下次循环匹配
	}
	return NULL;   //到头也没找到
}

int Strcmp(const char* str1, const char* str2) {
	assert(str1 != NULL && str2 != NULL);
	
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 > *str2) {
			return 1;
		}
		else if (*str1 < *str2) {
			return -1;
		}
		else {
			//当前字符难分高下,继续下一个字符
			str1++;
			str2++;
		}
	}
	if (*str1 < *str2) {
		return -1;
	}
	else if (*str1 > *str2) {
		return 1;
	}
	else {
		return 0;
	}
}



int main(void) {
	
	char arr[100] = "ae";
	char arr2[100] = "ehe";
	char* b = &arr[1];
	char* p = NULL;
	//p = (char*)Memcpy(arr, arr2);
	//p = (char*)Memmove(arr, b, 2);

	//p = Strstr(arr, arr2);
	//printf("%s\n", p);
	int ret = Strcmp(arr, arr2);

	if (ret < 0) {
		printf(" str1 < str2 \n");
	} else if (ret > 0) {
		printf(" str1 > str2 \n");
	} else {
		printf(" str1 == str2 \n");
	}
	//printf("%d \n", ret);

	system("pause");
	return 0;
}