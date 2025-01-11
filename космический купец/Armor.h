#pragma once
#include <iostream>
using namespace std;
class Armor
{
protected:
	int armorPoint;
	int chanceToBlock;
	string name;
public:
	Armor() : armorPoint{ 0 }, chanceToBlock{ 0 }, name{""} {}
	Armor(int armorPoint, int chanceToBlock, string name) : armorPoint{ armorPoint }, chanceToBlock{ chanceToBlock }, name{name} {}
};

