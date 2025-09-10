// 8주차 실습2. 학생 이름과 나이 출력 프로그램  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct student {
	char name[30];
	int age;
} Stu;

void main() {
	int n;
	printf("입력할 학생 수 : ");
	scanf("%d", &n);
	
	Stu* stu = (Stu*)malloc(sizeof(Stu) * n);
	for (int i = 0; i < n; i++) {
		printf("이름과 나이 입력 : ");
		scanf(" %s %d", stu[i].name, &stu[i].age);
	}

	printf("\n-- 학생 명단 --\n");
	for (int i = 0; i < n; i++) {
		printf("이름:%s , 나이:%d\n", stu[i].name, stu[i].age);
	}

	free(stu);
}