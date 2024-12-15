#pragma once
#include <iostream>
#include <vector>


namespace rarity {
	extern std::string Legendary;
}


class Weapon
{
protected:
	int damage;
	std::string name;
	int rarity = 0;
	std::string prefix;
	std::string suffix;

//	std::string type; //На реализацию
public:
	Weapon() { damage = 0; name = ""; rarity = 0; prefix = ""; suffix = ""; }
	Weapon(int damage, std::string name) : damage{ damage }, name{ name }, rarity{ 0 }, prefix{ "" }, suffix { "" } { }

	int getDamage() { return damage; }
//	std::string getType() { return type; }
	std::string getName() { return  (prefix.empty() ? prefix + " " : "") +" " + name + (suffix.empty() ? suffix + " " : ""); }

};

class Stick: public Weapon {
private:
	std::string name = "Stick";
	int damage = 10;

public:
	Stick() : Weapon(damage, name) {}
};


class Sword : public Weapon {
private:
	std::string name = "Sword";
	int damage = 15;

public:
	Sword() : Weapon(damage, name) {}
};
