#pragma once
#include <iostream>
#include <vector>
#include "weapon.h"
#include "Armor.h"
#include "Ability.h"
using namespace std;
#pragma execution_character_set("utf-8")

class Player: public Weapon, public Armor
{
private:

	std::string name;
	int hp;
	int defense;
	int damage;
	Weapon weapon = Weapon(); 
	Armor armor = Armor(); 
	vector<Ability> ability;
	vector<Ability> UsesAbilty;
protected:
	int x;
	int y;

public:
	Player() : name{ "NULL" }, hp{ 100 }, defense{ 1 }, damage{ 1 }, x{ 0 }, y{ 0 }, ability{Ability("Punch", "Обычный удра", 10),Ability("Pun2ch", "Обычный удра", 10) ,Ability("Punch11", "Обычный удра", 10) ,Ability("Punch34", "Обычный удра", 10) } { setlocale(LC_ALL, "Russian"); }
	Player(std::string name, int hp, int defense, int damage, vector<Ability> ability) : name{ name }, hp{ hp }, defense{ defense }, damage{ damage }, x{ 0 }, y{ 0 }, ability { ability } {}

	//Гетеры
	
	string getName()	{ return name; }
	
	int getHP()			{ return hp; }
	int getDefense()	{ return defense; }
	int getDamage()		{ return damage; }

	Weapon getWeapon()  { return this->weapon; } 
	Armor getArmor()	{ return this->armor; }

	int getX()			{ return x; }
	int getY()			{ return y; }

	Ability getAbility(int index) {
		if (index < 0 && index > 4 && index < ability.size()) {
			cout << "Error!"; return Ability();
		}
		else { return ability[index]; }
	}

	int hurt(int damage) {
		int DeltaDamage = (getHP() - damage * (1 / (rand() % defense)));
		this->hp = DeltaDamage;
		return DeltaDamage;
	}
	/*Вектор*/
	vector<Ability> getUsesAbility() { return this->UsesAbilty; }
	vector<Ability> getAbilities() { return ability; }
	
};

