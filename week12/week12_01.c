// 12주차 실습1. 간단한 연결 리스트 생성 프로그램 작성  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct number {
	int n;
	struct number* next;
}Num;

Num* head = NULL;
Num* tail = NULL;
Num* del = NULL;
Num* cur=NULL;

int main() {	
	int num;
	while (1) {
		printf("Number (0 to end) : ");
		scanf("%d%*c", &num);
		if (num == 0)
			break;
		cur = (Num*)malloc(sizeof(Num));
		cur->n = num;
		cur->next = NULL;
		if (head == NULL) {
			head = cur;
			tail = cur;
		}
		else {
			tail->next = cur;
			tail = cur;
		}
	}

	printf("\nNumber : ");
	cur = head;
	while (cur) {
		printf("%d ", cur->n);
		cur = cur->next;
	}

	cur = head;
	while (cur) {
		del = cur;
		cur = cur->next;
		free(del);
	}
}