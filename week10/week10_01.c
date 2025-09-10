// 10주차 실습1. 도서관 프로그램 확장(+관리자 모드)  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct Book_list {
	int id;
	char* title;
	int num;
}Book;

// 도서 목록 선언
Book* lib;
int count = 0;

int initial_booklist();
int manage_booklist();
int admin_check();
int print_booklist();

void main(int argc, char* argv[]) {
	lib = (Book*)malloc(sizeof(Book));
	// 도서목록 초기화
	initial_booklist();

	// 프로그램 시작, 모드 선택
	char option[20];
	strcpy(option, argv[1]);
	/* printf("Enter Mode (admin or user) : ");
	scanf("%s", option); */
	if (strcmp(option, "admin") == 0) {
		printf("========== Login ==========\n");
		admin_check();
	}
	else if (strcmp(option, "user") == 0) {
		printf("========== User Mode ==========\n");
		manage_booklist();
	}
	else {
		printf("Wrong option. Try again.");
		return 0;
	}

	// free
	for (int i = 0; i < count; i++) {
		free(lib[i].title);
	}
	free(lib);
}

int initial_booklist() {
	// 구조체에 책 목록 읽어오기
	FILE* book = fopen("books.txt", "r");
	char waste[20];
	fscanf(book, "%s\t\t%s\n", waste, waste);
	while (1) {
		char waste[20];
		int n;
		if (feof(book))
			break;
		lib = (Book*)realloc(lib, sizeof(Book) * (count + 1));
		lib[count].id = count + 1;
		char tmp[50];
		fscanf(book, "%[^\t]s", tmp);
		lib[count].title = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
		tmp[strlen(tmp)] = '\0';
		strcpy(lib[count].title, tmp);
		fgets(tmp, 50, book);
		for (int i = 0; i < strlen(tmp); i++) {
			if (tmp[i] != '\t') {
				n = (int)tmp[i] - 48;
				break;
			}
		}
		lib[count].num = n;
		count++;
	}
	fclose(book);
}

int manage_booklist() {
	int bo_num = 0;
	int check = 0;
	int* bo_list = (int*)malloc(sizeof(int) * 1);
	int n;
	while (1) {
		// 책 리스트 출력
		printf("========== Book list ==========\n");
		for (int i = 0; i < count; i++) {
			printf("%-2d : %-35s %d\n", lib[i].id, lib[i].title, lib[i].num);
		}
		printf("=================================\n");
		// 책 id 입력 받기
		printf("Type the book id to borrow(0 to end) : ");
		scanf("%d", &n);

		// 0 입력시 프로그램 종료
		if (n == 0) {
			printf("Exit the program.\n");
			break;
		}
		// 목록에 없는 책일 경우
		else if (n > count) {
			printf("There is no the book on list.\n");
			printf("=========== Borrowed Book List ============\n");
			for (int i = 0; i < bo_num; i++) {
				printf("%-2d : %-35s\n", lib[i].id, lib[i].title);
			}
		}
		// 책 재고가 없을 경우
		else if (lib[n - 1].num == 0) {
			printf("The Book is out of stock.\n");
		}
		// 책 대여
		else {
			printf("Borrow a Book.\n");
			bo_num++;
			check = 1;
			lib[n - 1].num--;
			printf("%d Books Left.\n", lib[n - 1].num);
		}
		// 추가 대여한 책 없다면 출력 안 함.
		// 대여한 책 목록 출력
		if (bo_num > 0 && check == 1) {
			printf("=========== Borrowed Book List ============\n");
			bo_list = (int*)realloc(bo_list, sizeof(int) * bo_num);
			bo_list[bo_num - 1] = n;
			for (int i = 0; i < bo_num; i++) {
				printf("%d : %s\n", bo_list[i], lib[bo_list[i] - 1].title);
			}
			check = 0;
		}
	}
	// free
	free(bo_list);
}

int admin_check() {
	FILE* auth = fopen("admin_auth.txt", "r");
	char waste[20];
	char id_data[20];
	char pw_data[20];

	// 올바른 아이디 데이터 받아오기
	fscanf(auth, "%s  %s\n", waste, id_data);
	fscanf(auth, "%s  %s\n", waste, pw_data);

	char id[20];
	char pw[20];

	char opt[20];

	while (1) {
		// 로그인
		printf("Enter the Admin Auth (Exit to end)\n");
		printf("ID : ");
		scanf("%s", id);
		// ID 입력
		if (strcmp(id_data, id) == 0) {
			// ID 맞을 경우 PW 입력
			printf("Password : ");
			scanf("%s", pw);
			if (strcmp(pw_data, pw) == 0) {
				// Admin mode 접속
				printf("Admin Authenticated. Access Successful.\n");
				printf("========== Admin Mode ==========\n");
				// 보유 도서 현황 출력
				print_booklist();
				while (1) {
					// 모드 전환 혹은 종료 선택
					printf("Switch the Mode (User or Exit) : ");
					scanf("%s", opt);
					if (strcmp(opt, "User") == 0) {
						printf("========== User Mode ==========\n");
						manage_booklist();
						break;
					}
					else if (strcmp(opt, "Exit") == 0) {
						printf("Exit the program.\n");
						break;
					}
					else {
						printf("Wrong option. Try again.\n");
					}
				}
			}
			else {
				// ID는 맞고 PW는 틀렸을 경우
				printf("Wrong Password. Try again.\n");
			}
		}
		else if (strcmp(id, "Exit") == 0) {
			// 프로그램 종료 (ID 입력에서 종료)
			printf("Exit the program.\n");
			break;
		}
		else {
			// ID 틀린 경우
			printf("Wrong ID. Try again.\n");
		}
		// admin 모드 접속 후 user 모드로 넘어가거나 프로그램 종료 시 반복문 종료
		if (strcmp(opt, "User") == 0 || strcmp(opt, "Exit") == 0)
			break;
	}

	// 파일 닫기
	fclose(auth);
}

int print_booklist() {
	// 책 재고 출력
	printf("========== Book Inventory ==========\n");
	for (int i = 0; i < count; i++)
		printf("%-2d : %-35s %d\n", lib[i].id, lib[i].title, lib[i].num);
	printf("=================================\n");
}