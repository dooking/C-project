#include <stdio.h>
#include <windows.h>
#include"snake.h"

void main() {
	int ekey = 0;
	int stated;
	printf("Enter the number of items : ");
	scanf_s("%d", &num);

	init();						// 변수값 초기화 함수

	int flag = 0;
	while (1) {
		if (_kbhit()) {			// 키보드 입력이 있으면 1, 없으면 0을 리턴
			ekey = _getch();	// 입력받은 키 값을 받음
			if (ekey == 224)
				ekey = _getch();
			_flushall();
		}
		update(ekey);	// 변수 업데이트
		draw();					// 화면에 출력
		Sleep(100);
	}
	release();

	
}