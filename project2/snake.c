#include"snake.h"

int vec_x[4] = { 0, 1, 0, -1 };
int vec_y[4] = { -1, 0, 1, 0 };
int state = 0;
int count = 0;
int st;
void init() {
	sInit();
	srand((int)time(NULL));

	int map[40][20];
	do {
		sna.dir = rand() % 4;
		sna.pos[0].x = rand() % 38 + 1;
		sna.pos[0].y = rand() % 18 + 1;
		if (sna.pos[0].x + vec_x[(sna.dir + 2) % 4] * 5 <= 38 && sna.pos[0].x + vec_x[(sna.dir + 2) % 4] * 5 >= 1)
			if (sna.pos[0].y + vec_y[(sna.dir + 2) % 4] * 5 <= 18 && sna.pos[0].y + vec_y[(sna.dir + 2) % 4] * 5 >= 1)
				break;
	} while (1);
	map[sna.pos[0].x][sna.pos[0].y] = 1;
	for (int i = 1; i < 6; i++) {
		sna.pos[i].x = sna.pos[i - 1].x + vec_x[(sna.dir + 2) % 4];
		sna.pos[i].y = sna.pos[i - 1].y + vec_y[(sna.dir + 2) % 4];
		map[sna.pos[i].x][sna.pos[i].y] = 1;
	}

	obj = (object*)malloc(sizeof(object)*num);
	for (int i = 0; i < num; i++) {
		pos tmp_pos;
		do {
			tmp_pos.x = rand() % 38 + 1;
			tmp_pos.y = rand() % 18 + 1;
			if (map[tmp_pos.x][tmp_pos.y] != 1)
				break;
		} while (1);
		map[tmp_pos.x][tmp_pos.y] = 1;
		obj[i].pos = tmp_pos;
		obj[i].hidden = 0;

	}
	draw();
}

void update(int ekey) {
	//move
	switch (ekey)
	{
	case 72:
		sna.dir = 0;
		break;
	case 77:
		sna.dir = 1;
		break;
	case 80:
		sna.dir = 2;
		break;
	case 75:
		sna.dir = 3;
		break;
	}
	for (int i = 5; i >= 1; i--)
		sna.pos[i] = sna.pos[i - 1];
	sna.pos[0].x += vec_x[sna.dir];
	sna.pos[0].y += vec_y[sna.dir];
	if (sna.pos[0].x == 0 || sna.pos[0].x == 39)
		release();
	else if (sna.pos[0].y == 0 || sna.pos[0].y == 19)
		release();
	else {
		for (int i = 0; i < num; i++) {
			if (sna.pos[0].x == obj[i].pos.x && sna.pos[0].y == obj[i].pos.y)
			{
				obj[i].hidden = 1;
				count += obj[i].hidden;
				if (count == num)
					win();
			}
		}
	}

	//collision
}

void draw() {

	sClear();
	for (int i = 0; i < 40; i++) {
		sPrint(i * 2, 0, "бс");
		sPrint(i * 2, 19, "бс");
	}
	for (int i = 1; i < 19; i++) {
		sPrint(0, i, "бс");
		sPrint(78, i, "бс");
	}

	for (int i = 0; i < num; i++) {
		if (obj[i].hidden == 0)
		{
			sPrint(obj[i].pos.x * 2, obj[i].pos.y, "в╛");	
		
		}
	}
	sPrint(sna.pos[0].x * 2, sna.pos[0].y, "б▌");
	for (int i = 1; i < 6; i++) {
		sPrint(sna.pos[i].x * 2, sna.pos[i].y, "в┬");
	}
	sFlipping();
	
}
void win()
{
		
	sRelease();
	system("CLS");
		printf("You Win!");
	
}
void release() {
	sRelease();
}

