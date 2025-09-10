// 9주차 실습1. 이름과 전화번호(또는 주민번호) 저장  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef union number {
	char* phone;
	char* ID;
}Num;

typedef struct person {
	char* name;
	Num* num;
}Per;

int main() {
	Per* per;
	(Per*)per = (Per*)malloc(sizeof(Per));
	char tmp[20];
	printf("이름 --> ");
	scanf(" %s", tmp);
	(char*)per[0].name = (char*)malloc(sizeof(char) * strlen(tmp) + 1);
	strcpy(per[0].name, tmp);
	
	printf("전화번호 또는 주민번호 --> ");
	scanf(" %s", tmp);
	(Num*)per[0].num = (Num*)malloc(sizeof(Num));

	if (strlen(tmp) == 13) {
		(char*)per[0].num[0].phone = (char*)malloc((sizeof(char) * strlen(tmp)) + 1);
		strcpy(per[0].num[0].phone, tmp);
	}
	else if (strlen(tmp) == 14) {
		(char*)per[0].num[0].ID = (char*)malloc((sizeof(char) * strlen(tmp) )+ 1);
		strcpy(per[0].num[0].ID, tmp);
	}
	else {
		printf("잘못된 입력.");
		free(per[0].num);
		free(per[0].name);
		free(per);
		return 0;
	}

	printf("\n--- 구조체/공용체 혼합 활용 ---\n");
	printf("이름 ==> %s\n", per[0].name);
	printf("전화번호/주민번호 ==> %s\n", per[0].num[0]);

	if (strlen(tmp) == 13)
		free(per[0].num[0].phone);
	else if (strlen(tmp) == 14);
		free(per[0].num[0].ID);
	free(per[0].num);
	free(per[0].name);
	free(per);

	return 0;
}