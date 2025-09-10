// 5주차 실습2. 대소문자 관계없는 strcmp구현  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int my_strcmp(char* str1, char* str2);

void main() {
	char tmp[100];
	char* str[2];
	for (int i = 0; i < 2; i++) {
		printf("문장 %d : ", i+1);
		scanf(" %s", tmp);
		str[i] = (char*)malloc((sizeof(char) * strlen(tmp)) + 1);
		strcpy(str[i], tmp);
	}

	int opt = my_strcmp(str[0], str[1]);

	if (opt)
		printf("True");
	else
		printf("False");

	free(str[0]);
	free(str[1]);
}

int my_strcmp(char* str1, char* str2) {
	int result;
	for (int i = 0; i < strlen(str1); i++) {
		if (str1[i] >= 'A' && str1[i] <= 'Z')
			str1[i] += ('a' - 'A');
		if (str2[i] >= 'A' && str2[i] <= 'Z')
			str2[i] += ('a' - 'A');
	}
	result = !(strcmp(str1, str2));

	return result;
}