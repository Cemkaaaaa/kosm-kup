#pragma once

#pragma execution_character_set("utf-8")
#include <iostream>
#include "player.h"
#include "Ability.h"
using namespace std;
class Enemy
{
protected:
	std::string sprite;
	std::string name;

	int health;
	int damage;
	int defense;
	int dopDefense;
	vector<Ability> ability{ Ability("Arrow", "", 10) };
	void setHealth(int health) {
		this->health = health;
	}



public:

	Enemy(int health, int damage, int defense, string name, string sprite) : health{ health }, damage{ damage }, defense{ defense }, name{ name }, sprite{ sprite } {}; //Фига конструктор
	Enemy(Enemy& enemy) : Enemy(enemy.health, enemy.damage, enemy.defense, enemy.name, enemy.sprite) {}
	virtual int attack(Player* player) {
		int Dplayer = player->getHP();
		player->hurt(getDamage());
		return Dplayer - player->getHP();
	}; // Атака
	virtual void defend() {
		this->dopDefense = rand() % 10;
	}; // Защита
	virtual void printSprite() { cout << sprite; };

	/*Гетеры*/
	int getHealth() const { return health; }
	int getDamage() const { return damage; }
	int getDefense() const { return defense; }

	std::string getName() const { return name; }
	std::string getSprite() const { return sprite; }
	int hurt(int damage) {
		int DeltaDamage = (getHealth() - damage * (1 / (rand() % (defense + dopDefense)) ));
		dopDefense > 0 ? dopDefense = 0 : true;
		setHealth(DeltaDamage);
		return DeltaDamage;
	}




};

class Skeleton : public Enemy {
private:
	static const string sprite;
public:
	Skeleton(int health, int damage, int defense) : Enemy(health, damage, defense, "Skeleton", sprite) {}


};
