// 실습4. 2~30 사이의 소수 구하기 (에라토스테네스의 체)  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void eratosthenes(int* num);

void eratosthenes(int* num) {
	for (int i = 1; i < 30; i++) {
		if (num[i] != 0) {
			for (int j = i + 1; j < 30; j++) {
				if (num[j] % num[i] == 0) {
					num[j] = 0;
				}
			}
		}
	}
}

int main() {
	int num[30];

	for (int i = 0; i < 30; i++) {
		num[i] = i + 1;
	}

	eratosthenes(num);

	for (int i = 1; i < 30; i++) {
		if (num[i] != 0)
			printf("%d ", num[i]);
	}

	return 0;
}