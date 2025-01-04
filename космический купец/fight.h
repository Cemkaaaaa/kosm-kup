#pragma once
#include <vector>
#include "enemy.h"
#include "player.h"
#include <conio.h>
using namespace std;
class Fight
{

public:
	Fight() {};

	string Interface = R"(
|---------------------|------------------------------------------------|-----------------------------------------------|
|                     |  |------------------|    |------------------|  |								|
|                     |  |     Attack       |    |     Backpack     |  |                                               |
|                     |  |------------------|    |------------------|  |                                               |
|                     |                                                |                                               |
|                     |                                                |                                               |
|                     |  |------------------|    |------------------|  |                                               |
|                     |  |     Escape       |    |     Defense      |  |                                               |
|                     |  |------------------|    |------------------|  |                                               |
|---------------------|------------------------------------------------|-----------------------------------------------|)";

	void fight() {
		int x = 22; int y = 51;
		int choice = 0;
		while (true)
		{
			
			coutInterface(x, y);
			switch (_getch())
			{
			case 77/*->*/:
				y = 51;
				choice = 0;
				break;
			case 75/*<-*/:
				y = 27;
				choice = 1;
				break;
			case 72/*/\*/:
				choice = 2;
				x = 22;
				break;
			case 80/*\/*/:
				choice = 3;
				x = 27;
				break;
			default:
				break;
			}

			
		}
	}
	void coutInterface(int x, int y) {
		
		cout << "\033[19;0f";
		cout << Interface;

		cout << "\033[23;2f" << "Player";
		cout << "\033[24;2f" << "Health: " << "100";
		cout << "\033[25;2f" << "\033[48;2;0;255;0m" << string(100 / 10, ' ') << "\033[0m";
		cout << "\033[" << x << ";" << y << "f" << ">";
		
		cout << "\033[23;75f" << "Enemy";
		cout << "\033[24;75f" << "Health: " << "1000";
		cout << "\033[25;75f" << "\033[48;2;0;255;0m" << string(1000 / 100, ' ') << "\033[0m";


	}

	
};
