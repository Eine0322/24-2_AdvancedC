// 4주차 실습1. 사용자 입력 숫자 중 짝수만 더하기  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void main() {
	int* p;
	int hap = 0;
	int cnt;

	printf(" 입력할 개수는 ? ");
	scanf("%d", &cnt);

	p = (int*)malloc(sizeof(int) * cnt);

	for (int i = 0; i < cnt; i++) {
		printf(" %d 번째 숫자 : ", i + 1);
		scanf("%d", p+i);
	}

	for (int i = 0; i < cnt; i++) {
		if (*(p + i) % 2 == 0)
			hap += *(p + i);
	}

	printf("입력한 짝수합 ==> %d", hap);

	free(p);
}