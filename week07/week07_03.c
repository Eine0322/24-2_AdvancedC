// 7주차 실습3. POS기 프로그램 만들기  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main()
{
	char* menu[9] = {
		NULL,
	};
	int* price[9] = {
		0,
	};
	char imsi[100] = {
		NULL,
	};
	char dan[10];
	int c, len = 0, j = 0, where_is_colon = 0, call = 1, mem = 0, ten = 1;

	int total = 0;

	FILE* rfp = fopen("menu.txt", "r");
	FILE* wfp = fopen("receipt.txt", "w");

	for (int i = 0; i < 9; i++)
	{
		j = 0;
		where_is_colon = 0;
		fgets(imsi, 100, rfp);
		len = strlen(imsi);
		while (j < len)
		{
			if (imsi[j] == ':')
				break;
			where_is_colon++;
			j++;
		}
		menu[i] = (char*)malloc(sizeof(char) * (where_is_colon)+1);
		price[i] = (int*)malloc(sizeof(int) * 1);
		*price[i] = 0;
		for (j = 0; j < where_is_colon; j++)
			menu[i][j] = imsi[j];
		menu[i][where_is_colon] = '\0';
		for (j = 0; j + where_is_colon + 1 < len; j++)
			dan[j] = imsi[where_is_colon + j + 1];
		dan[j] = '\0';
		int k = len - where_is_colon - 2;
		for (int p = 0; p < k; p++)
		{
			ten = 1;
			c = (int)dan[p] - 48;
			for (int q = p + 1; q < k; q++)
				ten *= 10;
			*price[i] += ten * c;
		}
	}
	while (call != 0)
	{
		printf("====================menu=================================price=======\n");
		for (int i = 0; i < 9; i++)
			printf("[%d] %25s \t\t %25d\n", i + 1, menu[i], *price[i]);
		printf("메뉴를 고르세요, 주문완료는 0을 누르세요: ");
		scanf("%d", &call);
		if (call < 0 && call > 9)
		{
			printf("잘못된 주문 번호를 입력했습니다, 다시 주문받겠습니다.\n");
			continue;
		}
		if (call == 0)
		{
			printf("주문을 완료하였습니다.\n");
			fprintf(wfp, "결제금액: %d", total);
			break;
		}
		printf("%s, 주문 받았습니다.\n", menu[call - 1]);
		total += *price[call - 1];
		fprintf(wfp, "%s : %d\n", menu[call - 1], *price[call - 1]);
	}
	fclose(rfp);
	fclose(wfp);
}