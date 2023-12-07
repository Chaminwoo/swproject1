#include <stdio.h>
#include <Windows.h>
#include <process.h>

int isForward = 0;
int isLeft = 0;
int isRight = 0;
int isDust = 0;
int tick = 10;

unsigned _stdcall DetectControl(/*void* arg*/) {
	while(1){
		DetectObstacle();
		DetectDust();
		Sleep(10);
	}
}

void DetectObstacle() {
	isForward = FrontSensor();
	isLeft = LeftSensor();
	isRight = RightSensor();
}

void DetectDust() {
	isDust = DustSensor();
}

void SetCleaner(int val) {
	if (val) {
		//먼지 흡입
	}
	else {
		//먼지 흡입 중단
	}
}

void MoveForward() {
	SetMotor(1, 1);
}

void MoveBackward() {
	SetMotor(0, 0);
}

void TurnLeft() {
	for(int i = 0; i<5; i++){
		SetMotor(0, 1);
		Sleep(tick);	
	}
}

void TurnRight() {
	for(int i = 0; i<5; i++){
		SetMotor(1, 0);
		Sleep(tick);	
	}
}

void SetMotor(int L, int R) {
	LeftMotorControl(L);
	RightMotorControl(R);
}

void LeftMotorControl(int L) {
	if (L) {
		//모터 전진
	}
	else {
		//모터 후진
	}
}

void RightMotorControl(int R) {
	if (R) {
		//모터 전진
	}
	else {
		//모터 후진
	}
}

int FrontSensor() {
	//전방 센서가 장애물을 감지하면 1, or 0을 return


	return 0;
}

int LeftSensor() {
	//좌측 센서가 장애물을 감지하면 1, or 0을 return


	return 0;
}

int RightSensor() {
	//우측 센서가 장애물을 감지하면 1, or 0을 return

	return 0;
}

int DustSensor() {
	//먼지 센서가 먼지를 감지하면 1 or 0을 return


	return 0;
}

int main() {
	_beginthreadex(NULL, 0, DetectControl, 0, 0, NULL);
	while(1) {
		if(isDust) {
			SetCleaner(1);
		}
		else {
			SetCleaner(0);
		}

		if (!isForward) {
			MoveForward();
		}
		else if (isForward && !isLeft) {
			TurnLeft();
		}
		else if (isForward && isLeft && !isRight) {
			TurnRight();
		}
		else {
			MoveBackward();
		}

		Sleep(tick);
	}
}