// 12주차 실습2. 간단한 연결 리스트 생성 프로그램 확장  2024402055 박현지
// 삭제함수 별도로 만들기!
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
Num* cur = NULL;

int del_Node(int num);

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
		if (num < 0)
			del_Node(num);
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

int del_Node(int num) {
	Num* cnt = head;
	Num* pre = head;

	int N = num * num;

	while (cnt == head) {
		if (cnt->n * cnt->n == N) {
			del = cnt;
			head = cnt->next;
			cnt = head;
			free(del);
		}
		else {
			cnt = cnt->next;
		}
	}

	while (cnt != tail&&cnt!=head) {
		if (cnt->n * cnt->n == N) {
			del = cnt;
			pre->next = cnt->next;
			cnt = cnt->next;
			free(del);
		}
		else {
			pre = cnt;
			cnt = cnt->next;
		}
	}
}