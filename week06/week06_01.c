// 6주차 실습1. 입력 문자열을 반대로 파일에 저장하기  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main() {
	char* ss[3];
	char tmp[100];
	FILE* output = fopen("output1.txt", "w");

	for (int i = 0; i < 3; i++) {
		printf("%d 번째 문자열 : ", i + 1);
		scanf(" %[^\n]s", tmp);
		ss[i] = (char*)malloc(sizeof(char) * strlen(tmp) + 1);
		strcpy(ss[i], tmp);
	}

	fprintf(output,"-- 입력과 반대로 출력(포인터) : 글자 순서도 거꾸로 --\n");
	for (int i = 2; i >= 0; i--) {
		fprintf(output,"%d :", i + 1);
		for (int j = strlen(ss[i]) - 1; j >= 0; j--)
			fprintf(output,"%c", ss[i][j]);
		fprintf(output,"\n");
	}

	for (int i = 0; i < 3; i++)
		free(ss[i]);
	fclose(output);
}