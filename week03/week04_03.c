// 4주차 실습3. 좌표 대칭 프로그램  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 정의
void get_coordination(int* x_point, int* y_point);
void change_x_axis(int* x_point, int* y_point);
void change_y_axis(int* x_point, int* y_point);
void change_xy_axis(int* x_point, int* y_point);
void print_matrix(int x_point, int y_point);

int main() {
	int x_point, y_point;
	get_coordination(&x_point, &y_point);
	change_x_axis(&x_point, &y_point);
	change_y_axis(&x_point, &y_point);
	change_xy_axis(&x_point, &y_point);
	return 0;
}

void get_coordination(int* x_point, int* y_point) {
	// 사용자로부터 x, y 좌표값을 입력 받는 함수
	printf("put X coordination : ");
	scanf("%d", x_point);
	printf("put Y coordination : ");
	scanf("%d", y_point);
	printf("\n");
	print_matrix(*x_point, *y_point);
}

void change_x_axis(int* x_point, int* y_point) {
	// 입력받은 초기좌표를 x축으로 대칭 변환하는 함수
	printf("change X axis\n");
	print_matrix(*x_point, -*y_point);
}

void change_y_axis(int* x_point, int* y_point) {
	// 입력받은 초기좌표를 y축으로 대칭 변환하는 함수
	printf("change Y axis\n");
	print_matrix(-*x_point, *y_point);
}
void change_xy_axis(int* x_point, int* y_point) {
	// 입력받은 초기좌표를 원점으로 대칭 변환하는 함수
	printf("change XY axis\n");
	print_matrix(-*x_point, -*y_point);
}
void print_matrix(int x_point, int y_point) {
	// 4X4 좌표 평면을 출력하는 함수
	int row, col;
	// 좌표 -> 2차원 배열 위치로 변환
	if (x_point < 0)
		col = x_point + 2;
	else
		col = x_point + 1;
	if (y_point < 0)
		row = -y_point + 1;
	else
		row = -y_point + 2;

	char map[4][4];
	// 좌표평면 초기화, 표시
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = 'O';
		}
	}
	map[row][col] = 'X';

	// 출력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}