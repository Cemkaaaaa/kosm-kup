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

protected:
	int x;
	int y;

public:
	Player() : name{ "NULL" }, hp{ 100 }, defense{ 1 }, damage{ 1 }, x{ 0 }, y{ 0 }, ability{Ability("Punch", "Default Desc", 10),Ability("Punch x2", "Default Desc", 20) ,Ability("Punch x3", "Default Desc", 30) ,Ability("Punch34", "Default Desc", 10) } {  }
	Player(std::string name, int hp, int defense, int damage, vector<Ability> ability) : name{ name }, hp{ hp }, defense{ defense }, damage{ damage }, x{ 0 }, y{ 0 }, ability { ability } {}
	Player(const Player& player) { this->name = player.name; this->hp = player.hp; this->defense = player.defense; this->damage = player.damage; this->weapon = player.weapon; this->armor = player.armor; this->ability = player.ability; }
	//Гетеры
	
	string getName()	{ return name; }
	
	int getHP()			{ return hp; }
	int getDefense()	{ return defense; }
	int getDamage()		{ return damage; }

	Weapon getWeapon()  { return this->weapon; } 
	Armor getArmor()	{ return this->armor; }

	int getX()			{ return x; }
	int getY()			{ return y; }

	Ability getAbility(int index) const {
		if (index < 0 || index >= ability.size()) {

			return Ability(); // Пустая способность
		}
		return ability[index];
	}


	int hurt(int damage) {
		int DeltaDamage = (getHP() - (damage -defense));
		this->hp = DeltaDamage;
		return DeltaDamage;
	}
	/*Вектор*/

	vector<Ability> getAbilities() { return ability; }
	
};

