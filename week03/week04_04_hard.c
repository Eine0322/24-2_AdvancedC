// 4주차 실습4(심화). 호텔 예약 시스템 + 예약 취소  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 전역변수 예약된 방 개수
int vip_room[3][2] = { { 301, 0 }, { 302,0 }, { 303,0 } };
int VipCount = 0;
int normal_room[5][2] = { {201,0},{202,0},{203,0},{204,0}, {205,0 } };
int NormalCount = 0;


// 함수 정의
int vip_check();
int vip_cancel();
int normal_check();
int normal_cancel();
int reservation_hotel(int per, int roomType);

int main() {
	int per;
	int option;

	// 5번 요청 받기 (예약 안된 경우도 포함)
	for (int i = 0; i < 5; i++) {
		// 방 종류 입력
		printf("Reserve Option <1> Vip  <2> Normal  <3> cancel : ");
		scanf(" %d", &option);
		if (option == 1 || option == 2) {
			// 방 선택 시 인원수 입력
			printf("Reservation Personnel : ");
			scanf(" %d", &per);
			if (per == 0)
				// 0명 예외처리
				printf("Try again\n\n");
			else
				reservation_hotel(per, option);
		}
		else if (option == 3)
			// 방 취소 옵션 선택
			reservation_hotel(0, option);
		else
			// 잘못된 옵션 예외처리
			printf("Wrong option\n\n");
	}
}

int vip_check() {
	// vip 방 예약 함수
	int roomNumber;
	if (VipCount == 3)
		// 남은 방 없을 경우
		roomNumber = -1;
	else { // 빈 방 순서대로 출력
		for (int i = 0; i < 3; i++) {
			if (vip_room[i][1] == 0) {
				roomNumber = vip_room[i][0];
				vip_room[i][1] = 1;
				VipCount++;
				break;
			}
		}
	}
	// 방 번호 반환 (없을 경우 -1)
	return roomNumber;
}

int vip_cancel() {
	// vip 방 예약 취소 함수
	int roomNumber;

	// 취소할 방 번호 입력
	printf("Room number (301-303) : ");
	scanf("%d", &roomNumber);
	int num = roomNumber - 301;
	if (vip_room[num][1] == 1) { // 예약된 방이 맞을 경우
		printf("%d cancelled\n\n", vip_room[num][0]);
		vip_room[num][1] = 0;
		VipCount--;
	}
	else  // 예약된 방이 아닐 경우
		printf("No Reserved Room\n");
}

int normal_check() {
	// normal 방 예약 함수
	int roomNumber;

	if (NormalCount == 5)
		// 남은 방 없을 경우
		roomNumber = -1;
	else { // 빈 방 순서대로 출력
		for (int i = 0; i < 5; i++) {
			if (normal_room[i][1] == 0) {
				roomNumber = normal_room[i][0];
				normal_room[i][1] = 1;
				NormalCount++;
				break;
			}
		}
	}

	// 방 번호 반환 (없을 경우 -1)
	return roomNumber;
}

int normal_cancel() {
	// normal 방 취소 함수
	int roomNumber;

	// 취소할 방 번호 입력
	printf("Room number (201-205) : ");
	scanf("%d", &roomNumber);
	int num = roomNumber - 201;
	if (normal_room[num][1] == 1) { // 예약된 방일 경우
		printf("%d cancelled\n\n", normal_room[num][0]);
		normal_room[num][1] = 0;
		NormalCount--;
	}
	else // 예약된 방이 아닐 경우
		printf("No Reserved Room\n");
}

int reservation_hotel(int per, int option) {
	// 예약 처리, 예약 결과 출력 함수
	int roomNumber, roomType;
	int count = 0;
	switch (option) {
	case 1: // Vip룸 선택
		// 인원수에 따른 필요한 방 개수 계산
		if (per <= 4)
			count = 1;
		else if (per % 4 == 0)
			count = per / 4;
		else
			count = (per / 4) + 1;
		// 남은 방 개수 모자란 경우 예약 불가 메시지 출력
		if (3 - VipCount < count) {
			printf("Exceed. No Room\n\n");
			return 0;
		}
		// 예약한 방 출력
		for (int i = 0; i < count; i++) {
			roomNumber = vip_check();
			if (roomNumber == -1) {
				// 방 없을 경우 예약 불가 메시지 출력
				printf("No Room\n\n");
				break;
			}
			else
				printf("%d check\n", roomNumber);
		}
		printf("\n");
		break;
	case 2: // Normal룸 선택
		// 인원수에 따른 필요한 방 개수 계산
		if (per <= 2)
			count = 1;
		else if (per % 2 == 0)
			count = per / 2;
		else
			count = (per / 2) + 1;
		// 남은 방 개수 모자란 경우 예약 불가 메시지 출력
		if (5 - NormalCount < count) {
			printf("Exceed. No Room\n\n");
			return 0;
		}
		// 예약한 방 출력
		for (int i = 0; i < count; i++) {
			roomNumber = normal_check();
			if (roomNumber == -1) {
				// 방 없을 경우 예약 불가 메시지 출력
				printf("No Room\n\n");
				break;
			}
			else
				printf("%d check\n", roomNumber);
		}
		printf("\n");
		break;
	case 3: // 예약한 방 취소
		printf("Room Type <1> Vip  <2> Normal : ");
		scanf("%d", &roomType);
		if (roomType == 1) // vip방 취소
			vip_cancel();
		else if (roomType == 2) //normal방 취소
			normal_cancel();
		else // 예외처리
			printf("Wrong oprion\n");
		break;
	}
	return 0;
}