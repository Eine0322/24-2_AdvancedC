// 실습6. 오름차순 내림차순 구현하기 (문자열)  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int input_char(char* str);
void func_sort(char* str, int sort);
void func_print(char* str);

int input_char(char* str) {
	char sort_method[30];
	printf("Enter Text : ");
	scanf("%s", str);
	printf("Sorting Method (오름차순 or 내림차순) : ");
	scanf("%s", sort_method);
	if (strcmp(sort_method,"오름차순")) {
		return 0;
	}
	else if (strcmp(sort_method,"내림차순")){
		return 1;
	}
	else {
		printf("Try again\n");
	}
}

void func_sort(char* str, int sort) {
	int tmp;
	if (sort == 0) {
		for (int i = 0; i < strlen(str); i++) {
			for (int j = i; j < strlen(str); j++) {
				if (str[i] < str[j]) {
					tmp =str[i];
					str[i] = str[j];
					str[j] = tmp;
				}
			}
		}
	}
	else if (sort == 1) {
		for (int i = 0; i < strlen(str); i++) {
			for (int j = i; j < strlen(str); j++) {
				if (str[i] > str[j]) {
					tmp = str[i];
					str[i] = str[j];
					str[j] = tmp;
				}
			}
		}
	}
}

void func_print(char* str) {
	str[strlen(str)] = '\0';
	printf("%s",str);
}

int main() {
	char str[101];
	int sort;
	sort = input_char(str);

	func_sort(str, sort);
	func_print(str);
}