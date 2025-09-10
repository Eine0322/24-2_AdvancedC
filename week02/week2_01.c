// 실습1. 포인터를 이용한 두 값의 교환  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap_value(int a, int b);
void swap_reference(int* a, int* b);

void swap_value(int a, int b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
	printf("\nAfter value swap(in function), A : %d, B : %d\n", a, b);
}

void swap_reference(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	printf("\nAfter value swap(in function), A : %d, B : %d\n", *a, *b);
}

int main() {
	int a, b;
	printf("Input Value to Swap (A B) : ");
	scanf("%d %d", &a, &b);

	printf("\nBefore swap, A : %d, B : %d\n", a, b);

	swap_value(a, b);
	printf("After value swap(in main), A : %d, B : %d\n", a, b);

	swap_reference(&a, &b);
	printf("Reference value swap(in main), A : %d, B : %d\n", a, b);

	return 0;
}