#include <stdio.h> 
#include <stdlib.h>


int compress(char* chars, int charsSize);


int main1() {

	char chars[] = { 'a', 'b','b' ,'v' ,'b' ,'b' ,'b' ,'b' ,'b' ,'b' ,'b' ,'b' ,'b'};
	int ans = 0;
	ans = compress(chars, 13);
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) {
		printf("%c ", chars[i]);
	}
	system("pause");
	return 0;
}

int compress(char* chars, int charsSize) {
	int i = 0, j = 0;
	int start = 0, end = 0;
	int count = 1;
	for (; i < charsSize; i++) {
		if (chars[i] == chars[i + 1]) {//内存访问越界造成的
			count++;
		}
		else {
			chars[j++] = chars[i];
			if (count > 9) {
				chars[j++] = (count / 10) + '0';
				chars[j++] = (count % 10) + '0';
			}
			else if (count > 1){
				chars[j++] = count + '0';
			}
			
			
			count = 1;
			end = i;
		}
	}
	return j ;
}

int compress2(char *chars, int charsSize)
{
	int start = 0, end = 0, k = 0, t, i, j;
	for (; start < charsSize; start++) {
		if (start + 1 == charsSize || chars[start] != chars[start + 1]) {
			chars[k++] = chars[end];
			if (start > end) {            //连续次数大于1时保存次数
				t = start - end + 1;
				i = k;              //次数转为字符串时需要翻转，用i保存翻转的起点
				while (t > 0) {       //测试用例的次数最多两位数，但我们要考虑多位数的情况
					chars[k++] = t % 10 + '0';
					t /= 10;
				}
				for (j = 0; j < (k - i) / 2; j++) {     //翻转
					char tmp = chars[i + j];
					chars[i + j] = chars[k - 1 - j];
					chars[k - 1 - j] = tmp;
				}
			}
			end = start + 1;
		}
	}
	return k;
}
