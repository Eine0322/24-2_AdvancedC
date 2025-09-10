// 6주차 실습3. 입력 문자열을 반대로 출력하기  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void sort_Ascending(char B[][10]);
void sort_Descending(char B[][10]);
int write_result_to_file(char B[][10]);
void print_result();

void main() {
	FILE* data = fopen("data.txt", "r");

	char A[5][100];
	char B[20][10];
	int count_word = 0;
	int count_b = 0;

	for (int i = 0; i < 5; i++) {
		fgets(A[i], 100, data);
		for (int j = 0; j < 100; j++) {
			if (A[i][j] >= 'A' && A[i][j] <= 'z') {
				B[count_b][count_word] = A[i][j];
				count_word++;
			}
			else if (A[i][j] == ',') {
				B[count_b][count_word] = '\0';
				count_b++;
				count_word = 0;
			}
		}
	}
	B[count_b][count_word] = '\0';

	write_result_to_file(B);

	print_result();

	fclose(data);
}

int write_result_to_file(char B[][10]) {
	FILE* as = fopen("Result_Ascending.txt", "w");
	FILE* des = fopen("Result_Descending.txt", "w");

	sort_Ascending(B);
	for (int i = 0; i < 19; i++) {
		fprintf(as, "%s\n", B[i]);
	}

	sort_Descending(B);
	for (int i = 0; i < 19; i++) {
		fprintf(des, "%s\n", B[i]);
	}

	fclose(as);
	fclose(des);
}

void sort_Ascending(char B[][10]) {
	char tmp[10];
	for (int j = 0; j < 19; j++) {
		for (int k = j; k < 19; k++) {
			if (strcmp(B[j], B[k]) > 0) {
				strcpy(tmp, B[k]);
				strcpy(B[k], B[j]);
				strcpy(B[j], tmp);
			}
		}
	}
}

void sort_Descending(char B[][10]) {
	char tmp[10];
	for (int j = 0; j < 19; j++) {
		for (int k = j; k < 19; k++) {
			if (strcmp(B[j], B[k]) < 0) {
				strcpy(tmp, B[k]);
				strcpy(B[k], B[j]);
				strcpy(B[j], tmp);
			}
		}
	}
}

void print_result() {
	FILE* as = fopen("Result_Ascending.txt", "r");
	FILE* des = fopen("Result_Descending.txt", "r");

	char word[11];

	printf("========sorting Result========\n");
	for (int i = 0; i < 19; i++) {
		fscanf(as, "%s", word);
		printf("[%10s]\n", word);
	}
	printf("========sorting Result========\n");
	for (int i = 0; i < 19; i++) {
		fscanf(des, "%s", word);
		printf("[%10s]\n", word);
	}

	fclose(as);
	fclose(des);
}