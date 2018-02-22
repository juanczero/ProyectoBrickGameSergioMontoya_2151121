#pragma once
#include <Windows.h>
#include <thread>
#include <iostream>
#include "gotoXY.h"

#ifndef CARROENEMIGO_H
#define CARROENEMIGO_H
class EnemiesCar {
public:
	EnemiesCar() {
		xPos = 5;//5
		yPos = -3;//-3
	}
	int xPos;
	int yPos;
	void appear() {
		if (yPos == 20) {
			int randomNo = rand() % 3;//2
			if (randomNo == 0) {
				xPos = 2;
				if (velocidad == 0)
				{
					score = score + 10;
				}
				else if (velocidad == 1)
				{
					score = score + 20;
				}
				else if (velocidad == 2)
				{
					score = score + 40;
				}
				else if (velocidad == 3)
				{
					score = score + 60;
				}
				else if (velocidad == 4)
				{
					score = score + 80;
				}
				else if (velocidad == 5)
				{
					score = score + 100;
				}
				else if (velocidad == 6)
				{
					score = score + 130;
				}
				else if (velocidad == 7)
				{
					score = score + 170;
				}
				else if (velocidad == 8)
				{
					score = score + 200;
				}
				else if (velocidad == 9)
				{
					score = score + 220;
				}
				else if (velocidad == 10)
				{
					score = score + 280;
				}
				
			}
			else if(randomNo == 2) {//0
				xPos = 5;
				if (velocidad == 0)
				{
					score = score + 10;
				}
				else if (velocidad == 1)
				{
					score = score + 20;
				}
				else if (velocidad == 2)
				{
					score = score + 40;
				}
				else if (velocidad == 3)
				{
					score = score + 60;
				}
				else if (velocidad == 4)
				{
					score = score + 80;
				}
				else if (velocidad == 5)
				{
					score = score + 100;
				}
				else if (velocidad == 6)
				{
					score = score + 130;
				}
				else if (velocidad == 7)
				{
					score = score + 170;
				}
				else if (velocidad == 8)
				{
					score = score + 200;
				}
				else if (velocidad == 9)
				{
					score = score + 220;
				}
				else if (velocidad == 10)
				{
					score = score + 280;
				}
			}
		else
		{
			xPos = 8;
			if (velocidad == 0)
			{
				score = score + 10;
			}
			else if (velocidad == 1)
			{
				score = score + 20;
			}
			else if (velocidad == 2)
			{
				score = score + 40;
			}
			else if (velocidad == 3)
			{
				score = score + 60;
			}
			else if (velocidad == 4)
			{
				score = score + 80;
			}
			else if (velocidad == 5)
			{
				score = score + 100;
			}
			else if (velocidad == 6)
			{
				score = score + 130;
			}
			else if (velocidad == 7)
			{
				score = score + 170;
			}
			else if (velocidad == 8)
			{
				score = score + 200;
			}
			else if (velocidad == 9)
			{
				score = score + 220;
			}
			else if (velocidad == 10)
			{
				score = score + 280;
			}
		}
			yPos = -3;
		}
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
	void move() {//rapidezz que se movieran los carros
		yPos++;
	}

};

#endif // !CARROENEMIGO_H

