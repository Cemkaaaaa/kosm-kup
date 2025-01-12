#pragma once
#include <iostream>
#pragma execution_character_set("utf-8")
class Ability
{
protected:
	int damage;
	std::string name;
	std::string description;
public:
	Ability() : damage{ 0 }, name{ std::string(17,'#')}, description{"Doesn't Exists!"} {}
	Ability(std::string name, std::string description, int damage) : damage{ damage }, name{ name }, description{ description } {}
	int getDamage() { return damage; }
	std::string getName() { return name; }
	std::string getDescription() { return description; }
};
