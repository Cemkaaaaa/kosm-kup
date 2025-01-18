#pragma once
#include <vector>
#include "enemy.h"
#include "player.h"
#include <conio.h>
using namespace std;
enum arrow{
	leftdown, leftup,rightup,rightdown
};
class Fight{
private:
	Player *p;
	enum class state {attack, choice, backpack, escape};
	string Interface = R"(
|---------------------|------------------------------------------------|-----------------------------------------------|
|                     |  |------------------|    |------------------|  |                                               |
|                     |  |     Attack       |    |     Backpack     |  |                                               |
|                     |  |------------------|    |------------------|  |                                               |
|                     |                                                |                                               |
|                     |                                                |                                               |
|                     |  |------------------|    |------------------|  |                                               |
|                     |  |     Escape       |    |     Defense      |  |                                               |
|                     |  |------------------|    |------------------|  |                                               |
|---------------------|------------------------------------------------|-----------------------------------------------|)";
	string Notification = R"(
|---------------------|------------------------------------------------------------------------------------------------|
|                     |                                                                                                |
|                     |	                                                                                               |
|                     |                                                                                                |
|                     |                                                                                                |
|                     |                                                                                                |
|                     |                                                                                                |
|                     |                                                                                                |
|                     |                                                                                                |
|---------------------|------------------------------------------------------------------------------------------------|)";

	string Attack = R"(
|---------------------|------------------------------------------------|-----------------------------------------------|
|                     |  |------------------|    |------------------|  |                                               |
|                     |  |                  |    |                  |  |                                               |
|                     |  |------------------|    |------------------|  |                                               |
|                     |                                                |                                               |
|                     |                                                |                                               |
|                     |  |------------------|    |------------------|  |                                               |
|                     |  |                  |    |                  |  |                                               |
|                     |  |------------------|    |------------------|  |                                               |
|---------------------|------------------------------------------------|-----------------------------------------------|)";
	
public:
	Fight() {};

	
	void fight() {
		int x = 22; int y = 51;
		int State = 0; 
		while (true)
		{
			
			//upravleniye(&coutInterface);
			

			
		}
	}
	void coutNotification(string notification) {
		cout << "\033[19;0f";
		cout << Notification;
		cout << "\033[23;27f" << notification;
	}
	void coutInterface() {
		
		cout << "\033[19;0f";
		cout << Interface;
		

		
		cout << "\033[23;2f" << "Player";
		cout << "\033[24;2f" << "Health: " << "100";
		cout << "\033[25;2f" << "\033[48;2;0;255;0m" << string(100 / 10, ' ') << "\033[0m";
		
		
		cout << "\033[23;75f" << "Enemy";
		cout << "\033[24;75f" << "Health: " << "1000";
		cout << "\033[25;75f" << "\033[48;2;0;255;0m" << string(1000 / 100, ' ') << "\033[0m";
	}
	void coutAttack(Player p) {
		
		int temp;
		cout << "\033[19;0f";
		cout << Attack;
		for (int i = 0; i < p.getAbilities().size(); i++) {
			
			for (int i = 0; i < (4); i++) {

				switch (i)
				{
				case 0:
					cout << "\033[22;28f" << p.getAbility(i).getName();
					break;
				case 1:
					cout << "\033[27;28f" << p.getAbility(i).getName();
					break;
				case 2:
					cout << "\033[22;52f" << p.getAbility(i).getName();
					break;
				case 3:
					cout << "\033[27;52f" << p.getAbility(i).getName();
					break;
				default:
					break;
				}
			

			}
			cout << "\033[0;0f";



		}
		
	}
	int inline upravleniye( void (*Interface)()) {
		Interface();
		bool cX = 0; bool cY = 0;
		if (cX && cY) { cout << "\033[27;51f>"; } //левый низ
		else if (cX && !cY) { cout << "\033[22;51f>"; } // 
		else if (!cX && cY) { cout << "\033[27;27f>"; }
		else { cout << "\033[22;27f>"; }
		switch (_getch())
		{
		case 77/*->*/:
			
			cX = true;
			
			break;
		case 75/*<-*/:
			
			cX = false;
			break;
		case 72/*/\*/:
			cY = true;
			
			break;
		case 80/*\/*/:
			cY = false;
			
			break;
		case '\n':
			if (cX && cY) { return arrow::rightup; } //левый низ
			else if (cX && !cY) { return arrow::rightdown; } // 
			else if (!cX && cY) { return arrow::leftup; }
			else { return arrow::leftdown; }
		default:
			break;
		}
		
	}
};
