// 5주차 실습1. 문자열 소문자 대문자 변환기  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main() {
	char tmp[100];
	printf("변환 전 문장 입력(길이 제한 100)\n");
	scanf(" %s", tmp);
	char* ss = (char*)malloc((sizeof(char) * strlen(tmp))+1);
	strcpy(ss, tmp);

	printf("\n변환 후");
	int gap = 'a' - 'A';
	for (int i = 0; i < strlen(ss); i++) {
		if (ss[i] >= 'A' && ss[i] <= 'Z')
			ss[i] += gap;
		else if (ss[i] >= 'a' && ss[i] <= 'z')
			ss[i] -= gap;
	}
	printf("\n%s", ss);

	free(ss);
}