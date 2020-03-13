#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
	char b;
	short c;
	short d;
}AA_t;
struct A {
	int a;
	short b;
	int c;
	char d;
};
struct B{
	int a;
	short b;
	char c;
	int d;
};

//#define MAX_SIZE A+B   //宏定义只是表达式的拷贝,
struct _Record_Struct
{
	unsigned char Env_Alarm_ID : 4;
	unsigned char Para1 : 2;
	unsigned char state;
	unsigned char avail : 1;
}*Env_Alarm_Record;

union Un
{
	short s[7];
	int n;
};



int main(void) {
	//int A = 2;
	//int B = 3;
	////printf("%d\n %d\n", sizeof(struct A), sizeof(struct B));
	//struct _Record_Struct *pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);
	//printf("%d\n", sizeof(sizeof(struct _Record_Struct) * MAX_SIZE));//3*  2+3  ==> 9  注意宏定义的本质: 表达式的拷贝!!!!
	printf("%d\n", sizeof(union Un));
	system("pause");
	return 0;
}
//
//int main()
//{
//	unsigned char puc[4];
//	struct tagPIM
//	{
//		unsigned char ucPim1;
//		unsigned char ucData0 : 1;
//		unsigned char ucData1 : 2;
//		unsigned char ucData2 : 3;
//	}*pstPimData;
//	pstPimData = (struct tagPIM*)puc;
//	memset(puc, 0, 4);
//	pstPimData->ucPim1 = 2;
//	pstPimData->ucData0 = 3;
//	pstPimData->ucData1 = 4;
//	pstPimData->ucData2 = 5;
//	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//	system("pause");
//	//	return 0;
//	return 0;
//}