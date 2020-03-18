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

//��ʼ��
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
	printf("����������ѡ��:\n");
	printf("1. �����ϵ��\n");
	printf("2. �޸���ϵ��\n");
	printf("3. ɾ����ϵ��\n");
	printf("4. ������ϵ��\n");
	printf("5. ��ӡȫ����ϵ��\n");
	printf("6. ɾ��ȫ����ϵ��\n");
	printf("7. ����������ȫ����ϵ��\n");
	printf("0. �˳�\n");
	printf("================================================\n");

	int choice = 0;
	scanf("%d", &choice);

	return choice;

}

void AddPersonPhone(phoneBook* add_book) {
	//��������͵绰
	//[0, size)����Ч����
	printf("������ϵ��!\n");
	if (add_book->size >= MAX_SIZE) {
		printf("ͨѶ¼����,���ʧ��\n");
		return;
	}

	personPhoneBook* info = &add_book->personPhoneInfo[add_book->size];
	printf("��������Ҫ��ӵ�����:\n");
	scanf("%s", info->name);

	printf("�������Ա�:\n");
	scanf("%s", info->gender);
	printf("����������:\n");
	scanf("%s", info->age);
	printf("������绰����:\n");
	scanf("%s", info->phone);
	printf("�������ַ:\n");
	scanf("%s", info->address);
	add_book->size++;
	printf("�������ϵ�˳ɹ�!\n");
}
void ModifyPersonPhone(phoneBook* add_book) {
	//�޸���ϵ��
	//���Ի�:(*����)
	char name[1024] = { 0 };
	char phone[1024] = { 0 };
	char gender[1024] = { 0 };
	char age[1024] = { 0 };
	char address[1024] = { 0 };
	int id = 0; 
	printf("�����������޸ĵ���ϵ�����:\n");
	scanf("%d", &id);
	//�Ƿ�У��
	if (id < 0 || id >= add_book->size) {
		printf("������������!\n");
	}
	personPhoneBook* info = &add_book->personPhoneInfo[id];
	
	printf("�������޸ĺ����ϵ������(*���޸�):\n");
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(info->name, name);
	}
	printf("�������޸ĺ���Ա�(*���޸�):\n");
	scanf("%s", gender);
	if (strcmp(gender, "*") != 0) {
		strcpy(info->gender, gender);
	}
	printf("�������޸ĺ������(*���޸�):\n");
	scanf("%s", age);
	if (strcmp(age, "*") != 0) {
		strcpy(info->age, age);
	}
	printf("�������޸ĺ�ĵ绰(*���޸�):\n");
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(info->phone, phone);
	}
	printf("�������޸ĺ�ĵ�ַ(*���޸�):\n");
	scanf("%s", address);
	if (strcmp(address, "*") != 0) {
		strcpy(info->address, address);
	}
	printf("�޸����!\n");
	

}
void DeletePersonPhone(phoneBook* add_book) {
	/*char name[1024] = { 0 };
	char phone[1024] = { 0 };*/
	int id = 0;
	printf("ɾ����ϵ��!\n");
	printf("��������Ҫɾ������ϵ�����:\n");
	while (1) {
		scanf("%d", &id);
		//id�Ƿ���У��
		if (id < 0 || id >= add_book->size) {
			printf("��������������,����������:\n");
			continue;
		}
		break;
	}
	//������ǰ�±�������һ��Ԫ�ص���Ϣ;
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
	printf("ɾ���ɹ�!\n");

}
void FindPersonPhone(phoneBook* add_book) {
	printf("������ϵ��!\n");
	char name[1024] = { 0 };
	int count = 0;
	printf("��������Ҫ���ҵ���ϵ������:\n");
	scanf("%s", name);
	
	int i = 0;
	for (i = 0; i < add_book->size; i++) {
		personPhoneBook* info = &add_book->personPhoneInfo[i];
		//ƥ����ϵ������,ע��������ӡ���
		if (strcmp(name, info->name) == 0) {
			printf("[%d] ����: %s\t�Ա�:%s\t����:%s\t�绰: %s\tסַ:%s\n", i, info->name, info->gender, info->age, info->phone, info->address);

			//printf("[%d] ����: %s\t �绰: %s\n", i, info->name, info->phone);
			count++;
		}
	}
	printf("���ҵ����� %d λ��ϵ��!\n", count);
	
}
void PrintfPersonPhone(phoneBook* add_book) {
	//��ӡ������ϵ����Ϣ
	int i = 0;
	for (i = 0; i < add_book->size; i++) {
		personPhoneBook* info = &add_book->personPhoneInfo[i];
		printf("[%d] ����: %s\t�Ա�:%s\t����:%s\t�绰: %s\tסַ:%s\n", i, info->name, info->gender, info->age, info->phone,info->address);
	}
	printf("����ӡ�� %d ����ϵ��!\n", add_book->size);
}
void ClearPersonPhone(phoneBook* add_book) {
	printf("ɾ��ȫ����ϵ��!!!����һ��Σ�ղ���!!!\n");
	printf("�˲���������,�����ȷ��ɾ��������ϵ����? Y/N?\n");
	char choice[1024] = { 0 };
	scanf("%s", choice);
	if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0){
		add_book->size = 0;
		printf("��ɾ��������ϵ��!\n");
		return;
	}
	else {
		printf("�˳�ɾ��������ϵ�˲���!\n");
		return;
	}
	
}
void RankPersonPhone(phoneBook* add_book) {
	printf("������������ĸ����������ϵ��!");
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
//	//[0, bound)Ϊ��������;
//	for (bound = 0; bound < size; bound++) {
//
//	}
//}

typedef void(*Fun)(phoneBook*);
//ת�Ʊ�ʵ��if elseif ������ ;Fun func[]Ҫע��д��
Fun func[] = {
	NULL,				  //NULL�����������Ϊ��ռλ,�������Ӧ 
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
	//ͨѶ¼��ʼ��
	phoneBookInit(&address_book);
	while (1) {
		int choice = menu();
		if (choice == 0) {
			printf(" goodbye!\n");
			break;
		}
		func[choice](&address_book);			//����ת�Ʊ�ִ�к���
		
	}
	
	system("pause");
	return 0;
}