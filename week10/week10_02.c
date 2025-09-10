// 10주차 실습2. POS 프로그램 확장 2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct menu {
	int id;
	char* name;
	float cost;
}Menu;

Menu* drink;
Menu* dessert;
Menu* receipt;
int drink_cnt = 0;
int dessert_cnt = 0;
int receipt_cnt = 0;
float total_cost = 0;

int Initial_menulist(); // 음료, 디저트 메뉴 리스트 초기화
int drink_count(); // 음료 주문 처리
int dessert_count(); // 디저트 주문 처리
int print_receipt(); // 영수증 출력

void main() {
	drink = (Menu*)malloc(sizeof(Menu));
	dessert = (Menu*)malloc(sizeof(Menu));
	receipt = (Menu*)malloc(sizeof(Menu));

	Initial_menulist();

	// 옵션 선택
	int opt;
	while(1) {
		printf("1. 음료 주문하기\n2. 디저트 주문하기\n0. 종료         ::      ");
		scanf("%d", &opt);
		if (opt == 1)
			drink_count();
		else if (opt == 2)
			dessert_count();
		else if (opt == 0&&receipt_cnt>0) {
			print_receipt();
			printf("영수증이 Receipt.txt에 저장되었습니다.");
			break;
		}
		else {
			printf("프로그램을 종료합니다.");
			break;
		}
	}

	// free
	for (int i = 0; i < drink_cnt; i++)
		free(drink[i].name);
	free(drink);
	for (int i = 0; i < dessert_cnt; i++)
		free(dessert[i].name);
	free(dessert);
	for (int i = 0; i < receipt_cnt; i++)
		free(receipt[i].name);
	free(receipt);
}

int Initial_menulist() {
	FILE* drink_list = fopen("drink.txt", "r");

	char tmp[50];
	int name_cnt;
	int cost_cnt;

	// drink 초기화
	while (1) {
		if (feof(drink_list)==1)
			break;
		fgets(tmp, 50, drink_list);
		char name_tmp[20];
		name_cnt = 0;
		char cost_tmp[5];
		cost_cnt = 0;
		for (int i = 0; i < strlen(tmp); i++) {
			if ((tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == '.')
				cost_tmp[cost_cnt++] = tmp[i];
			else
				name_tmp[name_cnt++] = tmp[i];
		}
		if (name_tmp[name_cnt - 1] == '\n')
			name_tmp[name_cnt - 2] = '\0';
		name_tmp[name_cnt - 1] = '\0';
		drink = (Menu*)realloc(drink,sizeof(Menu) * (drink_cnt + 1));
		drink[drink_cnt].name = (char*)malloc(sizeof(char) * (name_cnt));
		strcpy(drink[drink_cnt].name, name_tmp);
		drink[drink_cnt].cost = atof(cost_tmp); //문자열을 실수형으로 바꿈
		drink[drink_cnt].id = drink_cnt + 1;
		drink_cnt++;
	}
	fclose(drink_list);

	// dessert 초기화
	FILE* dessert_list = fopen("dessert.txt", "r");
	while (1) {
		if (feof(dessert_list)==1)
			break;
		fgets(tmp, 50, dessert_list);
		char name_tmp[20];
		name_cnt = 0;
		char cost_tmp[5];
		cost_cnt = 0;
		for (int i = 0; i < strlen(tmp); i++) {
			if ((tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == '.')
				cost_tmp[cost_cnt++] = tmp[i];
			else
				name_tmp[name_cnt++] = tmp[i];
		}
		if (name_tmp[name_cnt - 1] == '\n')
			name_tmp[name_cnt - 2] = '\0';
		name_tmp[name_cnt - 1] = '\0';
		dessert = (Menu*)realloc(dessert, sizeof(Menu) * (dessert_cnt + 1));
		dessert[dessert_cnt].name = (char*)malloc(sizeof(char) * (name_cnt));
		strcpy(dessert[dessert_cnt].name, name_tmp);
		dessert[dessert_cnt].cost = atof(cost_tmp);
		dessert[dessert_cnt].id = dessert_cnt + 1;
		dessert_cnt++;
	}
	fclose(dessert_list);
}

int drink_count(){
	int opt;
	printf("주문하실 음료를 선택하세요\n\n");
	printf("drink menues\n");
	for (int i = 0; i < drink_cnt; i++) {
		printf("[%d] %-20s %.2f\n", drink[i].id, drink[i].name, drink[i].cost);
	}
	scanf("%d", &opt);
	printf("\n");

	int check = 0;
	if (receipt_cnt > 0) {
		for (int i = 0; i < receipt_cnt; i++) {
			if (strcmp(receipt[i].name, drink[opt - 1].name) == 0) {
				receipt[receipt_cnt].cost += drink[opt - 1].cost;
				receipt[i].id++;
				check = 1;
				break;
			}
		}
	}
	if (check == 0) {
		receipt = (Menu*)realloc(receipt, sizeof(Menu) * (receipt_cnt + 1));
		receipt[receipt_cnt].name = (char*)malloc(sizeof(char) * strlen(drink[opt - 1].name) + 1);
		strcpy(receipt[receipt_cnt].name, drink[opt - 1].name);
		receipt[receipt_cnt].cost = drink[opt - 1].cost;
		receipt[receipt_cnt].id = 1;
		receipt_cnt++;
	}
	
	total_cost += drink[opt - 1].cost;
}

int dessert_count() {
	int opt;
	printf("주문하실 디저트를 선택하세요\n\n");
	printf("dessert menues\n");
	for (int i = 0; i < dessert_cnt; i++) {
		printf("[%d] %-20s %.2f\n", dessert[i].id, dessert[i].name, dessert[i].cost);
	}
	scanf("%d", &opt);
	printf("\n");

	int check = 0;
	if (receipt_cnt > 0) { // 이미 주문한 메뉴일 경우 (주문 수량 증가)
		for (int i = 0; i < receipt_cnt; i++) {
			if (strcmp(receipt[i].name, dessert[opt - 1].name) == 0) {
				receipt[receipt_cnt].cost += dessert[opt - 1].cost;
				receipt[i].id++;
				check = 1;
				break;
			}
		}
	}
	if (check == 0) { // 처음 주문한 메뉴일 경우 영수증 칸 추가
		receipt = (Menu*)realloc(receipt, sizeof(Menu) * (receipt_cnt + 1));
		receipt[receipt_cnt].name = (char*)malloc(sizeof(char) * strlen(dessert[opt - 1].name) + 1);
		strcpy(receipt[receipt_cnt].name, dessert[opt - 1].name);
		receipt[receipt_cnt].cost = dessert[opt - 1].cost;
		receipt[receipt_cnt].id = 1;
		receipt_cnt++;
	}

	// 총 금액 계산
	total_cost += dessert[opt - 1].cost;
}

int print_receipt() {
	// txt 파일에 영수증 저장
	FILE* receipt_list = fopen("Receipt.txt", "w");

	fprintf(receipt_list,"======================\n        Receipt\n======================\n");
	for (int i = 0; i < receipt_cnt; i++) {
		fprintf(receipt_list,"%-18s%-13d%-7.2f\n", receipt[i].name, receipt[i].id, (float)receipt[i].id*receipt[i].cost);
	}
	fprintf(receipt_list,"======================\n");
	fprintf(receipt_list,"%-31s%-7.2f\n", "Total ::", total_cost);

	fclose(receipt_list);
}