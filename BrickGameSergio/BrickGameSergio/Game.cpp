#include <Windows.h>
#include <thread>
#include <iostream>
#include "gotoXY.h"
#include "CarroEnemigo.h"
#include "CarroUser.h"
 
using namespace std;



void myListener(car *c) {
	while (1) {
		if (GetAsyncKeyState(VK_LEFT) & (0x8000 != 0)) {
			c->moveLeft();
		}
		else if (GetAsyncKeyState(VK_RIGHT) & (0x8000 != 0)) {
			c->moveRight();
		}
	}
}
void startGame() {
	car mycar = car();
	EnemiesCar myEnmCar = EnemiesCar();
	// starts the second thread (The input listener )  
	thread mySecondThread(myListener, &mycar);
	// This is the game engine/game loop  
	bool running = true;
	while (running) {
		
		
		system("cls");

		gotoXY(17, 4);
		
		cout << "SCORE:" << score;//14->17
		gotoXY(17, 5);
		
		cout << "Nivel:" << nivel;
		gotoXY(17, 6); 
		
		cout << "velocidad:"<<velocidad;

		/*gotoXY(17, 7);
		cout << "contador: " << cont;*/


		resetBoard();
		myEnmCar.appear();
		myEnmCar.draw();
		myEnmCar.move();
		mycar.draw();
		mycar.checkCollusion(&myEnmCar, &running);

		for (int j = 0; j<20; j++) {
			for (int i = 0; i<11; i++) {

				if (i == 0 | i == 10) {
					gotoXY(i, j);
					cout << "0";
					
				}
				else if (matrix[i][j] == 1) {
					gotoXY(i, j);
					cout << "|";
					
				}
				else {
					gotoXY(i, j);
					cout << " ";
					
				}
			}
			if (cont >= 12) {
				running = false;
			}
		}
		cont++;
		
		////////////////////////////////////
		/*if (cont == 200) {
			cont = -4;	
		}*/
		if (cont == 210) {
			nivel = nivel +1; 
			cont = 0;
		}
		else if (nivel % 10 ==0)
		{
			
			velocidad ++;
			nivel = 1;
			rapidez = rapidez - 5;
		}
		/*else if (velocidad == 1)
		{
			
			velocidad = 0;
			
		}*/
		if (velocidad ==10) {
			gotoXY(17, 4);
			cout << "GANASTE!" << endl;
			running = true;
		}
		////////////////

		Sleep(rapidez);



		//Sleep(50);//RAPIDEZ QUE CAEN LOS CARROS ENEMIGOS
	}
	//The game ended  

	//Show the Game Over  
	Sleep(1000);
	system("cls");
	gotoXY(5, 4);
	
	cout << "GAME OVER!!!";
	
	
	gotoXY(5, 7);
	
	cout << "1. try again"<<endl;
	gotoXY(5, 8);
	
	cout << "2. Exit" << endl;

	int opc2;
	gotoXY(5, 9);
	cout << "Ingrese que desea hacer: ";
	cin >> opc2;

	switch (opc2)
	{
	case 1:
			startGame();
			break;
	case 2:
		system("exit");
	default:
		break;
	}

	// Kills the second thread  
	mySecondThread.detach();
}
int main()
{

	int opc = 0;
	
	cout << " BIENVENIDO AL JUEGO DE CARROS"<<endl;
	cout << "==============================="<<endl;
	cout << "1. Jugar Brick Game\n2. Estadisticas \n3.Salir"<<endl;
	cin >> opc;
	switch (opc)
	{

	case 1:
		startGame();
		break;
	case 2:
		system("cls");
			gotoXY(5, 6);
		cout << "aqui va la estadistica"<<score<<endl;
		system("pause");
			break;
	case 3:
		system("exit");

	default:
		break;
	}
	
	//startGame();
	return 0;
}
