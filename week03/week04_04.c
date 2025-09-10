// 4주차 실습4. 호텔 예약 시스템  2024402055 박현지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 전역변수 예약된 방 개수
int VipCount = 0;
int NormalCount = 0;

// 함수 정의
int vip_check();
int normal_check();
int reservation_hotel(int per, int roomType);

int main() {
	int per;
	int roomType;

	// 5번 요청 받기 (예약 안된 경우도 포함)
	for (int i = 0; i < 5; i++) {
		// 인원수 입력
		printf("Reservation Personnel : ");
		scanf(" %d", &per);
		if (per == 0) 
			// 0명 예외처리
			printf("Try again\n\n");
		else{
			// 방 종류 입력
			printf("Room type <1> Vip  <2> Normal : ");
			scanf(" %d", &roomType);
			if (roomType == 1 || roomType == 2)
				reservation_hotel(per, roomType);
			else
				// 잘못된 옵션 예외처리
				printf("Wrong option\n\n");
		}
	}
}

int vip_check() {
	int vip_room[3] = { 301, 302, 303 };
	int roomNumber;

	if (VipCount == 3)
		// 남은 방 없을 경우
		roomNumber = -1;
	else
		roomNumber = vip_room[VipCount++];

	// 방 번호 반환 (없을 경우 -1)
	return roomNumber;
}

int normal_check() {
	int normal_room[5] = { 201, 202, 203, 204, 205 };
	int roomNumber;

	if (NormalCount == 5)
		// 남은 방 없을 경우
		roomNumber = -1;
	else
		roomNumber = normal_room[NormalCount++];

	// 방 번호 반환 (없을 경우 -1)
	return roomNumber;
}

int reservation_hotel(int per, int roomType) {
	// 예약 처리, 예약 결과 출력 함수
	int roomNumber;
	int count=0;
	switch (roomType) {
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
	}
	return 0;
}