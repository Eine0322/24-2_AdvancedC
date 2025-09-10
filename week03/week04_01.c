// 4주차 실습1. 문자열 변환 함수 구현  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 정의
int my_strcmp(char* str1, char* str2);
void my_strcat(char* str1, char* str2,char* strcat);
void my_strcpy(char* str1, char* strcpy);

int main() {
	char str1[6];
	char str2[6];
	char strcat[11];
	char strcpy[6];

	printf("Type first word : ");
	scanf("%s", str1);
	printf("Type second word : ");
	scanf("%s", str2);

	// 함수 호출 및 출력
	printf("\nmy_strcmp\n");
	if (my_strcmp(str1, str2)==1)
		printf("%s > %s\n",str1, str2);
	else if (my_strcmp(str1, str2) == -1)
		printf("%s < %s\n", str1, str2);
	else if (my_strcmp(str1, str2) == 0)
		printf("%s == %s\n", str1, str2);

	printf("\nmy_strcat\n");
	my_strcat(str1, str2, strcat);
	printf("%s + %s => %s\n", str1, str2, strcat);

	printf("\nmy_strcpy\n");
	my_strcpy(str1, strcpy);
	printf("%s == %s\n", str1, strcpy);
}

int my_strcmp(char* str1, char* str2) {
	// 문자열 비교함수
	for (int i = 0; i < 5; i++) {
		if (str1[i] > str2[i])
			return 1;
		else if (str1[i] < str2[i])
			return -1;
	}
	return 0;
}

void my_strcat(char* str1, char* str2, char* strcat) {
	// 문자열 병합 함수
	int count = 0;
	for (int i = 0; i < 6; i++) {
		if (str1[i] == '\0')
			break;
		strcat[count++] = str1[i];
	}
	for (int i = 0; i < 6; i++) {
		if (str2[i] == '\0')
			break;
		strcat[count++] = str2[i];
	}
	strcat[count] = '\0';
}

void my_strcpy(char* str1, char* strcpy) {
	// 문자열 복사 함수
	for (int i = 0; i < 6; i++) {
		strcpy[i] = str1[i];
	}
}