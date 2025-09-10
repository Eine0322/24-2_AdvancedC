// 5주차 실습3. 문자열 세로로 읽기  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() {
	int n;
	printf("입력할 문자열 개수 입력: ");
	scanf("%d", &n);
	char** str = (char**)malloc(sizeof(char*) * n);
	char tmp[100];
	int max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp);
		if (max <= strlen(tmp))
			max = strlen(tmp) + 1;
		str[i] = (char*)malloc(sizeof(char) * max);
		strcpy(str[i], tmp);
		for (int j = strlen(tmp); j < max; j++)
			str[i][j] = '\0';
	}

	printf("\n");
	for (int i = 0; i < max-1; i++) {
		for (int j = 0; j < n; j++) {
			if (str[j][i] != '\0'); {
				printf("%c", str[j][i]);
			}
		}
	}

	for (int i = 0; i < n; i++)
		free(str[i]);
	free(str);
}