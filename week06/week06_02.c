// 6주차 실습2. 파일에서 읽어온 문자열을 반대로 파일에 저장하기  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main() {
	FILE* in = fopen("in.txt", "r");
	FILE* out = fopen("out.txt", "w");

	char** ss = (char**)malloc(sizeof(char*));
	char tmp[100];
	char ent;
	int cnt = 0;

	for (;;) {
		if (feof(in) == 1)
			break;
		else {	
			ss = (char**)realloc(ss, sizeof(char*) * (cnt + 1));
			fscanf(in, "%[^\n]%c", tmp, &ent);
			ss[cnt] = (char*)malloc(sizeof(char) * strlen(tmp) + 1);
			strcpy(ss[cnt], tmp);
			cnt++;
		}
	}

	for (int i = 0; i < cnt-1; i++) {
		for (int j = strlen(ss[i]) - 1; j >= 0; j--) {
			fprintf(out, "%c", ss[i][j]);
		}
		fprintf(out, "\n");
	}

	for (int i = 0; i < 3; i++)
		free(ss[i]);
	free(ss);
	fclose(in);
	fclose(out);
}