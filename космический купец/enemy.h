#pragma once

#pragma execution_character_set("utf-8")
#include <iostream>

using namespace std;
class Enemy
{
protected:
	std::string sprite;
	std::string name;
	
	int health;
	int damage;
	int defense;



	void setHealth(int health) {
		this->health = health;
	}

	int hurt(int damage) {
		int DeltaDamage = (getHealth() - damage * (1 / (rand() % defense)));
		setHealth(DeltaDamage);
		return DeltaDamage;
	}

public:

	Enemy(int health, int damage, int defense, string name, string sprite) : health{ health }, damage{ damage }, defense{ defense }, name{ name }, sprite{ sprite } {}; //Фига конструктор
	Enemy(Enemy& enemy) : Enemy(enemy.health, enemy.damage, enemy.defense, enemy.name, enemy.sprite) {}
	virtual void attack(/*Player* player*/) = 0; // Атака
	virtual void defend() = 0; // Защита
	virtual void printSprite() { cout << sprite; };

	/*Гетеры*/
	int getHealth() const { return health; }
	int getDamage() const { return damage; }
	int getDefense() const { return defense; }

	std::string getName() const { return name; }
	std::string getSprite() const { return sprite; }
	
	



};

class Skeleton : public Enemy {
private:
	static const string sprite;
public:
	Skeleton(int health, int damage, int defense) : Enemy(health, damage, defense, "Skeleton", sprite) {}
	void attack() override { cout << "HE ATTACKED FOR " << damage << "!" << endl; }
	void defend() override { defense+= 1; }

};

