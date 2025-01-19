#pragma once
#include <vector>
#include "enemy.h"
#include "player.h"
#include <conio.h>
#include "ansiUtils.h"
#include <functional>
#include <string>
using namespace std;
enum arrow{
	leftdown, leftup,rightup,rightdown
};
class Fight{
private:
	Player *p;
	Enemy *enemy;
	enum class state {escape, attack, backpack, defense};
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
	bool cX = 0; bool cY = 0;
public:
	Fight() {};
	Fight(Player* player) : p{ player } { enemy = new Skeleton(rand() % 100, rand() % 15, rand() % 10); }

	
	void fight() {
		int x = 22; int y = 51;
		int State = 0; 
		function<void(Fight&)> fun;
		fun = &Fight::coutInterface;

		while (true)
		{
			
			State = upravleniye(fun);
			if (State == (int)state::attack) {
				State = upravleniye(function<void(Fight&)>{&Fight::coutAttack});
				switch (State)
				{
				case arrow::leftdown:
					
					coutNotification(to_string(enemy->hurt(p->getAbility(1).getDamage())));
					
					break;
				case arrow::leftup:
					enemy->hurt(p->getAbility(2).getDamage());
					break;
				case arrow::rightdown:
					enemy->hurt(p->getAbility(3).getDamage());
				case arrow::rightup:
					enemy->hurt(p->getAbility(4).getDamage());
					break;
				default:
					break;
				}
			}
			if (State == (int)state::backpack) {
				coutNotification("Work In Progress");
				cin;
			}
			if (State == (int)state::escape) {

			}

			
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
		cout << "\033[24;2f" << "Health: " << p->getHP();
		cout << "\033[25;2f" << "\033[48;2;0;255;0m" << string(p->getHP() / 10, ' ') << "\033[0m";
		
		ansi::putText(ansi::COORD(0, 75), 20, enemy->getSprite());
		cout << "\033[23;75f" << "Enemy";
		cout << "\033[24;75f" << "Health: " << "1000";
		cout << "\033[25;75f" << "\033[48;2;0;255;0m" << string(enemy->getHealth()/10, ' ') << "\033[0m";
	}
	void coutAttack() {
		
		int temp;
		cout << "\033[19;0f";
		cout << Attack;
		for (int i = 0; i < p->getAbilities().size(); i++) {
			
			for (int i = 0; i < (4); i++) {

				switch (i)
				{
				case 0:
					cout << "\033[22;28f" << p->getAbility(i).getName();
					break;
				case 1:
					cout << "\033[27;28f" << p->getAbility(i).getName();
					break;
				case 2:
					cout << "\033[22;52f" << p->getAbility(i).getName();
					break;
				case 3:
					cout << "\033[27;52f" << p->getAbility(i).getName();
					break;
				default:
					break;
				}
			

			}
			



		}
		
	}
	int inline upravleniye(function<void(Fight&)> Interface) {
		while (true) {
			Interface(*this);
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
				cY = false;

				break;
			case 80/*\/*/:
				cY = true;

				break;
			case 13:
				if (cX && cY) { return arrow::rightdown; } //левый низ
				else if (cX && !cY) { return arrow::rightup; } // 
				else if (!cX && cY) { return arrow::leftdown; }
				else { return arrow::leftup; }
				break;
			case 65:
				return -1;
			default:
				break;
			}
		}
		
		
	}
};
