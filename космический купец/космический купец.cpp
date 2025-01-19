#include <iostream>
#include "ansiUtils.h"
#include "Earth.h"


//#pragma execution_character_set("utf-8")
using namespace std;
int main() {

	MapEarth map1;

	cout << "Enter planet:\n1.Earth\n2.Jupiter\n3.Venera\n";
	int user;
	cin >> user;
	switch (user)
	{
	case 0:

		break;
	case 1:
		map1.initMap();
	default:
		break;
	}
}