// 4주차 실습4. 사용자 문자열을 합하여 출력하기  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main() {
	char* ss[3];
	char tmp[100];

	for (int i = 0; i < 2; i++) {
		printf("%d 번째 문자열 : ", i + 1);
		scanf(" %[^\n]s", tmp);
		ss[2-i] = (char*)malloc(sizeof(char) * strlen(tmp) + 1);
		strcpy(ss[2-i], tmp);
	}
	ss[0] = (char*)malloc(sizeof(char) * strlen(ss[2]) + 1);
	strcpy(ss[0], ss[2]);
	ss[2] = (char*)realloc(ss[2], sizeof(char) * (strlen(ss[2]) + strlen(ss[1]) + 1));
	strcat(ss[2], ss[1]);

	printf("\n결과=============================\n");
	for (int i = 0; i < 3; i++) {
		printf("%d : %s\n", i + 1, ss[i]);
		free(ss[i]);
	}
}