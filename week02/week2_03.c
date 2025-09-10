// 실습3. 원의 넓이와 둘레 구하기  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const double pi = 3.14;

float circle_area(int r);
float circumference(int r);

float circle_area(int r) {
	float value;
	value = r * r * pi;

	return value;
}

float circumference(int r) {
	float value;
	value = 2 * r * pi;

	return value;
}

int main() {
	int r;
	printf("넓이 /둘레 를 수할 원의 반지름을 입력하시오 : ");
	scanf("%d", &r);
	printf("입력한 반지름 : %d에 대한\n", r);
	printf("원의 넓이는 %f\n", circle_area(r));
	printf("원의 둘레는 %f", circumference(r));

	return 0;
}