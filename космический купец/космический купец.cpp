
#include <iostream>
#include <windows.h>
#include "enemy.h"
#pragma execution_character_set("utf-8")
using namespace std;


int main(){
	Skeleton skelet(1, 1, 1);
	SetConsoleOutputCP(CP_UTF8); // Устанавливаем кодировку UTF-8
	SetConsoleCP(CP_UTF8);
	cout << skelet.getSprite();
	return 80085;
}

