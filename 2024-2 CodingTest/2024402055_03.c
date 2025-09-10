// 2024-2 adv-C 코딩테스트 -2024402055 박현지
// Step 3. 서비스 모드(user) 확장: 가격, 재고 기능
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct menu {
	int id;
	char* name;
	int cost;
	int inventory;
}Menu;

Menu* drink_list;
int drink_cnt;
Menu* snack_list;
int snack_cnt;
Menu* receipt_list;
int receipt_cnt;
int total_cost = 0;

int check_ID();
void reset_drink_menu();
void reset_snack_menu();
void service_mode();
void print_receipt();

int main() {
	drink_cnt = 0;
	snack_cnt = 0;
	receipt_cnt = 0;
	int mode;
	mode = check_ID();
	if (mode == 0) {
		printf("Admin mode\n");
	}
	else if (mode == 1) {
		printf("User mode\n");
		reset_drink_menu();
		reset_snack_menu();
		service_mode();
	}

	for (int i = 0; i < drink_cnt; i++)
		free(drink_list[i].name);
	free(drink_list);
	for (int i = 0; i < snack_cnt; i++)
		free(snack_list[i].name);
	free(snack_list);
	for (int i = 0; i < receipt_cnt; i++)
		free(receipt_list[i].name);
	free(receipt_list);
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

void reset_drink_menu() {
	drink_list = (Menu*)malloc(sizeof(Menu));
	FILE* drink2 = fopen("drink2.txt", "r");
	char tmp[40];
	int size;
	while (1) {
		if (feof(drink2) == 1)
			break;
		fgets(tmp, 40, drink2);
		size = strlen(tmp);
		char tmp_name[20] ="";
		char tmp_cost[6]="";
		char tmp_inven[3]="";
		int name_cnt = 0;
		int cost_cnt = 0;
		int inven_cnt = 0;
		drink_list = (Menu*)realloc(drink_list, sizeof(Menu) * (drink_cnt + 1));
		for (int i = 0; i < size;) {
			if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
				while (tmp[i] != '\t') {
					tmp_name[name_cnt++] = tmp[i];
					i++;
				}
				drink_list[drink_cnt].name = (char*)malloc(sizeof(char) * name_cnt+1);
				tmp_name[name_cnt] = '\0';
				strcpy(drink_list[drink_cnt].name, tmp_name);
			}
			else if (tmp[i - 2] >= 'a' && tmp[i - 2] <= 'z') {
				while (tmp[i] != '\t') {
					tmp_cost[cost_cnt++] = tmp[i];
					i++;
				}
				drink_list[drink_cnt].cost = atoi(tmp_cost);
			}
			else if (tmp[i - 2] >= '0' && tmp[i - 2] <= '9') {
				while (1) {
					if (i == size)
						break;
					tmp_inven[inven_cnt++] = tmp[i];
					i++;
				}
				drink_list[drink_cnt].inventory = atoi(tmp_inven);
			}
			i++;
		}
		drink_list[drink_cnt].id = drink_cnt + 1;
		drink_cnt++;
	}

	fclose(drink2);
}

void reset_snack_menu() {
	snack_list = (Menu*)malloc(sizeof(Menu));
	FILE* snack2 = fopen("snack2.txt", "r");
	char tmp[40];
	char tmp_name[20];
	char tmp_cost[6];
	char tmp_inven[3];
	int size;
	while (1) {
		if (feof(snack2) == 1)
			break;
		fgets(tmp, 40, snack2);
		size = strlen(tmp);
		int name_cnt = 0;
		int cost_cnt = 0;
		int inven_cnt = 0;
		snack_list = (Menu*)realloc(snack_list, sizeof(Menu) * (snack_cnt + 1));
		for (int i = 0; i < size;) {
			if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
				while (tmp[i] != '\t') {
					tmp_name[name_cnt++] = tmp[i];
					i++;
				}
				snack_list[snack_cnt].name = (char*)malloc(sizeof(char) * name_cnt + 1);
				tmp_name[name_cnt] = '\0';
				strcpy(snack_list[snack_cnt].name, tmp_name);
			}
			else if (tmp[i - 2] >= 'a' && tmp[i - 2] <= 'z') {
				while (tmp[i] != '\t') {
					tmp_cost[cost_cnt++] = tmp[i];
					i++;
				}
				snack_list[snack_cnt].cost = atoi(tmp_cost);
			}
			else if (tmp[i - 2] >= '0' && tmp[i - 2] <= '9') {
				while (1) {
					if (i == size)
						break;
					tmp_inven[inven_cnt++] = tmp[i];
					i++;
				}
				snack_list[snack_cnt].inventory = atoi(tmp_inven);
			}
			i++;
		}
		snack_list[snack_cnt].id = snack_cnt + 1;
		snack_cnt++;
	}

	fclose(snack2);
}

void service_mode() {
	printf("========== drink Menu ==========\n");
	for (int i = 0; i < drink_cnt; i++) {
		printf("%d : %s  %d  %d\n", drink_list[i].id, drink_list[i].name,drink_list[i].cost,drink_list[i].inventory);
	}
	printf("\n");

	printf("========== snack Menu ==========\n");
	for (int i = 0; i < snack_cnt; i++) {
		printf("%d : %s  %d  %d\n", snack_list[i].id, snack_list[i].name,snack_list[i].cost,snack_list[i].inventory);
	}
	printf("\n");

	receipt_list = (Menu*)malloc(sizeof(Menu));
	int opt;
	int menu_opt;
	
	while (1) {
		printf("Type 1 for drink, 2 for snack, 3 for buy : ");
		scanf("%d%*c", &opt);
		if (opt == 1) {
			while (1) {
				printf("Type drink id to buy : ");
				scanf("%d%*c", &menu_opt);
				if (menu_opt >= 1 && menu_opt <= drink_cnt && drink_list[menu_opt - 1].inventory > 0) {
					receipt_list = (Menu*)realloc(receipt_list, sizeof(Menu) * (receipt_cnt + 1));
					receipt_list[receipt_cnt].name = (char*)malloc(sizeof(char) * (strlen(drink_list[menu_opt - 1].name) + 1));
					strcpy(receipt_list[receipt_cnt].name, drink_list[menu_opt - 1].name);
					receipt_list[receipt_cnt].cost = drink_list[menu_opt - 1].cost;
					total_cost += drink_list[menu_opt - 1].cost;
					drink_list[menu_opt - 1].inventory--;
					receipt_cnt++;
					printf("\n");
					break;
				}
				else if (drink_list[menu_opt - 1].inventory == 0)
					printf("Out of stock!\n");
				else
					printf("Error : Not enougt ID for drink\n");
			}
		}
		else if (opt == 2) {
			while (1) {
				printf("Type snack id to buy : ");
				scanf("%d%*c", &menu_opt);
				if (menu_opt >= 1 && menu_opt <= snack_cnt && snack_list[menu_opt - 1].inventory > 0) {
					receipt_list = (Menu*)realloc(receipt_list, sizeof(Menu) * (receipt_cnt + 1));
					receipt_list[receipt_cnt].name = (char*)malloc(sizeof(char) * (strlen(snack_list[menu_opt - 1].name) + 1));
					strcpy(receipt_list[receipt_cnt].name, snack_list[menu_opt - 1].name);
					receipt_list[receipt_cnt].cost = snack_list[menu_opt - 1].cost;
					total_cost += snack_list[menu_opt - 1].cost;
					snack_list[menu_opt - 1].inventory--;
					receipt_cnt++;
					printf("\n");
					break;
				}
				else if (snack_list[menu_opt - 1].inventory == 0)
					printf("Out of stock!\n");
				else
					printf("Error : Not enougt ID for snack\n");
			}
		}
		else if (opt == 3) {
			print_receipt();
			break;
		}
		else {
			printf("Error : Wrong input for type select!\n");
		}
	}
}

void print_receipt() {
	printf("========== Receipt ==========\n");
	for (int i = 0; i < receipt_cnt; i++) {
		printf("%-15s%d\n", receipt_list[i].name, receipt_list[i].cost);
	}
	printf("Total : %d\n============================", total_cost);

	FILE* receipt = fopen("receipt.txt", "w");
	for (int i = 0; i < receipt_cnt; i++) {
		fprintf(receipt,"%s\t%d\n", receipt_list[i].name, receipt_list[i].cost);
	}
	fprintf(receipt, "Total : %d", total_cost);
	fclose(receipt);
}