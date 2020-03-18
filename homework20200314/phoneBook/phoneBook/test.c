#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

typedef struct personPhoneBook {
	char name[1024];
	char gender[1024];
	char age[1024];
	char phone[1024];
	char address[1024];
}personPhoneBook;

typedef struct phoneBook {
	personPhoneBook personPhoneInfo[MAX_SIZE];
	int size;
}phoneBook;

//初始化
void phoneBookInit(phoneBook* addr) {
	addr->size = 0;
	int  i = 0;

	for (i = 0; i < MAX_SIZE; i++) {
		personPhoneBook* info = &addr->personPhoneInfo[i];
		strcpy(info->name, " ");
		strcpy(info->address, " ");
		strcpy(info->age, " ");
		strcpy(info->gender, " ");
		strcpy(info->phone, " ");
	}
	return;
}

int menu() {
	printf("================================================\n");
	printf("请输入您的选项:\n");
	printf("1. 添加联系人\n");
	printf("2. 修改联系人\n");
	printf("3. 删除联系人\n");
	printf("4. 查找联系人\n");
	printf("5. 打印全部联系人\n");
	printf("6. 删除全部联系人\n");
	printf("7. 以名字排序全部联系人\n");
	printf("0. 退出\n");
	printf("================================================\n");

	int choice = 0;
	scanf("%d", &choice);

	return choice;

}

void AddPersonPhone(phoneBook* add_book) {
	//添加姓名和电话
	//[0, size)是有效部分
	printf("新增联系人!\n");
	if (add_book->size >= MAX_SIZE) {
		printf("通讯录已满,添加失败\n");
		return;
	}

	personPhoneBook* info = &add_book->personPhoneInfo[add_book->size];
	printf("请输入想要添加的姓名:\n");
	scanf("%s", info->name);

	printf("请输入性别:\n");
	scanf("%s", info->gender);
	printf("请输入年龄:\n");
	scanf("%s", info->age);
	printf("请输入电话号码:\n");
	scanf("%s", info->phone);
	printf("请输入地址:\n");
	scanf("%s", info->address);
	add_book->size++;
	printf("新添加联系人成功!\n");
}
void ModifyPersonPhone(phoneBook* add_book) {
	//修改联系人
	//人性化:(*不变)
	char name[1024] = { 0 };
	char phone[1024] = { 0 };
	char gender[1024] = { 0 };
	char age[1024] = { 0 };
	char address[1024] = { 0 };
	int id = 0; 
	printf("请输入您想修改的联系人序号:\n");
	scanf("%d", &id);
	//非法校验
	if (id < 0 || id >= add_book->size) {
		printf("您的输入有误!\n");
	}
	personPhoneBook* info = &add_book->personPhoneInfo[id];
	
	printf("请输入修改后的联系人姓名(*不修改):\n");
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(info->name, name);
	}
	printf("请输入修改后的性别(*不修改):\n");
	scanf("%s", gender);
	if (strcmp(gender, "*") != 0) {
		strcpy(info->gender, gender);
	}
	printf("请输入修改后的年龄(*不修改):\n");
	scanf("%s", age);
	if (strcmp(age, "*") != 0) {
		strcpy(info->age, age);
	}
	printf("请输入修改后的电话(*不修改):\n");
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(info->phone, phone);
	}
	printf("请输入修改后的地址(*不修改):\n");
	scanf("%s", address);
	if (strcmp(address, "*") != 0) {
		strcpy(info->address, address);
	}
	printf("修改完成!\n");
	

}
void DeletePersonPhone(phoneBook* add_book) {
	/*char name[1024] = { 0 };
	char phone[1024] = { 0 };*/
	int id = 0;
	printf("删除联系人!\n");
	printf("请输入想要删除的联系人序号:\n");
	while (1) {
		scanf("%d", &id);
		//id非法性校验
		if (id < 0 || id >= add_book->size) {
			printf("您输入的序号有误,请重新输入:\n");
			continue;
		}
		break;
	}
	//交换当前下标与最后的一个元素的信息;
	personPhoneBook* info_id = &add_book->personPhoneInfo[id];
	//strcpy(name, info_id->name);
	//strcpy(phone, info_id->name);
	personPhoneBook* info_size = &add_book->personPhoneInfo[add_book->size-1];
	strcpy(info_id->name, info_size->name);
	strcpy(info_id->gender, info_size->gender);
	strcpy(info_id->age, info_size->age);
	strcpy(info_id->phone, info_size->phone);
	strcpy(info_id->address, info_size->address);
	add_book->size--;
	printf("删除成功!\n");

}
void FindPersonPhone(phoneBook* add_book) {
	printf("查找联系人!\n");
	char name[1024] = { 0 };
	int count = 0;
	printf("请输入想要查找的联系人姓名:\n");
	scanf("%s", name);
	
	int i = 0;
	for (i = 0; i < add_book->size; i++) {
		personPhoneBook* info = &add_book->personPhoneInfo[i];
		//匹配联系人姓名,注意重名打印序号
		if (strcmp(name, info->name) == 0) {
			printf("[%d] 姓名: %s\t性别:%s\t年龄:%s\t电话: %s\t住址:%s\n", i, info->name, info->gender, info->age, info->phone, info->address);

			//printf("[%d] 姓名: %s\t 电话: %s\n", i, info->name, info->phone);
			count++;
		}
	}
	printf("已找到以上 %d 位联系人!\n", count);
	
}
void PrintfPersonPhone(phoneBook* add_book) {
	//打印所有联系人信息
	int i = 0;
	for (i = 0; i < add_book->size; i++) {
		personPhoneBook* info = &add_book->personPhoneInfo[i];
		printf("[%d] 姓名: %s\t性别:%s\t年龄:%s\t电话: %s\t住址:%s\n", i, info->name, info->gender, info->age, info->phone,info->address);
	}
	printf("共打印了 %d 个联系人!\n", add_book->size);
}
void ClearPersonPhone(phoneBook* add_book) {
	printf("删除全部联系人!!!这是一个危险操作!!!\n");
	printf("此操作不可逆,您真的确定删除所有联系人吗? Y/N?\n");
	char choice[1024] = { 0 };
	scanf("%s", choice);
	if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0){
		add_book->size = 0;
		printf("已删除所有联系人!\n");
		return;
	}
	else {
		printf("退出删除所有联系人操作!\n");
		return;
	}
	
}
void RankPersonPhone(phoneBook* add_book) {
	printf("按照姓名首字母排序所有联系人!");
	char name[1024] = { 0 };
	char phone[1024] = { 0 };
	char gender[1024] = { 0 };
	char age[1024] = { 0 };
	char address[1024] = { 0 };
	int id = 0;
	int i = 0;
	/*for (i = 0; i < add_book->size; i++) {
		personPhoneBook* info = &add_book->personPhoneInfo[i];

	}*/
	return;
}
//int bubbleSort(phoneBook* add_book, int size) {
//	int i, j;
//	int bound = 0;
//	//[0, bound)为排序区间;
//	for (bound = 0; bound < size; bound++) {
//
//	}
//}

typedef void(*Fun)(phoneBook*);
//转移表实现if elseif 的作用 ;Fun func[]要注意写法
Fun func[] = {
	NULL,				  //NULL在这里仅仅是为了占位,让输入对应 
	AddPersonPhone,
	ModifyPersonPhone,
	DeletePersonPhone,
	FindPersonPhone,
	PrintfPersonPhone,
	ClearPersonPhone,
	RankPersonPhone,
};

int main(void) {
	phoneBook address_book;
	//通讯录初始化
	phoneBookInit(&address_book);
	while (1) {
		int choice = menu();
		if (choice == 0) {
			printf(" goodbye!\n");
			break;
		}
		func[choice](&address_book);			//进入转移表执行函数
		
	}
	
	system("pause");
	return 0;
}