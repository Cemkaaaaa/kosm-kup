#include <iostream>
#include <vector>
#include <utility> 
#include "stdlib.h"
using namespace std;

/*




void cvest1() {
	cout << "� ������� ��� �� �� ������� ���������� �������� ������� � �������, ������� ��� � � ������ ����";
};
void cvest2() {
	cout << "������, ��� �� ������� ������� ��� ������, �� ����� ������� ��� ������ ��, ������� ������� �� �������";
};
auto Panchann{ []() {
    cout << R"(..............................................::::+*******=======-
::.:..........................................::::********=======-
::::::::......................................::::********=======-
+==--:::-::::::....:.........::................:::=**#*#**=======-
:::---====-----=-::--::::.....................:::-=**#*#**======--
:::::::::::::::-==-=+==--:..:::::::::.........:::-+**#*#*+======--
:::::::::::::::-*+=:::::::=--+====-:-++-.....:-::=+#*#*##+=====---
:::::::::::::::-*+===::::::::..:::=*++*=.....:-::=**####*======---
-:::::::::::::::*++==+===-:::---=**+==+-:::.:::::+**####*=======--
-:::::::::::::::-++++=++*#***#+++++++++:::::::::::--=+*#*=======--
-:::::::::::::::-++=+++++#==*++++++=++-:::::::::::::::+#*---------
-:::::::::::::::-++++*++===:--+=+++++=-:::::::::::::::-*+---------
-:::::::::::::::=+**#%%*+=-:-=+#%#++===::::::::::::::--+=---------
--:::::::::::::=####**##*=-::-###*++#*+-::::::::::::::-==---------
--::::::::::::-#**###*+++-::.:-=+**++++-:::::::::::::::-+++++++===
=-::::::::::::=*#%%##+=--+*+=:.:-=*##*+-:::::::::::::::-*#######**
=--:::::::::::-===========++--:::--=---::::::::--=+++==+++++=+++++
---:::::::::::-+=======++++++=-----::::::::----=+###*##******+====
----::::::::::+####*****++++===--::::::::::---=++*#########*+++*++
--=--:::::::-*####%%%%%%#***+*+-:::::..::::--=+++++=#%###########+
+++*=+=-::-+*#%%%%##%%*++=+%%@%+=:.....:+=-:::=+===+=+#%@@@%%%%#-.
++++++==--*#%%%%%%%@%#%##%%%%#=++=-:...:=**=-::::::::::-::::::---:
++++++++++#%%%%%%%@%%%@%@%%%#*####*=::::..:::--::::::::::::::::---
**********#%%%@@@@%%%@@@@@@#***%%#*----::::::::::-::::::::::::::::
+++++++++++*####%@@@@@@@@@@#%#%%#*=---======----:-+-::::::::::::::
+==+==++++++++++*##%%%%%%@@%%%######*#####*+**+*+=--:--::::::--:::
++=========+++++**#################*****+++++**++++++**+++==------
*****++=====+++++****###*#***********###**********++++++++++++++++
#########***+++++++++*++*****#*****+*****************+***+********
####%######%####**+*******+++++++++++*++++++****+**###*****+******
===+*###%%%%%###########*****++++++=++++=++++++++++++++*+++++**+**
======+#%%%%%%%%%%%##%%######**+++++++===+++++++++*****++++++++++=
----==+%%@@@@@%%%%%%%%%%###########**+++==++++++++++++++++++++++++
=-=====+%%%@@@@%##%%%%%%%%%%%#########%##**+++===++++++++++***+***
+========*%%%%@%########%%%%%%%%%%%%%##%##%%%##*++++=+++++********
*=========*%%%%%#***********##%%%%%%%%%%%%%%%%%%%####**++++++*****)" << endl;} };
class Panchan {
public:
    void Vstrecha() {
        bool flag = true;
        do {
            try {
                system("cls");
                Panchann();
                cout << "\n ________________________________________________________________";
                cout << "\n|                                                                |";
                cout << "\n|   ����� ��������, ���� ����� ������, � �������� ����� ������.  |";
                cout << "\n|________________________________________________________________|";
                cout << "\n\n ________________________________________________________________";
                cout << "\n|                                                                |";
                cout << "\n|             �������� �������                                   |";
                cout << "\n|     1. ������, ���������, �������� ��� ��� �����.              |";
                cout << "\n|     2. ������, � ������ ��� � ��� ������ ������ �� ���������.  |";
                cout << "\n|     3. ����� �����.                                            |";
                cout << "\n|________________________________________________________________|";

                int choice;
                cin >> choice;
                if (choice == 1, 2) {
                    switch (choice) {

                    case 1:
                        system("cls");
                        Panchann();
                        cout << "\n ________________________________________________________________";
                        cout << "\n|                                                                |";
                        cout << "\n| �� ������ ������ � ���� �� ������ ����� ������ ������� �����.  |";
                        cout << "\n|________________________________________________________________|";
                        break;
                    case 2:
                        system("cls");
                        Panchann();
                        cout << "\n ________________________________________________________________";
                        cout << "\n|                �� ��� ���, �� ������ ������                    |";
                        cout << "\n|        ����� ����� � ������� �������� ����� ���� ������        |";
                        cout << "\n|      ������ ���� �� �����, ����� ������� � �������� �����.     |";
                        cout << "\n|________________________________________________________________|";
                        break;
                    }
                    return;
                }
                if (choice == 3) {
                    system("cls");
                    Panchann();
                    cout << "\n ________________________________________________________________";
                    cout << "\n|                                                                |";
                    cout << "\n|                                                                |";
                    cout << "\n|________________________________________________________________|";
                    return;
                }
                string key;
                if (key != "1", key != "2") {
                    throw key;
                    flag = false;
                }
            }
            catch (string key) {
                cout << "Eroro Not found this example " << key;
                getchar();
            }

        } while (flag = true);
    }
};
auto Flopka{ []() {
        cout << R"(...................................................................
...................................................................
.................................:++-..............................
...*#%%+:.....................:*%##*++:............................
..-+:.:*%=...................####..................................
........*#*:...............-#*+##..................................
.........=*%+.............=%**##+..................................
..........:*#%=..........:#*++#%...................................
...........=*%%%##*#####%%%*+*##%#%%%%%%%%%#-......................
...........-###**#%#*####%#***######%%%%%%%%%%#:...................
...........*#%%*###**#@####*##%%#####%%%%%%%%%%%*-.................
..........+##%###%##*#%%%###**##****###%%%%%%%%%%%*................
.........-*%@@#*###+-#@@@%**###*=+**###%%%%%###%%%#*......--.......
.........-#**@#*##*=+@@%+*####%#+****##%%%%%########+....:#%=......
.........:###%%#****%@#**####*##****####%%###########*:.-*#*:......
...........#%%@####%@%%%%%%***#****#####%%###########%####*........
...........:#*%%%%@@**###++++##***######%################-.........
............**+#@%+=+#%@#+++**########%#%%##*#######%%###-.........
............:%#######%%#+++*########%%%%%%####**####%%%##-.........
..............=***+*++++++**########%%%%%%%####*###%%%%%#..........
..............:*#***********#######%####%%%%%###*#%%%%%%:..........
...............+************##########%%%%%%%%#**#%%%%*............
...............-**********#########%#%%%%@@%%%#**%%%#..............
................++*********#######%%%%%%%@@@%###@%=................
................=+++*+*******####%%%%%%%%%%@%%%%*:.................
................-#+++++++*******##%%%##%%%%%%#=....................
................=##*+++++++++++++*##%%%%#+-:.......................
...............+#%%#*+=+++=--:-+####%%%=...........................
.............:#%%%%#-...........:#%%%%=............................
.............:#%%%*............-%%%%%+.............................
..............:--.............-%%%%*:..............................
..............................=#*:.................................
...................................................................
)" << endl;} };
class Flopa {
public:
    void Sell() {
        system("cls");
        Flopka();
        cout << "\n ________________________________________________________________";
        cout << "\n|                                                                |";
        cout << "\n|   �����������, ������ �� �� �������� ������ ������ � ����?     |";
        cout << "\n|________________________________________________________________|";
        cout << "\n\n ________________________________________________________________";
        cout << "\n|                                                                 |";
        cout << "\n|   1. ������� ���� ���������.                                    |";
        cout << "\n|   2. ����� �����?                                               |";
        cout << "\n|_________________________________________________________________|";
        

    }
};*/