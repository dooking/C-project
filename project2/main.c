#include <stdio.h>
#include <windows.h>
#include"snake.h"

void main() {
	int ekey = 0;
	int stated;
	printf("Enter the number of items : ");
	scanf_s("%d", &num);

	init();						// ������ �ʱ�ȭ �Լ�

	int flag = 0;
	while (1) {
		if (_kbhit()) {			// Ű���� �Է��� ������ 1, ������ 0�� ����
			ekey = _getch();	// �Է¹��� Ű ���� ����
			if (ekey == 224)
				ekey = _getch();
			_flushall();
		}
		update(ekey);	// ���� ������Ʈ
		draw();					// ȭ�鿡 ���
		Sleep(100);
	}
	release();

	
}