// 9주차 실습2. 입력된 월의 이름을 출력  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void main() {
	enum month {January=1, Febuary, March, April, May, Jun, July, August, September, October, November, December};
	int n;
	printf("월 입력 : ");
	scanf("%d", &n);

	switch (n){
	case January:
		printf("%d월은 January 입니다.\n", n);
		break;
	case Febuary:
		printf("%d월은 Febuary 입니다.\n", n);
		break;
	case March:
		printf("%d월은 March 입니다.\n", n);
		break;
	case April:
		printf("%d월은 April 입니다.\n", n);
		break;
	case May:
		printf("%d월은 May 입니다.\n", n);
		break;
	case Jun:
		printf("%d월은 Jun 입니다.\n", n);
		break;
	case July:
		printf("%d월은 July 입니다.\n", n);
		break;
	case August:
		printf("%d월은 August 입니다.\n", n);
		break;
	case September:
		printf("%d월은 September 입니다.\n", n);
		break;
	case October:
		printf("%d월은 October 입니다.\n", n);
		break;
	case November:
		printf("%d월은 November 입니다.\n", n);
		break;
	case December:
		printf("%d월은 December 입니다.\n", n);
		break;
	default:
		break;
	}
 }