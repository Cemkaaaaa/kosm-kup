#pragma once
#include <iostream>
#include <vector>
#include "weapon.h"
#include "Armor.h"


class Player: public Weapon, public Armor
{
private:
	std::string name;
	int hp;
	int defense;
	int damage;
	Weapon weapon; //Название Урон
	Armor armor; //Название Защита
	
	int x;
	int y;
	int chX; int chY;
public:
	//Гетеры
	
	std::string getName() { return name; }
	
	int getHP() { return hp; }
	int getDefense() { return defense; }
	int getDamage() { return damage; }

	Weapon getWeapon()  { return weapon; } 
	Armor getArmor() { return armor; }

	int getX() { return x; }
	int getY() { return y; }


	
};

