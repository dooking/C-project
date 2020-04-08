#pragma once
#ifndef _SNAKE_H
#define _SNAKE_H

#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include"screen.h"

#define ROW 40
#define COL 20

#define L 75
#define R 77
#define U 72
#define D 80

typedef enum _dir { LEFT, RIGHT, UP, DOWN } direction;

typedef struct _pos {
	int x;
	int y;
}pos;

typedef struct _object {
	pos pos;
	int hidden;
}object;

typedef struct _snake {
	pos pos[6];
	int dir;
}snake;


snake sna;
object *obj;
int num;

void init();
void update(int ekey);
void draw();
void release();
void win();
void lose();

#endif