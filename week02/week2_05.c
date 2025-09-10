// 실습5. 오름차순 내림차순 구현하기  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

void sort_Ascending(int* arr);
void sort_Descending(int* arr);

void sort_Ascending(int* arr) {
	int tmp;
	for (int i = 0; i < 100; i++) {
		for (int j = i; j < 100; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void sort_Descending(int* arr) {
	int tmp;
	for (int i = 0; i < 100; i++) {
		for (int j = i; j < 100; j++) {
			if (arr[i] < arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main() {
	int arr[100];
	
	printf("Before sort==================\n");
	for (int i = 0; i < 100; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}

	printf("\n\nAfter Ascending Sort============\n");
	sort_Ascending(arr);
	for (int i = 0; i < 100; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n\nAfter Descending Sort============\n");
	sort_Descending(arr);
	for (int i = 0; i < 100; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}