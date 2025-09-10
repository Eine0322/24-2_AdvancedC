// 7주차 실습4. 사전식 정렬  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable : 6031)

void make_dictionary(char** a, int cnt);//sorting func
int my_strcmp(const char* a, const char* b, char* p, char* q);//strcmp func: case sensitive regardless

void main()
{
	FILE* rfp = fopen("words.txt", "r");//file ptr define
	int c;//input constructor
	int len = 0, cnt = 0;//word length & words cnt
	int overlapping = 0;//overlapping delimiter
	char** A = NULL;//words list

	A = (char**)malloc(sizeof(char*));//std_alloc
	*A = (char*)malloc(sizeof(char));//std_alloc

	////////////word input///////////////////////////
	while (1)//word input loop
	{
		if (feof(rfp) != 0) { printf("파일의 끝에 도달했습니다.\n");	break; }//file end inspect
		c = fgetc(rfp);
		if (c == '\n' || c == ';' || c == '\t' || c == ',' || c == '|')
		{
			if (overlapping == 1)
				continue;
			A[cnt][len] = '\0';
			++cnt;
			A = (char**)realloc(A, sizeof(char*) * (cnt + 1));
			*(A + cnt) = (char*)malloc(sizeof(char) * (len + 1));
			len = 0;
			++overlapping;
		}
		else
		{
			*(A + cnt) = (char*)realloc(*(A + cnt), sizeof(char) * (len + 1));
			A[cnt][len] = c;
			len++;
			overlapping = 0;
		}
	}
	/////////word input//////////////////////////////

	make_dictionary(A, cnt);//sorting func call



	////////////file save/////////////////////
	FILE* wfp = fopen("dictionary.txt", "w");
	for (int i = 0; i < cnt; i++)
	{
		printf("%s\n", *(A + i));
		fprintf(wfp, "%s\n", *(A + i));
	}
	/////////////////////////////////////////


	for (int i = 0; i < cnt; i++)
		free(A[i] = NULL);
	free(A);
	fclose(rfp);
	fclose(wfp);
}

void make_dictionary(char** a, int cnt)
{
	char* p = NULL;
	char* q = NULL;
	int c = 0, j;
	char tmp[20] = { NULL };

	for (int i = 0; i < cnt; i++)
	{
		for (int k = i + 1; k < cnt; k++)
		{
			j = i;
			c = my_strcmp(a[i], a[k], p, q);
			if (c == 1)
				j = k;
			strcpy(tmp, *(a + i));
			strcpy(*(a + i), *(a + j));
			strcpy(*(a + j), tmp);
		}
	}

}

int my_strcmp(const char* a, const char* b, char* p, char* q)
{
	p = (char*)malloc(sizeof(char) * (strlen(a) + 1));
	q = (char*)malloc(sizeof(char) * (strlen(b) + 1));
	strcpy(p, a);
	strcpy(q, b);

	for (int h = 0; p[h] != '\0'; h++)
	{
		if (p[h] >= 'A' && p[h] <= 'Z')
			p[h] += 32;
	}
	for (int j = 0; q[j] != '\0'; j++)
	{
		if (q[j] >= 'A' && q[j] <= 'Z')
			q[j] += 32;
	}

	int v = strcmp(p, q);

	return v;
}