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
	Weapon weapon = Weapon(); //�������� ����
	Armor armor = Armor(); //�������� ������

	int x;
	int y;

public:
	Player() : name{ "NULL" }, hp{ 100 }, defense{ 1 }, damage{ 1 }, x{ 0 }, y{ 0 } {}
	Player(std::string name, int hp, int defense, int damage) : name{ name }, hp{ hp }, defense{ defense }, damage{ damage }, x{ 0 }, y{ 0 }  {}
	
	//������
	
	std::string getName() { return name; }
	
	int getHP() { return hp; }
	int getDefense() { return defense; }
	int getDamage() { return damage; }

	Weapon getWeapon()  { return this->weapon; } 
	Armor getArmor() { return this->armor; }

	int getX() { return x; }
	int getY() { return y; }


	
};

