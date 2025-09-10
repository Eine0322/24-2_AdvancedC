// 5주차 실습4. 로마숫자  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int romeCnt = 0;
char* rome;

int RomeNumber(int num);

int RomeNumber(int num) {
	int tmp;
	int result;
	if (num == 1000) {
		romeCnt++;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		rome[romeCnt - 1] = 'M';
		result = num - 1000;
		printf("1000 ");
	}
	else if (num >= 900) {
		romeCnt += 2;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		rome[romeCnt - 2] = 'C';
		rome[romeCnt - 1] = 'M';
		result = num - 900;
		printf("900 ");
	}
	else if (num >= 500) {
		romeCnt++;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		rome[romeCnt - 1] = 'D';
		result = num - 500;
		printf("500 ");
	}
	else if (num >= 400) {
		romeCnt += 2;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		rome[romeCnt - 2] = 'C';
		rome[romeCnt - 1] = 'D';
		result = num - 400;
		printf("400 ");
	}
	else if (num >= 100) {
		tmp = num / 100;
		romeCnt += tmp;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		for (int i = tmp; i > 0; i--)
			rome[romeCnt - i] = 'C';
		result = num - (100*tmp);
		printf("%d ", 100 * tmp);
	}
	else if (num >= 90) {
		romeCnt += 2;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		rome[romeCnt - 2] = 'X';
		rome[romeCnt - 1] = 'C';
		result = num - 90;
		printf("90 ");
	}
	else if (num >= 50) {
		romeCnt++;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		rome[romeCnt - 1] = 'L';
		result = num - 50;
		printf("50 ");
	}
	else if (num >= 40) {
		romeCnt += 2;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		rome[romeCnt - 2] = 'X';
		rome[romeCnt - 1] = 'L';
		result = num - 40;
		printf("40 ");
	}
	else if (num >= 10) {
		tmp = num / 10;
		romeCnt += tmp;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		for (int i = tmp; i > 0; i--)
			rome[romeCnt - i] = 'X';
		result = num - (10 * tmp);
		printf("%d ", 10 * tmp);
	}
	else if (num >= 9) {
		romeCnt += 2;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		rome[romeCnt - 2] = 'I';
		rome[romeCnt - 1] = 'X';
		result = num - 9;
		printf("9 ");
	}
	else if (num >= 5) {
		romeCnt++;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		rome[romeCnt - 1] = 'V';
		result = num - 5;
		printf("5 ");
	}
	else if (num >= 4) {
		romeCnt += 2;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		rome[romeCnt - 2] = 'I';
		rome[romeCnt - 1] = 'V';
		result = num - 4;
		printf("4 ");
	}
	else if (num >= 1) {
		tmp = num / 1;
		romeCnt += tmp;
		rome = (char*)realloc(rome, (sizeof(char) * romeCnt) + 1);
		for (int i = tmp; i > 0; i--)
			rome[romeCnt - i] = 'I';
		result = num - (1 * tmp);
		printf("%d ", 1 * tmp);
	}

	if (num != 0)
		printf("+ ");
	rome[romeCnt] = '\0';

	return result;
}

void main() {
	int num;
	printf("Enter the number: ");
	scanf("%d", &num);

	rome = (char*)malloc(sizeof(char));
	printf("%d = ",num);
	while (num > 0) {
		num = RomeNumber(num);
	}
	printf("%s, %d", rome, strlen(rome));
	free(rome);
}