#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	string file = "myFile.txt";
	//SetConsoleCP(CP_UTF8);
	//SetConsoleOutputCP(CP_UTF8);
	fstream fs;
	fs.open(file, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "ошибка открытияя файла\n";
	}
	else {
		string msg;
		int value;
		cout << "файл открыт\n";
		cout << "1.Добавить сохранение\n";
		cout << "2.Посмотреть сохранения\n";
		cin >> value;

		if (value == 1) {
			cout << "Введите название сохранения\n";
			SetConsoleCP(1251);
			cin >> msg;
			fs << msg << endl;
			SetConsoleCP(866);
		}
		if (value == 2) {
			while (!fs.eof()) {
				msg = "";
				fs >> msg;
				cout << msg << endl;
			}
		}
	}
	fs.close();
	return 0;
}
