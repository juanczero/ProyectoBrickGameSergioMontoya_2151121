#pragma once
#include <Windows.h>
#include <thread>
#include <iostream>

#ifndef GOTOXY_H
#define GOTOXY_H


int score;
int rapidez = 50, nivel=1,velocidad,cont;



void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int matrix[11][20];


void drawPoint(int x, int y) {
	if (y<20 & y >= -0) {
		matrix[x][y] = 1;
	}
}
void resetBoard() {
	for (int j = 0; j<20; j++) {
		for (int i = 1; i<10; i++) {
			matrix[i][j] = 0;
		}
	}
}






#endif // !GOTOXY_H

