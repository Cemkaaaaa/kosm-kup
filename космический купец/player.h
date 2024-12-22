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
	Weapon weapon = Weapon(); //Название Урон
	Armor armor = Armor(); //Название Защита

	int x;
	int y;

public:
	Player() : name{ "NULL" }, hp{ 100 }, defense{ 1 }, damage{ 123 }, x{ 0 }, y{ 0 } {}
	Player(std::string name, int hp, int defense, int damage) : name{ name }, hp{ hp }, defense{ defense }, damage{ damage }, x{ 0 }, y{ 0 }  {}
	
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

