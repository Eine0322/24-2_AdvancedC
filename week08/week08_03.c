// 8주차 실습3. "학생들" 성적 관리 프로그램 업그레이드  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct Student {
	char name[30];
	int kor;
	int eng;
} Stu;

typedef struct average {
	float* stu;
	float kor;
	float eng;
	float total;
} Avg;

void main() {
	int n;
	printf("Number of students : ");
	scanf("%d", &n);
	Stu* stu = (Stu*)malloc(sizeof(Stu) * n);
	Avg avg;
	avg.stu = (float*)malloc(sizeof(float) * n);
	avg.kor = 0;
	avg.eng = 0;
	avg.total = 0;

	for (int i = 0; i < n; i++) {
		printf("Name : ");
		scanf(" %s", stu[i].name);
		printf("Korean, English Score (eg: 80 90) : ");
		scanf("%d %d", &stu[i].kor, &stu[i].eng);
		avg.stu[i] = (stu[i].kor + stu[i].eng) / 2;
		avg.kor += stu[i].kor;
		avg.eng += stu[i].eng;
		avg.total += avg.stu[i];
	}
	avg.kor /= n;
	avg.eng /= n;
	avg.total /= n;

	FILE* rfp = fopen("average_student_ANSI.txt", "w"); // VS 한글 깨짐 현상 방지 (파일인코딩->ANSI)

	for (int i = 0; i < n; i++) {
		fprintf(rfp, "Name : %-8sAvg : %.2f\n", stu[i].name, avg.stu[i]);
	}
	fprintf(rfp, "Avg Korean : %.2f\n", avg.kor);
	fprintf(rfp, "Avg English : %.2f\n", avg.eng);
	fprintf(rfp, "Avg Total : %.2f\n", avg.total);

	fclose(rfp);
	free(avg.stu);
	free(stu);
}