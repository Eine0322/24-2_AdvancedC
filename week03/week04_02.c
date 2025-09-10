// 4주차 실습2. 행렬 내 합 계산  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a[4][8] = { 0 };
	int x = 1, y = 1;
	int p1, p2;

	// 0이 아닌 수 입력 받기
	printf("숫자 8개를 입력하세요.\n");
	for (int i = 0; i < 8; i++)
	{
		scanf(" %d", (*a + i)); // 입력값
		if (*(*a + i) == 0) {
			printf("처음부터 다시 입력해주세요.");
			return 0;
		}
	}

	// 인접한 값 더하기
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 7; k += 2 * x) {
			p1 = *(*(a + i) + k);
			p2 = *(*(a + i) + (k+y));

			*(*(a + (i + 1)) + k) = p1 + p2;
		}
		x++;
		y *= 2;
	}

	// 배열 출력하기
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 8; k++) {
			printf("%3d ", *(*(a + i) + k));
		}
		printf("\n");
	}
}