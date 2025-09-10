// 2024-2 adv-C 코딩테스트 -2024402055 박현지
// Step 2. 서비스 모드(user)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct menu {
	int id;
	char* name;
}Menu;

Menu* drink_list;
int drink_cnt;
Menu* snack_list;
int snack_cnt;
Menu* receipt_list;
int receipt_cnt;

int check_ID();
void reset_drink_menu();
void reset_snack_menu();
void service_mode();

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
	FILE* drink1 = fopen("drink1.txt", "r");
	char tmp[20];
	int size;
	while (1) {
		if (feof(drink1)==1)
			break;
		fgets(tmp, 20, drink1);
		size = strlen(tmp)+1;
		drink_list = (Menu*)realloc(drink_list, sizeof(Menu) * (drink_cnt + 1));
		drink_list[drink_cnt].name = (char*)malloc(sizeof(char) * size);
		if (tmp[size -2] == '\n')
			tmp[size - 2] = '\0';
		else
			tmp[size-1] = '\0';
		strcpy(drink_list[drink_cnt].name, tmp);
		drink_list[drink_cnt].id = drink_cnt + 1;
		drink_cnt++;
	}

	fclose(drink1);
}

void reset_snack_menu() {
	snack_list = (Menu*)malloc(sizeof(Menu));
	FILE* snack1 = fopen("snack1.txt", "r");
	char tmp[20];
	int size;
	while (1) {
		if (feof(snack1)==1)
			break;
		fgets(tmp, 20, snack1);
		size = strlen(tmp)+1;
		snack_list = (Menu*)realloc(snack_list, sizeof(Menu) * (snack_cnt + 1));
		snack_list[snack_cnt].name = (char*)malloc(sizeof(char) * size);
		if (tmp[size - 2] == '\n')
			tmp[size - 2] = '\0';
		else
			tmp[size-1] = '\0';
		strcpy(snack_list[snack_cnt].name, tmp);
		snack_list[snack_cnt].id = snack_cnt + 1;
		snack_cnt++;
	}

	fclose(snack1);
}

void service_mode() {
	printf("========== drink Menu ==========\n");
	for (int i = 0; i < drink_cnt; i++) {
		printf("%d : %s\n", drink_list[i].id, drink_list[i].name);
	}
	printf("\n");

	printf("========== snack Menu ==========\n");
	for (int i = 0; i < snack_cnt; i++) {
		printf("%d : %s\n", snack_list[i].id, snack_list[i].name);
	}
	printf("\n");

	receipt_list = (Menu*)malloc(sizeof(Menu));
	int opt;
	int menu_opt;
	while (1) {
		printf("Type 1 for drink, 2 for snack, 3 for buy : ");
		scanf("%d%*c",&opt);
		if (opt == 1) {
			while (1) {
				printf("Type drink id to buy : ");
				scanf("%d%*c", &menu_opt);
				if (menu_opt >= 1 && menu_opt <= drink_cnt) {
					receipt_list = (Menu*)realloc(receipt_list,sizeof(Menu) * (receipt_cnt + 1));
					receipt_list[receipt_cnt].name = (char*)malloc(sizeof(char) * (strlen(drink_list[menu_opt - 1].name)+1));
					strcpy(receipt_list[receipt_cnt].name, drink_list[menu_opt - 1].name);
					receipt_cnt++;
					printf("\n");
					break;
				}
				else
					printf("Error : Not enougt ID for drink\n");
			}
		}
		else if (opt == 2) {
			while (1) {
				printf("Type snack id to buy : ");
				scanf("%d%*c", &menu_opt);
				if (menu_opt >= 1 && menu_opt <= snack_cnt) {
					receipt_list = (Menu*)realloc(receipt_list, sizeof(Menu) * (receipt_cnt + 1));
					receipt_list[receipt_cnt].name = (char*)malloc(sizeof(char) * (strlen(snack_list[menu_opt - 1].name)+1));
					strcpy(receipt_list[receipt_cnt].name, snack_list[menu_opt - 1].name);
					receipt_cnt++;
					printf("\n");
					break;
				}
				else
					printf("Error : Not enougt ID for snack\n");
			}
		}
		else if (opt == 3) {
			printf("========== Receipt ==========\n");
			if (receipt_cnt>0) {
				for (int i = 0; i < receipt_cnt; i++) {
					printf("%s\n", receipt_list[i].name);
				}
			}
			else {
				printf("None");
			}
			break;
		}
		else {
			printf("Error : Wrong input for type select!\n");
		}
	}
}