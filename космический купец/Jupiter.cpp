#include <iostream>
#include <vector>
#include <map>
#include <utility> 
#include "stdlib.h"
#include <conio.h>
#include <windows.h>
#include "ansiUtils.h" // ��� clear() | LT_leonid
using namespace std;
using namespace ansi;  // ��� clear() ��������


class Chunks {
protected:
    int chX, chY;
    int oldChX, oldChY;
public:
    Chunks(int chX = 0, int chY = 0, int oldChX = 0, int oldChY = 0) : chX(chX), chY(chY), oldChX(oldChX), oldChY(oldChY) {}
};

class Player {
protected:
    int x, y;
public:
    Player(int x = 0, int y = 1) : x(x), y(y) {}
};

class Decorations {
protected:
    vector<pair<int, int>> decoC1;
    vector<pair<int, int>> decoC2;
    vector<pair<int, pair<int, int>>> decoratedChunks;
    vector<pair<int, int>> nullChunks;
    int seed;
public:
    Decorations() {
        nullChunks = { {0 ,0}, {0, 1}, {1, 0}, {1, 1} };
        decoC1 = {};
        decoC2 = {};
    }
    bool isDecoration(int x, int y, int choice) const {
        switch (choice) {
        case 1:
            for (auto i : decoC1) {
                if (i.first == y && i.second == x) {
                    return true;
                }
            }
            break;
        case 2:
            for (auto i : decoC2) {
                if (i.first == y && i.second == x) {
                    return true;
                }
            }
            break;
        }
        return false;
    }
    void addRandomDeco(int x = 0, int y = 0, int choice = 1) {
        int rngY = rand() % 5;
        int rngX = rand() % 5;
        switch (choice) {
        case 1:
            decoC1.push_back({ rngX + x * 7, rngY + y * 5 });
            break;
        case 2:
            decoC2.push_back({ rngX + x * 7, rngY + y * 5 });
            break;
        }
    }
    void fillChunk() {
        for (int y = 0; y < 7; y++) {
            for (int x = 0; x < 5; x++) {
                addRandomDeco(x, y, 1);
                int chance = rand() % 10;
                if (chance <= 4) {
                    addRandomDeco(x, y, 2);
                }
            }
        }
    }
    void addSeedToChs(int seed, int x, int y) {
        decoratedChunks.push_back({ seed, {x, y} });
    }
    int getSeed(int x, int y) {
        for (auto i : decoratedChunks) {
            if (i.second.first == x && i.second.second == y) {
                return i.first;
            }
        }
        return 0;
    }
    void print() {
        for (auto i : decoratedChunks) {
            cout << i.first << " " << i.second.first << " " << i.second.second << endl;
        }
    }
    void clearChunk() {
        decoC1 = {};
        decoC2 = {};
    }
};

class Obstacles {
    vector<pair<int, int>> obstC;
    vector<pair<pair<int, int>, pair<int, int>>> largeObstC;
    vector<pair<int, int>> deleteObstC;
    vector<pair<pair<int, int>, pair<int, int>>> deleteLargeObstC;
public:
    Obstacles() {
        //yx
        largeObstC = { {{25,34},{49,34} },{{32,30},{42,34} } }; // ������ ��� ������� �����������
        deleteLargeObstC = { {{27,33},{49,32}},{{33,31},{41,34}},{{35,30},{39,30}} }; // ������� ������� ������ �����������
        obstC = { {5,35},{4,35},{3,35},{2,35},{1,35},{0,35},{5,36},{5,37},{5,38},{5,39},{5,40},{5,41},{5,42},{5,43},{5,44},{5,45},{5,46},{5,47},{5,48},{5,49},{5,50},     {5,51},{5,52},{5,53},{5,54},{5,55},{5,56},{5,57},{5,58},{5,59},{5,60},{5,61},{5,62},{5,63},{5,64},{5,65},{5,66},{5,67},{5,68},{5,69},{4,69},{3,69},{2,69},{1,69},{0,69},
            //������                                                     
            {24,35},{24,36},{24,37},{24,38},{23,38},{22,38},{21,38},{20,38},{19,38},{18,39},{18,40},{18,41},{18,42},{18,43},{18,44},{18,45},{18,46},{18,47},{18,48},{18,49},{18,50},
            {18,54},{18,55},{18,56},{18,57},{18,58},{18,59},{18,60},{18,61},{18,62},{18,63},{18,64},{18,65},{19,66},{20,66},{21,66},{22,66},{23,66},{23,66},{24,66},{24,67},{24,68},{24,69},
            //����� �������
            {25,35},{25,36},{25,37},{25,38},{25,39},{25,40},{25,41},{25,42},{25,43},{25,44},{25,45},{25,46},{25,47},{25,48},{25,49},{25,50},{25,54},{25,55},{25,56},{25,57},{25,58},{25,59},{25,60},{25,61},{25,62},{25,63},{25,64},{25,65},{25,66},
            {25,67},{25,68},{25,69},
            {26,35},{27,35},{28,35},{29,35},{30,35},{31,35},{32,35},{33,35},{34,35},{38,35},{39,35},{40,35},{41,35},{42,35},{43,35},{44,35},{45,35},{46,35},{47,35},{48,35},{49,35},{49,35},
            {49,36},{49,37},{49,38},{49,39},{49,40},{49,41},{49,42},{49,43},{49,44},{49,45},{49,46},{49,47},{49,48},{49,49},{49,50},{49,51},{49,52},{49,53},{49,54},{49,55},{49,56},{49,57},
            {49,58},{49,59},{49,60},{49,61},{49,62},{49,63},{49,64},{49,65},{49,66},{49,67},{49,68},{49,69},
            {26,69},{27,69},{28,69},{29,69},{30,69},{31,69},{32,69},{33,69},{34,69},{35,69},{36,69},{37,69},{38,69},{39,69},{40,69},{41,69},{42,69},{43,69},{44,69},{45,69},{46,69},{47,69},{48,69},{49,69},{49,69},
            {26,63},{27,63},{28,63},{29,63},{30,63},{31,63},{32,63},{33,63},{34,63},{35,63},{36,63},{37,63},{38,63},{39,63},{40,63},{41,63},{42,63},{43,63},{44,63},{45,63},{46,63},{47,63},{48,63},{49,63},
            //�������    
            {28,38},{28,39},{28,40},{28,41},{28,42},{29,38},{29,39},{29,40},{29,41},{29,42},{30,38},{30,39},{30,40},{30,41},{30,42},{31,38},{31,39},{31,40},{31,41},{31,42},
            {28,54},{28,55},{28,56},{28,57},{28,58},{29,54},{29,55},{29,56},{29,57},{29,58},{30,54},{30,55},{30,56},{30,57},{30,58},{31,54},{31,55},{31,56},{31,57},{31,58},
            {46,54},{46,55},{46,56},{46,57},{46,58},{45,54},{45,55},{45,56},{45,57},{45,58},{44,54},{44,55},{44,56},{44,57},{44,58},{43,54},{43,55},{43,56},{43,57},{43,58},
            {46,38},{46,39},{46,40},{46,41},{46,42},{45,38},{45,39},{45,40},{45,41},{45,42},{44,38},{44,39},{44,40},{44,41},{44,42},{43,38},{43,39},{43,40},{43,41},{43,42},
            //������
            {40,10},{41,10},{39,10},{38,10},{37,10},{36,10},{35,10},{34,11},{42,11},{43,12},{33,12},{32,13},{32,14},{32,15},{32,16},{32,17},{44,13},{44,14},{44,15},{44,16},{44,17},{44,18},{32,18},{43,19},
            {42,20},{41,21},{40,21},{39,21},{38,21},{37,21},{36,21},{33,19},{34,20},{35,21},


        };
        // ������ ��� �������� �����������
        deleteObstC = { {12,4}, }; // ������� ������� �����������
        for (auto i : largeObstC) {
            for (int j = i.first.first; j <= i.second.first; ++j) {
                for (int k = i.first.second; k <= i.second.second; ++k) {
                    obstC.push_back({ j,k });
                }
            }
        }
        deleteObstacles();
    }

    bool isObstacle(int y, int x) const {
        for (auto i : obstC) {
            if (i.first == x && i.second == y) {
                return true;
            }
        }
        return false;
    }

    void deleteObstacles() {
        for (auto& delRange : deleteLargeObstC) {
            int x1 = delRange.first.first, y1 = delRange.first.second;
            int x2 = delRange.second.first, y2 = delRange.second.second;

            // ������� �� ���� ������ � obstC � ������ ��, ������� ����� � ���������
            obstC.erase(remove_if(obstC.begin(), obstC.end(), [&](const pair<int, int>& p) {
                return p.first >= x1 && p.first <= x2 && p.second >= y1 && p.second <= y2;
                }), obstC.end());
        }
        for (auto& point : deleteObstC) {
            obstC.erase(remove(obstC.begin(), obstC.end(), point), obstC.end());
        }
    }

    void printObst() {
        for (auto i : obstC) {
            cout << i.first << ", " << i.second << "\n";
        }
    }
};class Map : public Player, public Chunks, public Obstacles, public Decorations {
    vector<Chunks> chunks;
public:
    void printMap() {
        clear();
        for (int y = chY * 25; y < 25 + (chY * 25); ++y) {
            for (int x = chX * 35; x < 35 + (chX * 35); ++x) {
                // ���������
                if (x == this->x && y == this->y) {
                    cout << "��";
                }
                else if (isObstacle(x, y)) {
                    cout << "##";
                }
                // ������� ����� ����� x<35 y<25
                else if ((x > -1 && y > -1) && (x < 1 && y < 25)) { cout << "[]"; }
                else if ((x > -1 && y > -1) && (x < 35 && y < 1)) { cout << "[]"; }
                else if ((x > -1 && y > 25) && (x < 35 && y < 25)) { cout << "[]"; }

                // ������� ������ ����
                else if ((x >= 40 && y >= 20) && (x <= 40 && y <= 23)) { cout << "| "; }
                else if ((x >= 40 && y >= 19) && (x <= 41 && y <= 19)) { cout << "__"; }
                else if ((x >= 42 && y >= 20) && (x <= 42 && y <= 21)) { cout << "| "; }//�
                else if ((x >= 40 && y >= 21) && (x <= 41 && y <= 21)) { cout << "__"; }

                else if ((x >= 43 && y >= 20) && (x <= 43 && y <= 23)) { cout << "| "; }
                else if ((x >= 43 && y >= 19) && (x <= 44 && y <= 19)) { cout << "__"; }
                else if ((x >= 43 && y >= 21) && (x <= 44 && y <= 21)) { cout << "__"; }//�
                else if ((x >= 43 && y >= 23) && (x <= 44 && y <= 23)) { cout << "__"; }

                else if ((x >= 46 && y >= 20) && (x <= 46 && y <= 23)) { cout << "| "; }
                else if ((x >= 46 && y >= 19) && (x <= 47 && y <= 19)) { cout << "__"; }//C
                else if ((x >= 46 && y >= 23) && (x <= 47 && y <= 23)) { cout << "__"; }

                else if ((x >= 50 && y >= 20) && (x <= 50 && y <= 23)) { cout << "| "; }//T
                else if ((x >= 49 && y >= 19) && (x <= 51 && y <= 19)) { cout << "__"; }

                else if ((x >= 53 && y >= 20) && (x <= 53 && y <= 23)) { cout << "| "; }
                else if ((x >= 53 && y >= 19) && (x <= 54 && y <= 19)) { cout << "__"; }//O
                else if ((x >= 53 && y >= 23) && (x <= 54 && y <= 23)) { cout << "__"; }
                else if ((x >= 55 && y >= 20) && (x <= 55 && y <= 23)) { cout << "|"; }

                else if ((x >= 56 && y >= 20) && (x <= 56 && y <= 23)) { cout << "| "; }
                else if ((x >= 56 && y >= 19) && (x <= 57 && y <= 19)) { cout << "__"; }//P                         ������ ���� �������� ������
                else if ((x >= 58 && y >= 20) && (x <= 58 && y <= 21)) { cout << "| "; }
                else if ((x >= 56 && y >= 21) && (x <= 57 && y <= 21)) { cout << "__"; }

                else if ((x >= 59 && y >= 20) && (x <= 59 && y <= 23)) { cout << "| "; }
                else if ((x >= 59 && y >= 19) && (x <= 60 && y <= 19)) { cout << "__"; }
                else if ((x >= 61 && y >= 20) && (x <= 61 && y <= 23)) { cout << "| "; }//A
                else if ((x >= 59 && y >= 21) && (x <= 60 && y <= 21)) { cout << "__"; }

                else if ((x >= 62 && y >= 20) && (x <= 62 && y <= 23)) { cout << "| "; }
                else if ((x >= 62 && y >= 21) && (x <= 63 && y <= 21)) { cout << "__"; }//H
                else if ((x >= 64 && y >= 20) && (x <= 64 && y <= 23)) { cout << "|  "; }

                else if ((x >= 43 && y >= 3) && (x <= 43 && y <= 3)) { cout << "PR"; }
                else if ((x >= 52 && y >= 3) && (x <= 52 && y <= 3)) { cout << "PR"; }
                else if ((x >= 61 && y >= 3) && (x <= 61 && y <= 3)) { cout << "PR"; }

                //4 ����

                else if ((x >= 61 && y >= 31) && (x <= 61 && y <= 31)) { cout << "[]"; }
                else if ((x >= 61 && y >= 34) && (x <= 61 && y <= 34)) { cout << "[]"; }
                else if ((x >= 61 && y >= 37) && (x <= 61 && y <= 37)) { cout << "[]"; }
                else if ((x >= 61 && y >= 40) && (x <= 61 && y <= 40)) { cout << "[]"; }
                else if ((x >= 61 && y >= 43) && (x <= 61 && y <= 43)) { cout << "[]"; }

                else if ((x >= 61 && y >= 31) && (x <= 61 && y <= 31)) { cout << "[]"; }
                else if ((x >= 61 && y >= 34) && (x <= 61 && y <= 34)) { cout << "[]"; }
                else if ((x >= 61 && y >= 37) && (x <= 61 && y <= 37)) { cout << "[]"; }
                else if ((x >= 61 && y >= 40) && (x <= 61 && y <= 40)) { cout << "[]"; }
                else if ((x >= 61 && y >= 43) && (x <= 61 && y <= 43)) { cout << "[]"; }
                //3 ����
                else if ((x >= 2 && y >= 41) && (x <= 2 && y <= 45)) { cout << "[]"; }
                else if ((x >= 2 && y >= 31) && (x <= 2 && y <= 35)) { cout << "[]"; }
                else if ((x >= 9 && y >= 48) && (x <= 14 && y <= 48)) { cout << "[]"; }
                else if ((x >= 18 && y >= 48) && (x <= 23 && y <= 48)) { cout << "[]"; }
                else if ((x >= 18 && y >= 28) && (x <= 23 && y <= 28)) { cout << "[]"; }
                else if ((x >= 9 && y >= 28) && (x <= 14 && y <= 28)) { cout << "[]"; }




                // ������
                else if (isDecoration(x - chX * 35, y - chY * 25, 2)) { cout << "/#"; }
                else if (isDecoration(x - 1 - chX * 35, y - chY * 25, 2)) { cout << "&#"; }
                else if (isDecoration(x - 2 - chX * 35, y - chY * 25, 2)) { cout << "#\\"; }
                else if (isDecoration(x - chX * 35, y - 1 - chY * 25, 2)) { cout << "#&"; }
                else if (isDecoration(x - 1 - chX * 35, y - 1 - chY * 25, 2)) { cout << "##"; }
                else if (isDecoration(x - 2 - chX * 35, y - 1 - chY * 25, 2)) { cout << "&#"; }
                else if (isDecoration(x - chX * 35, y - 2 - chY * 25, 2)) { cout << "\\#"; }
                else if (isDecoration(x - 1 - chX * 35, y - 2 - chY * 25, 2)) { cout << "#&"; }
                else if (isDecoration(x - 2 - chX * 35, y - 2 - chY * 25, 2)) { cout << "#/"; }
                else if (isDecoration(x - 1 - chX * 35, y - 3 - chY * 25, 2)) { cout << "||"; }
                else if (isDecoration(x - 1 - chX * 35, y - 4 - chY * 25, 2)) { cout << "||"; }
                // �����
                else if (isDecoration(x - chX * 35, y - chY * 25, 1)) { cout << ".,"; }
                else if (isDecoration(x - 1 - chX * 35, y - chY * 25, 1)) { cout << "\"\""; }
                else if (isDecoration(x - 2 - chX * 35, y - chY * 25, 1)) { cout << ",."; }
                // ������ 
                else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << getSeed(chX, chY);
    }
    void movePlayer(int dx, int dy) {
        int newX = x + dx;
        int newY = y + dy;
        oldChX = chX;
        oldChY = chY;
        if (isObstacle(newX, newY) == false) {

            x = newX;
            y = newY;
            if (newX < 0) {
                chX = newX / 35 - 1;
            }
            else {
                chX = newX / 35;
            }
            if (newY < 0) {
                chY = newY / 25 - 1;
            }
            else {
                chY = newY / 25;
            }
        }
    }
    void tick() {
        if (oldChY != chY || oldChX != chX) {
            clearChunk();
            bool check = false;
            for (auto i : nullChunks) {
                if (chX == i.first && chY == i.second) {
                    check = true;
                }
            }
            if (!check) {
                fillChunk();
            }
        }
        if (getSeed(chX, chY) != 0) {
            seed = getSeed(chX, chY);
        }
        else {
            seed = rand();
            addSeedToChs(seed, chX, chY);
        }
    }
    void initMap() {
        while (true) {
            tick();
            srand(seed);
            this->printMap();
            char input = _getch();
            switch (input) {
            case 'd':
                this->movePlayer(1, 0);
                break;
            case 's':
                this->movePlayer(0, 1);
                break;
            case 'a':
                this->movePlayer(-1, 0);
                break;
            case 'w':
                this->movePlayer(0, -1);
                break;
            }
        }
    }
};

void cvest1() {
    cout << "� ������� ��� �� �� ������� ���������� �������� ������� � �������, ������� ��� � � ������ ����";
};
void cvest2() {
    cout << "������, ��� �� ������� ������� ��� ������, �� ����� ������� ��� ������ ��, ������� ������� �� �������";
};
auto Panchan{ []() {cout << R"(..............................................::::+*******=======-
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

class PanchanDial {
public:
    void Vstrecha() {
        bool flag = true;
        do {
            try {
                system("cls");
                Panchan();
                cout << "\n\n ________________________________________________________________";
                cout << "\n|                                                                |";
                cout << "\n|   ����� ��������, ���� ����� ������, � �������� ����� ������   |";
                cout << "\n|________________________________________________________________|";
                cout << "\t\t\n\n ________________________________________________________________";
                cout << "\t\t\n|                                                                |";
                cout << "\t\t\n|             �������� �������                                   |";
                cout << "\t\t\n|     1. ������, ���������, �������� ��� ��� �����               |";
                cout << "\t\t\n|     2. ������, � ������ ��� � ��� ������ ������ �� ���������   |";
                cout << "\t\t\n ________________________________________________________________|";
                int choice;
                cin >> choice;
                switch (choice) {
                case 1:
                    system("cls");
                    Panchan();
                    cout << "\n ________________________________________________________________";
                    cout << "\n|                                                                |";
                    cout << "\n| �� ������ ������ � ���� �� ������ ����� ������ ������� �����   |";
                    cout << "\n|________________________________________________________________|";
                    break;
                case 2:
                    system("cls");
                    Panchan();
                    cout << "\n ________________________________________________________________";
                    cout << "\n|                �� ��� ���, �� ������ ������                    |";
                    cout << "\n|        ����� ����� � ������� �������� ����� ���� ������        |";
                    cout << "\n|      ������ ���� �� �����, ����� ������� � �������� �����      |";
                    cout << "\n|________________________________________________________________|";
                    break;
                }
                string key;
                cin >> key;
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

        cout << "\n\n ________________________________________________________________";
        cout << "\n|                                                                |";
        cout << "\n|                  ������ ���                                    |";
        cout << "\n|                          �����                                 |";
        cout << "\n|                                                                |";
        cout << "\n|                                                                |";
        cout << "\n ________________________________________________________________|";
    }
};