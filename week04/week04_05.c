// 4주차 실습5. 블랙잭 프로그램  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

// 전역 변수 선언
int deck[20];
int deckCnt;
int* userDeck;
int userCnt;
int userScore;
int* dealerDeck;
int dealerCnt;
int dealerScore;

// 함수 선언
void Shuffle();
void Initialization();
void Status();
void Hit();
void End();
void Result();

// 카드 20장 만드는 함수
void Shuffle() {
	// 각 숫자,문자 별 4장씩 들어있는 카드덱 생성
	int decks[52];
	int cnt=0;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 4; j++) {
			decks[cnt++] = i + 1;
		}
	}
	cnt = 0;

	// 카드 덱에서 20장 뽑아 저장
	int n;
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		n = rand() % 52;
		if (decks[n] != 0) {
			deck[i] = decks[n];
			decks[n] = 0;
		}
		else
			i--;
	}
}

// 카드를 2개씩 사용자 딜러 순으로 분배하는 함수
void Initialization() {
	// 변수 초기화
	deckCnt = 0;
	userCnt = 0;
	userScore = 0;
	dealerCnt = 0;
	dealerScore = 0;

	// 각 카드 동적할당 후 카드분배, 점수 저장
	userDeck = (int*)malloc(sizeof(int) * 2);
	dealerDeck = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < 2; i++){
		userDeck[userCnt] = deck[deckCnt++];
		if (userDeck[userCnt] == 11 || userDeck[userCnt] == 12 || userDeck[userCnt] == 13) {
			userScore += 10;
			userCnt++;
		}
		else
			userScore += userDeck[userCnt++];
		dealerDeck[dealerCnt] = deck[deckCnt++];
		if (dealerDeck[dealerCnt] == 11 || dealerDeck[dealerCnt] == 12 || dealerDeck[dealerCnt] == 13) {
			dealerScore += 10;
			dealerCnt++;
		}
		else
			dealerScore += dealerDeck[dealerCnt++];
	}
}

// 현재 카드 상황을 출력하는 함수
void Status() {
	printf("Dealer : ");
	for (int i = 0; i < dealerCnt; i++) {
		switch (dealerDeck[i]){
		case 1:
			printf("A ");
			break;
		case 11:
			printf("J ");
			break;
		case 12:
			printf("Q ");
			break;
		case 13:
			printf("K ");
			break;
		default:
			printf("%d ", dealerDeck[i]);
			break;
		}
	} printf("\n");
	printf("User : ");
	for (int i = 0; i < userCnt; i++) {
		switch (userDeck[i]) {
		case 1:
			printf("A ");
			break;
		case 11:
			printf("J ");
			break;
		case 12:
			printf("Q ");
			break;
		case 13:
			printf("K ");
			break;
		default:
			printf("%d ", userDeck[i]);
			break;
		}
	} printf("\n");
}

// 카드를 1장씩 유저에게 주는 함수
void Hit() {
	// 카드 수 늘리는 동적할당 후 카드 분배, 유저 점수 추가
	userDeck = (int*)realloc(userDeck, sizeof(int) * (userCnt+1));
	userDeck[userCnt] = deck[deckCnt++];
	if (userDeck[userCnt] == 11 || userDeck[userCnt] == 12 || userDeck[userCnt] == 13) {
		userScore += 10;
		userCnt++;
	}
	else
		userScore += userDeck[userCnt++];
}

// 카드를 1장씩 딜러에게 주는 함수
void End() {
	// 카드 수 늘리는 동적할당 후 카드 분배, 딜러 점수 추가
	dealerDeck = (int*)realloc(dealerDeck, sizeof(int) * (dealerCnt + 1));
	dealerDeck[dealerCnt] = deck[deckCnt++];
	if (dealerDeck[dealerCnt] == 11 || dealerDeck[dealerCnt] == 12 || dealerDeck[dealerCnt] == 13) {
		dealerScore += 10;
		dealerCnt++;
	}
	else
		dealerScore += dealerDeck[dealerCnt++];
}

// 유저의 승리 및 패배 판단 후 출력하는 함수 (+free)
void Result() {
	if ((dealerScore == 21 && userScore == 21) || (dealerScore == userScore) || (dealerScore > 21 && userScore > 21)) {
		// 무승부일 경우
		printf("Draw!\n\n");
	}
	else if (dealerScore > 21 || userScore > 21) {
		// 딜러나 유저 중 21을 초과했을 경우
		printf("Busted! Over 21! ");
		if (dealerScore > userScore)
			printf("User Wins.\n\n");
		else
			printf("Dealer Wins.\n\n");
	}
	else if (dealerScore == 21 || userScore == 21) {
		// 딜러나 유저 중 블랙잭일 경우
		printf("BlackJack! Winner Winner Chicken Deinner! ");
		if (dealerScore < userScore)
			printf("User Wins.\n\n");
		else
			printf("Dealer Wins.\n\n");
	}
	// 위 조건 외 딜러와 유저 중 21에 가까운 사람 승
	else if (dealerScore > userScore)
		printf("Dealer Wins! Congratulation!\n\n");
	else
		printf("User Wins! Congratulation!\n\n");

	// free
	free(userDeck);
	free(dealerDeck);
}

// 게임 시작 및 조건문 처리
void main() {
	char selc[20]; 
	while (1) {
		printf("Game Start? (Start or Quit)  ");
		scanf("%s", selc);
		if (strcmp(selc, "Start") == 0) {
			// 게임 시작
			Shuffle(); // 덱 20장 뽑기
			Initialization(); // 카드 2장씩 분배
			Status(); // 분배된 카드 확인
			while (1) {
				// 유저가 카드를 더 뽑을지 결정
				printf("More Card? (Hit or Stay)  ");
				scanf("%s", selc);
				if (strcmp(selc, "Hit") == 0) {
					// 유저가 카드를 더 뽑을 경우
					Hit(); // 유저 카드 1 할당
					Status(); // 확인
					if (userScore >= 21) {
						// 뽑은 카드로 인해 유저점수가 21을 초과했을 경우, 블랙잭일 경우 승패 출력
						Result();
						break;
					}
				}
				else if (strcmp(selc, "Stay") == 0) {
					// 카드를 더 뽑지 않을 경우
					while (1) {
						// 딜러의 카드가 16이 넘지 않는다면 넘을 때까지 한 장 더
						if (dealerScore >= 17)
							break;
						End(); // 딜러 카드 1 할당
						Status(); // 확인
						if (dealerScore >= 21) {
							// 뽑은 카드로 인해 딜러의 점수가 21을 초과했을 경우, 블랙잭일 경우 승패 출력
							Result();
							break;
						}
					}
					if (dealerScore >= 17)
						// 딜러의 점수가 17이 넘고, 아무도 21을 초과하지 않고, 아무도 블랙잭이 아닐경우 패스
						break;
				}
				else
					// Stay or Hit 이 아닐 경우
					printf("Error : Wrong Input, Try Again.\n");
			}
			if (dealerScore < 21 && userScore < 21)
				// 딜러의 점수가 17이 넘고, 아무도 21을 초과하지 않고, 아무도 블랙잭이 아닐경우 결과 출력
				Result();
		}
		else if (strcmp(selc, "Quit") == 0)
			// 게임 종료
			break;
		else
			// Start or Quit 가 아닐 경우
			printf("Error : Wrong Input, Try Again.\n\n");
	}
}