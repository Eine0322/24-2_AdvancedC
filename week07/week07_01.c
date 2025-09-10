// 7주차 실습1. 구구단 출력 프로그램  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int dan;
	printf("출력하고 싶은 단을 입력 : ");
	scanf("%d", &dan);
	char file[20] = { 0 };
	sprintf(file, "%d_dan.txt", dan);

	FILE* gugu = fopen(file, "w");

	for (int i = 1; i <= 9; i++) {
		fprintf(gugu, "%d X %d = %d\n", dan, i, dan * i);
	}

	printf("%d_dan.txt에 결과를 저장", dan);

	fclose(gugu);
}