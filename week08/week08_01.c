// 8주차 실습1. 평점 계산기 업그레이드  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main() {
	typedef struct grade {
		char sub[20];
		int hakjum;
		char sungjuk[10];
		float score;
		float jumsoo;
	} Gra;

	char waste[20];
	float std_score[9] = { 4.5, 4, 3.5, 3, 2.5, 2, 1.5, 1, 0 };
	float total_jumsoo = 0;
	int total_hakjum = 0;

	Gra gra[7];

	FILE* rfp = fopen("grade_ANSI.txt", "r"); // VS 한글 깨짐 현상 방지 (파일인코딩->ANSI)
	fscanf(rfp, "%s\t\t%s\t%s\n", waste, waste, waste);
	for (int i = 0; i < 7; i++)
	{
		fscanf(rfp, "%s\t%d\t%s", gra[i].sub, &gra[i].hakjum, gra[i].sungjuk);

		if (strcmp(gra[i].sungjuk, "A+") == 0)
			gra[i].score = std_score[0];
		else if (strcmp(gra[i].sungjuk, "A") == 0)
			gra[i].score = std_score[1];
		else if (strcmp(gra[i].sungjuk, "B+") == 0)
			gra[i].score = std_score[2];
		else if (strcmp(gra[i].sungjuk, "B0") == 0)
			gra[i].score = std_score[3];
		else if (strcmp(gra[i].sungjuk, "C+") == 0)
			gra[i].score = std_score[4];
		else if (strcmp(gra[i].sungjuk, "C0") == 0)
			gra[i].score = std_score[5];
		else if (strcmp(gra[i].sungjuk, "D+") == 0)
			gra[i].score = std_score[6];
		else if (strcmp(gra[i].sungjuk, "D0") == 0)
			gra[i].score = std_score[7];
		else if (strcmp(gra[i].sungjuk, "F") == 0)
			gra[i].score = std_score[8];

		gra[i].jumsoo = gra[i].hakjum * gra[i].score;
		total_hakjum += gra[i].hakjum;
		total_jumsoo += gra[i].jumsoo;
		printf("%s 과목의 점수: %.2f\n", gra[i].sub, gra[i].jumsoo);
	}
	printf("총 평점: %.2f", total_jumsoo / total_hakjum);

	fclose(rfp);
}