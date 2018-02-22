#pragma once
#include <Windows.h>
#include <thread>
#include <iostream>
#include "gotoXY.h"
#include "CarroEnemigo.h"

#ifndef CARROUSER_H
#define CARROUSER_H
class car {
public:
	int xPos;
	int yPos;
	int vidas;//vidas
	car() {
		xPos = 5;//2
		yPos = 16;//16
	}
	void draw() {
		drawPoint(xPos, yPos);
		drawPoint(xPos - 1, yPos + 1);
		drawPoint(xPos + 1, yPos + 1);
		drawPoint(xPos, yPos + 1);
		drawPoint(xPos, yPos + 2);
		drawPoint(xPos - 1, yPos + 3);
		drawPoint(xPos + 1, yPos + 3);
		drawPoint(xPos, yPos + 3);
	}
	void moveLeft() {
		xPos = xPos-3 ;
	}
	void moveRight() {
		xPos = xPos+3;
	}
	/*void moveFast() {
		
	}*/


	void checkCollusion(EnemiesCar *EC, bool *running) {
		if (EC->xPos == xPos & EC->yPos>13) {
			*running = false;
			
		}
	}
};

#endif // !CARROUSER_H

