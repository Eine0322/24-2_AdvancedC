// 실습2. 포인터를 이용한 배열 처리  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap_index(int* a);
void swap_pointer(int* a1, int* a2);

void swap_index(int* a) {
	int tmp;
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

void swap_pointer(int* a1, int* a2) {
	int tmp;
	tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}

int main() {
	int a[2];
	printf("Before Swap: ");
	scanf("%d %d", &a[0], &a[1]);
	swap_index(a);
	printf("Swap by index : %d %d\n\n", a[0], a[1]);

	printf("Before Swap: ");
	scanf("%d %d", &a[0], &a[1]);
	swap_pointer(&a[0], &a[1]);
	printf("Swap by index : %d %d\n\n", a[0], a[1]);

	return 0;
}