// 도서 목록에 따라 수정 필요함.
// 9주차 실습1. 도서관 도서 대여 프로그램  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct Book_list {
	int id;
	char* title;
	int num;
}Book;

int initial_booklist(int count, Book* lib,int n);
int manage_booklist(int count, Book* lib);

int main() {
	// 구조체에 책 목록 읽어오기
	FILE* book = fopen("books.txt", "r");
	int count = 0;
	Book* lib = (Book*)malloc(sizeof(Book) * (count + 1));
	char waste[20];
	fscanf(book, "%s\t\t%s\n", waste,waste);
	while (1) {
		char waste[20];
		int n;
		if (feof(book)) 
			break;
		lib = (Book*)realloc(lib, sizeof(Book) * (count + 1));
		lib[count].id = count + 1;
		char tmp[50];
		fscanf(book, "%[^\t]s",tmp);
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
		initial_booklist(count, lib, n);
		count++;
	}
	fclose(book);
	// 대여 프로그램 시작
	manage_booklist(count, lib);

	// free
	for (int i = 0; i < count; i++) {
		free(lib[i].title);
	}
	free(lib);
}

int initial_booklist(int count, Book* lib, int n) {
	lib[count].num = n;
}

int manage_booklist(int count, Book* lib) {
	int bo_num = 0;
	int check = 0;
	int* bo_list = (int*)malloc(sizeof(int) * 1);
	int n;
	while (1) {
		// 책 리스트 출력
		printf("========== Book list ==========\n");
		for (int i = 0; i < count; i++) {
			printf("%d : %s\n", lib[i].id, lib[i].title);
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
				printf("%d : %s\n", bo_list[i], lib[bo_list[i] - 1].title);
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