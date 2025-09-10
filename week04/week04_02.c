// 4주차 실습2. 사용자 입력 숫자 중 짝수만 더하기  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void main() {
	int* p;
	int hap = 0;
	int cnt=1;

	p = (int*)malloc(sizeof(int) * cnt);

	while(1) {
		p = (int*)realloc(p, sizeof(int) * cnt);
		printf(" %d 번째 숫자 : ", cnt);
		scanf("%d", p + (cnt-1));
		if (*(p + (cnt-1)) == 0)
			break;
		cnt++;
	}

	for (int i = 0; i < cnt - 1; i++) {
		if (*(p + i) % 2 == 0)
			hap += *(p + i);
	}

	printf("입력한 짝수합 ==> %d", hap);

	free(p);
}