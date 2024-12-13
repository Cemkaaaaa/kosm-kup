#pragma once
#include <iostream>

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
public:
	virtual void attack() = 0; // �����
	virtual void defend() = 0; // ������
	virtual void printSprite() = 0;

	/*������*/
	int getHealth() const { return health; }
	int getDamage() const { return damage; }
	int getDefense() const { return defense; }

	std::string getName() const { return name; }
	std::string getSprite() const { return sprite; }
	
	

};

