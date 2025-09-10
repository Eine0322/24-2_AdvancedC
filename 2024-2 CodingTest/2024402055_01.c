// 2024-2 adv-C 코딩테스트 -2024402055 박현지
// Step 1. 관리자모드, 서비스 모드 진입
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int check_ID();

void main() {
	int mode = check_ID();
	if (mode == 0) {
		printf("Admin mode\n");
	}
	else if (mode == 1) {
		printf("User mode\n");
	}
}

int check_ID() {
	char mode[10];
	while (1) {
		printf("Mode Select (admin or user) : ");
		scanf("%s%*c", mode);
		if (strcmp(mode, "admin") == 0)
			return 0;
		else if (strcmp(mode, "user") == 0)
			return 1;
		else
			printf("Error : Wrong Input!\n");
	}
}