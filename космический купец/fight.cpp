#include "fight.h"
#include "player.h"
#include <iostream>
#pragma execution_character_set("utf-8")
int main() {
	Fight f{new Player()};
	f.fight();
	return 0;
}