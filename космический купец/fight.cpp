#include "fight.h"
#include "player.h"
#include <iostream>
using namespace std;
#pragma execution_character_set("utf-8")
int main() {
	setlocale(LC_ALL, "Russian");
	
	Fight f;
	Player p;
	f.coutAttack(p);
	return 80085;
}
