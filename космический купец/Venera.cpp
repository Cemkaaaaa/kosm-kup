﻿#include <iostream>
#include <vector>
#include <conio.h>
#include "player.h"
#include "fight.h"
#include <windows.h>
using namespace std;

void clear()
{
    system("cls");
}
void Print_Replica() {
    bool flag = false;
    while (flag != false)
    {
        clear();
        std::cout << R"(
──────▄▀▄─────▄▀▄
─────▄█░░▀▀▀▀▀░░█▄
─▄▄──█░░░░░░░░░░░█──▄▄
█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█)";
        std::cout << "Барман: Добро пожаловать что желаете\n1)бананчик\n";
        std::cout << R"(
________________________1¶¶¶¶_____________________
_______________________1¶__¶¶¶¶___________________
_______________________¶1___1¶¶¶__________________
_______________________¶1____11¶¶_________________
_______________________¶1_____11¶1________________
___________1111111_____¶1______¶1¶________________
________1¶¶111111¶¶¶¶1_¶1______11¶¶_______________
________¶¶¶111______1¶¶¶1_______¶1¶_______________
_________1¶¶¶¶¶¶¶1_____¶¶_______¶1¶1______________
_____________1¶¶¶¶¶1___1¶_______11¶¶______________
________________¶¶1¶1__1¶_______11¶¶______________
_________________1¶_¶___¶________11¶______________
__________________¶¶1¶__¶________11¶______________
___________________¶_¶1_¶________11¶11111_________
___________________1¶_¶_¶________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1_
____________________¶1¶¶¶1______¶1111111¶11¶___1¶_
___________________1111111¶¶__1¶111_11¶11¶_¶1___¶1
________________1¶1111111¶1¶¶1¶_¶1_11¶___1¶1¶___¶1
_____________11¶¶_1¶1_____1_¶¶_¶1_1¶¶_____¶_____¶_
___________1¶¶¶¶_¶¶¶1_______¶_¶1_1¶¶1_____¶____¶¶_
__________1¶__¶_¶1__¶¶_____111¶_¶11¶______¶___¶¶__
__________¶1___1¶___¶¶______1__11¶¶______1¶__¶¶___
__________¶____¶____¶1_____1¶__¶¶¶1______¶1_¶1____
_________1¶___¶¶___¶¶_____¶¶__¶1¶¶______1¶_¶1_____
_________¶¶__¶¶___¶¶_____¶¶___1¶¶_______¶¶1¶______
_________¶1_¶¶__1¶1____1¶1___¶1¶_________11_______
________¶¶_¶¶__¶¶____1¶¶___1¶1¶___________________
_______1¶¶¶1_¶¶1____¶¶1___11¶¶____________________
________11__¶¶____1¶¶_____¶¶¶_____________________
___________¶1____¶¶1____¶¶1¶______________________
__________¶1___1¶1____1¶1¶¶_______________________
_________¶1___¶¶____111¶¶1________________________
________¶¶__1¶1___1_1¶¶¶__________________________
________¶1_1¶1____¶¶¶¶1___________________________
_______¶¶__1¶__1¶¶¶¶1_____________________________
____1¶¶1____1¶¶¶¶¶1_______________________________
1¶¶¶¶1__1¶¶¶¶11___________________________________
¶¶¶¶_1¶¶1_________________________________________
1¶1¶¶¶____________________________________________)";
        std::cout << "\n2)Конфета\n ";
        std::cout << R"(______________________________________¶¶__________
___________________________________¶1_¶1¶1________
__________________________________1¶¶¶__1¶¶_______
__________________________________¶1_¶____1¶¶1____
__________________________________¶¶_________1¶___
__________________________________¶¶_________¶¶11_
________________________1¶¶11111__1¶__¶_____11_1¶_
___________________1¶¶¶¶111¶¶11¶¶¶¶¶¶1¶¶__1___1¶11
_________________1¶1__1¶___1¶________¶¶¶¶¶¶_____1¶
_______________1¶1_____¶1___1¶_________¶1_____¶¶__
______________¶¶¶_______¶____¶¶________1¶___11¶¶__
_____________¶¶_1¶______1¶____¶¶_______¶¶11¶11____
____________¶¶¶__¶1______1¶____¶¶______¶¶_________
____________¶_¶1__¶1______1¶____¶¶_____1¶_________
___________1¶_1¶__1¶________¶1___1¶1___1¶_________
___________1¶__¶¶__1¶________¶¶____¶¶__1¶_________
____________¶___¶¶__1¶1_______¶¶_____1¶¶1_________
_________111¶1___¶¶___¶1_______1¶¶____¶¶__________
___¶¶¶¶¶¶11¶1_____¶¶___¶¶________1¶1¶¶¶___________
1¶¶¶_____11¶1______1¶1__1¶1________¶¶_____________
_1¶¶1___1¶¶¶¶1_______¶1___¶¶____1¶¶1______________
___1¶¶_____¶¶¶¶¶¶¶11__1¶1__1¶¶¶¶¶1________________
____¶¶_____1¶__1¶_1¶¶¶1¶¶¶¶¶111___________________
____1¶__________¶_________________________________
_____1¶1______¶¶¶_________________________________
_______¶¶¶11_1¶___________________________________
__________¶¶11____________________________________)";
        std::cout << "\n3)Вишня\n";
        std::cout << R"(__________________________________________________
________________________1¶1_______________________
_______________________1¶¶¶_______________________
_______________________¶¶__1111111________________
_____________________1¶1___¶¶¶¶¶¶¶¶¶¶_____________
____________________1¶1___1¶1111111¶¶¶¶___________
___________________¶¶1____1¶1111111111¶¶1_________
__________________¶¶______1¶1111¶1111111¶¶1_______
_________________¶¶________¶¶¶11111111111¶¶1______
________________¶¶_________1¶¶¶¶1111111111¶¶¶_____
_______________1¶___________1¶¶¶¶¶¶1111¶111¶¶1____
_______________¶1____________1¶¶¶¶¶1¶11111¶¶¶¶____
______________¶¶______________1¶¶111¶¶¶1¶¶¶¶¶¶1___
______________¶_________________¶¶¶¶¶¶¶¶¶¶¶¶1¶¶___
_____________1¶__________________1¶¶¶¶¶¶¶¶¶¶¶¶¶___
_____________¶1_____________________11¶¶¶¶¶¶¶¶¶___
_____________¶1________________________1¶¶¶¶¶¶¶___
_____________¶_____________________________1¶¶¶1__
_____________¶________________________________¶¶__
_____________¶____________________________________
_____________¶1___________________________________
_____________¶1___________________________________
_____________¶¶___________________________________
_____________1¶___11¶¶¶11_________________________
____________11¶1¶¶¶¶¶¶¶¶¶¶1_______________________
_______1¶¶¶¶¶1¶¶¶¶¶¶¶¶¶¶¶¶¶¶______________________
_____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1_____________________
____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶111¶¶¶¶1____________________
___1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1_1¶¶¶¶¶____________________
___¶¶1_1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶____________________
___¶¶¶¶1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1____________________
___1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_____________________
____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1_____________________
_____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶______________________
______1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_______________________
_______1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1________________________
_________1¶¶¶¶¶¶¶¶¶¶¶¶¶1__________________________
__________________________________________________)";
        std::cout << "\n Введите  ваш выбор:";
        int key;
        std::cin >> key;
        switch (key) {
        case 1:
            std::cout << "\nОтличный выбор ";
            flag == true;
            break;
        case 2:
            std::cout << "\nОтличный выбор ";
            flag == true;
            break;
        case 3:
            std::cout << "\nОтличный выбор ";
            flag == true;
            break;
        }
    }
}
void Print_Text()
    {
        clear();

        std::cout << R"(
.......................-+=-:................................
......................=%###%%@%=............................
.....................:==*#%%@@@@@-..........................
..................:::##%%@@@@@@@@@..........................
...............:%@@@%-=====*%%@@@@=.........................
................:+*#*+=====+*++=+#-.........................
...................-======+****=-+-.........................
.................:+.:++++++****=**+.........................
..............:-*#@..=+++++*####**+.........................
............:-=--#%...===+*####***#-........................
............+++#%%-....*#%%%#***++*%%-......................
............-+==*:.....-%@##***+++#%@#@@@#:.................
............:-:=:...:%@#%%++*++==#@@@@@@%####*:.............
........*-:-=-...:=*#%%%@%%%#++#@@@@@@@@%#%%%@@*............
.......*%##@*..=#%%%%%@%%%%%%%@%%%%@%%---@%%@@@%*...........
......+%#%@%::#%%%###%%%%%%%%@%%%%%%@%=+=#@%@@@%#=..........
....-%@##%@@@@@@%%###%%%%%%%%%%%##%%%%%%@@@@@@@%*+-.........
...:%%##%@@@@@@@%%####%%##%%%%%##%%%%%%%@@@@@@%@@*+-........
..:####%%@%%@@@@%%%#%%%#%%@%%%%%%%%@%%%@@@@%@@@@@@%#........
..-####%#:@%+@=-%*##=#%%#+#*%-%-%@=@=%:+*+=@@@@%%@@@%.......
..+###%%@:%#+%+*##+%:%.%++#*%-%-%@=%:#*+*+*-@@@%%%@@%*......
..####%%@@@@@@@@=*#########%%%%#%#@%#%@%@@@-*@@@%%%@@@*.....
.=####%%%@@@#:...=###########%##%#%%%#%@@@#..=@@%%@@@@%=....
..*%%%@@#-.......:##%%%%%%###%##%%#@%%%@@@*..:%@%%@@@@@@=...
.................:%@%########%####%%@@%@@@*....=@%%@%%%@*...
.................:#%%########%####%%@@@@@@-.....:%%%%%@@#:..
................:-.=%%%######%###%%%%%@@@@#+:....*%#%#%@@-..
...............#%%@#@%#########%%%@@%@@@@@@@%....:%%%%%%@=..
..............-@%%@@%%%%%%%%%%%%@@@@@@@@@#%@*.....:#%#%@@-..
..............-@##@%#%%####%=-=##@@@@@@@@%#@-......-##%%%-..
..............*#*%@%%#+***#%*++%#@@@@@@@@@#%:......-+:=%@:..
)";
        std::cout << "/t/t/tОхрана вы записаны  проходите ";
        getchar();
    }


    void Replica() {
        bool flag = true;
        do {
            try {
                clear();
                std::cout << "/t/t/t/t/tVadim:/n";
                std::cout << R"(
@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@
@@%%%@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@
%%%@@%%%@@@@@@@@@@@%%%%%%%%%%%%%%%%%%@%@%%%@@@%#***%@@@@@@@@
%%#%%%%%%%%%%+=+%@%%%%*#%*+=*+-#*#*=*%%%%%%@%**++*##@@@@@@@@
%%#%%%#%%%@%#==+++%%%%++++*++=+#+#+-+**%%%%#*+++++*#@@@@@@@@
###%%%#%%%#%*====*%%%%##%**%**%%#%**%##%%@@%++===+*#@@@@@@@@
+**#%%##%%#%*=====-%%%%#****##%%#*%##%%%%@%%+===++*#%@@@@@@@
++*+*###%%#%#+==+##%%%%%%%%%%%%%%%%%%%%%%@%++==+++*%%%@@@@@@
#++=++*#%%#%#+===%%%%%%%%%%%%%%%%%%%%%%%%%%%*++==+*%%%%%%%%@
%%%**##+*##%%#==*%%%#*+==++==+%@@@@@%%%%%%%%#==++*#%%%#%%#%%
##%%#%%%%@@@%#+++*##########%%%%##%%%%%%%%%%%*++*#%%%%%%%%%%
##########%%%#==#@@@@%+-:-==--======-:-=*@@@@*=+*#%%%%%%%%%%
###+#########+==##@%%#@%=:-========::=%%#+%@%%*++%@%@@@@@@@@
###**###*###+-::**#@@@*#%:--===+=-=:-@+#@@@@+#::-*%%@@%@@%@@
###*####*##**+===-::::-+#+==-----==+##*====----=+*#%@%%@@%@@
###**#####*==+++++=+==++=++==----==****+-====++**+#%%%%%@%@@
#########*==****+=====--=+#**++++***==-====++**+===*%%%%@@@@
%%%%%####++=+++*+=+++=--:=#@%*++#%#+----==+=+#*****#@@@@@@@@
%%%%%%%%%*=+=-==+=--=--::..:##%##-...:----=*+==-=+*#@@@@@@@@
%%%%%%##%#=-----=====--:::::-*%+-::::::----+===++=+%@@@@@@@@
%%%###%#+*+=-:::--====------=+*+=-:-----==--------*%%%%@%@@@
%%%%####*+-=====--==++++====-----====++=--::-----+**+++***#*
##***++++--===---==++++++++===========----=======++**#####%%
**++****+=--====-------=====++*+=+------------==+*#*****####
********+=-==++=--------:-:--::=--:::--------=++**+*###**#%%
******+=+++=---===-----::::+-::-=::--------==+***++*########
***+==-==+*+=---===+===--=+=--:-=------=+++****+==+*#%#%####
++==-:-+*+*##**+==++++*++====--====++******+=====+*##%%#####
=*+===+##***##%###**+++++++==+=++=+=+++++=====++*##*+#%%%%%%
=+++***%%###***#%%%#######+++++++*+++=++++++++******#%%%%###
+++****#######******###*##**++++*#%####*#####***+**#@@%%####
*******##%%#%%####******++*+++=+++*#######**++++*##%@@@%%%%%)";
                std::cout << "/t/t/t/t Дароу в клуб хочешь?(1 - да 2- нет) ";
                std::string key;
                std::cin >> key;
                if (key == "1") {
                    // тут должен быть телепорт в клуб а где лучшие тусовки ? у нас в клубе  или чо ты там придумаешь ренатик
                }
                if (key == "2") {
                    clear();
                }
                if (key != "1", key != "2") {
                    throw key;
                    flag = false;
                }
            }
            catch (std::string key) {
                std::cout << "Eroro Not found this example " << key;
                getchar();
            }

        } while (flag = true);
    }


    void Verstappen() {
        clear();
        cout << "\t\t\t\t\tMax Verstappen:\n"; // Исправлен синтаксис отступа
        cout << R"(
#######********++++++==============++++++******************#
#####******++++++=====--===---==--=====++++++++*******++****
######**++++++++===-===-------------=====++++++*************
#####***+++++===-==--------------------======++++*****+*****
##*****++++++==-----------------------------===++++++*******
##***++===+====-------------------------------===++++***+***
*****++===-====----------------------------------=+++***++**
***++========-------------+++++=--------------======+++++++*
***++=====-------------+%%%%%#**%*=-------------====+++++=+*
#**+++++===----------+%@@%%%%####%%#=-----------=====+++++++
#**+++====----:-----*%@@%%%###*+++*##------------=====++****
****++=====---:-----%%@#*==--:::::-*+=----------======+++***
****+++=--=---:-----%%%#+=-:::::::=#*=---------=======++****
**+++++==-==-------=%%*#**#*--++==-=#+--------====++++++*+**
**++++++=====------=%***+=+#=:-=---:=----------=====+++*+++*
**++++++=+===------+%**+-=*#=--:::::-=------========++++=++*
***++++++=+===------*##*++*#*=-::::-:------=========++++=++*
#*++++++=++======-----*##***+==-:::----------======+++++++**
***+++++====+++=====--+###**+=---:-===============+++++*****
****+++===+*++========*%%%#+=---==-*#*++++======++++=+******
****+++=+++*++=++==+++*%%%%%%*+=-:-****#**++++++++++++******
***++++=-=*+++==---=++=*%%#*=--::::=*********+++++++********
****+++++==+++-----=++++=*##=-----=*************+++*********
#***+++++==++=-------=+++++++=++******+*******#**********#**
##**+++++==++=---------===++*++**+++===+********###******###
##*****+==+*+-=-==-------------------==***+******###****####
##****=-==+*=+====-----------==------==+*++******#%%#*######
#****=--=++++=====---------==++==-----==+=+**+**######*#####
###+=----+*+=+=++==--------==++==-----==+++*+++*#%##%#######
#*+=-=---=+====+=+=-------:-====-:::-===+++**++*#####%######
*+==------+====+++=-------=*+*****=--==+*++**+*#####%#%#####
++==-=---===++==++==-----=*#######+====+*=***+########%%####
++=====--=-=++==++==------=+****+=--=+*+===+**#########%%###
*+=+====---=++=-+++=-===---:-+*====+++=======+*########%%%##
*+++=+=-=--=*+=-=*+======-----:---+++==+===+===+*######%%%%#
**+++=======+*=--*+=======--------==+**=======+++=*#%%%%%%%%
**+++=++====+*+==++================++******##***+==*#####%%%
**++++++++++=+=--+++================+*+**####***+=++#####%%%
#******+*++++*=--*+++====+====+++=+++*+***##*+**==++*####%%%
####**+++++*******++=+++++=++++++++++*+**###*++*=++++*####%%
######*####%%%######***********#*+**+***####*=++=++=+*#####%
###########%%###*+=+=+=+++++++*+****+*######*=++=+++++#####%
############%##*+=+=+==-=+=++++*****+*#######==+=++*++####%%
###############*+=+++===+=+=+***++**+*########=*=+++***##%%%
#############%*+=++=+===+++=+**++***+*########+++=++++**##%%%)";
        cout << "\t\t\t\tТы прибыл на Венеру\n"; // Исправлен синтаксис
        _getch();
        cout << "\t\t\t\tПрекрасное место для отдыха и не более\n";
        cout << "\t\t\t\tБольше тебя задерживать не буду.\n";
        clear();
    }
    void Dialog() {
        bool flag = false;
        std::cout << R"(
==-===-=-:===-===--=-------:--:::::--.::::---:::::::::::::::
=======-=-:===-=====-------::--..::-:-:::--::--::--:-:::-::.
=====++=-=--======---------:::::.:---------::--:::::--::::::
+=++=======:-======-===-----::-:..:--------=--=::::::-::::::
+++++=++=-=--======--==-----::--:.::::---::-::-:::::::::--::
+++=++=++===--==========-=---::--:.:::--:--:--::::::::::::::
+++++++++===--========+#%%%%#*---:.:::---------------:::::::
++++++++++===--======#%%######%#=-:.:--::::---=++**=--=:::::
=++++++++++===:-====*+=++====*##*-:.::::::-------::...:-::::
-++++++++++==+--===#*+=------+*#*--:::::::-:--..........-:::
+=++++++++++======*#*++=====-==+=--..::.::::--..........::::
+-:::::::::.:---=*%%*=+--=-------:-:..:.:::::-...........::-
.:::........:--==+#%%%+===--==-+-:--:::::::::-...........:::
::::--..:::::-=++++*##*+========-:--:.:::::::-............::
::.::::---::::::::::-=**+=====+=:..:..:-:::::-............-:
:::::......:::::...:::=+++=====::.:......::-:-:...........::
+-...:...:....:......:.-====-:.............-::-...........::
%++:::::::::...:.........:..................::-:..........:-
#+=--+##+::-::..::....:...........:..........:--.......:.::-
#+=--=**##%=:::..::............:-+=....:......:-..........:-
#*=---*#**#=::::..::...........-++=-:.::.......:--::::::::--
#+=--=***##=:::-:...:.........:======-==:.......::::::::::-:
#+---=*#*##*::::-:...:.........==---==:..........::::::::::-
#*=--+******::::--:.:.:::......-=-=++++-.......:::----:--::-
#*=--+*#**#-::::::--:...:.......-++++*+-:.....::::.:::::::--
##+--+***#+:::::::::::...:........:::--+-:....-::::-:::::::-
##+--+**#*=:::::::::..::.....:::.:::--==---:-===-+-::::-::::
###--=****-::-:::::::...::........::::--#%%%%%%%%%%%%%###*++
###*--*****::=+==::::....:::..::::::-*##++++#%##%%%%########
####+-****####*==--:::......:::::=#%%%%%#====###%%%%########
####*****###%%%%%%%%%##%%##%%@%%%%%%%%%%%%#**##%%%%%#%%#%%%#
####*=#***##%@@%@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#####=***####@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#)";
        while (!flag) {
            std::cout << "/nPetya: куда летим воин?: 1 2 3";
            int key;
            std::cin >> key;
            switch (key) {
            case 1:
                std::cout << "Телепортация прошла успешна";
                flag = true;
            case 3:
                std::cout << "Телепортация прошла успешна";
                flag = true;
            case 2:
                std::cout << "Телепортация прошла успешна";
                flag = true;
            }
        }
        clear();
    }


    void Dialog_s_merom() {
        std::cout << R"(```
     .--.
    |o_o |
    |:_/ |
   //   \ \
  (|     | )
 /'\_   _/`\
 \___)=(___/
```)";
        std::cout << "\nМер: Я мер.....\n"; // Исправлен синтаксис новой строки
        std::cout << "ВЫ: ....\n";
        clear(); // Вызов метода очистки
        std::cout << "Увидев в каком состоянии мер, вы ушли обратно.\n";
        clear(); // Очистить консоль снова
    }

class Chunks {
protected:
    int chX, chY;
    int oldChX, oldChY;
public:
    Chunks(int chX = 0, int chY = 0, int oldChX = 0, int oldChY = 0) : chX(chX), chY(chY), oldChX(oldChX), oldChY(oldChY) {}
};



class NPC {
protected:
    pair<int, int> npc;
public:
    NPC() {
        npc = {};
    }

};

class Decorations {
protected:
    vector<pair<int, int>> korobochka;
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
        korobochka = {};
        seed = 0;
    }
    // ne skip
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
        case 3:
            for (auto i : korobochka) {
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
        case 3:
            korobochka.push_back({ rngX + x * 7, rngY + y * 5 });
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
public:
    Obstacles() {
        //отрисовка стен xy
        obstC = { {5,35},{4,35},{3,35},{2,35},{1,35},{0,35},{5,36},{5,37},{5,38},{5,39},{5,40},{5,41},{5,42},{5,43},{5,44},{5,45},{5,46},{5,47},{5,48},{5,49},{5,50},
            {5,55},{4,50},{3,50},{2,50},{1,50},{1,51},{1,52},{1,53},{1,54},{1,55},{2,55},{3,55},{4,55},{19,50},{20,50},{21,50},{22,50},{23,50},{24,50},{19,54},{20,54},{21,54},{22,54},{23,54},{24,54}, { 5,56 },{5,57},{5,58},{5,59},{5,60},{5,61},{5,62},{5,63},{5,64},{5,65},{5,66},{5,67},{5,68},{5,69},{4,69},{3,69},{2,69},{1,69},{0,69},
            //рестик                                                                   -
            {24,35},{24,36},{24,37},{24,38},{23,38},{22,38},{21,38},{20,38},{19,38},{18,39},{18,40},{18,41},{18,42},{18,43},{18,44},{18,45},{18,46},{18,47},{18,48},{18,49},{18,50},
            {18,54},{18,55},{18,56},{18,57},{18,58},{18,59},{18,60},{18,61},{18,62},{18,63},{18,64},{18,65},{19,66},{20,66},{21,66},{22,66},{23,66},{23,66},{24,66},{24,67},{24,68},{24,69},
            //стены рестика
        {25,35},{25,36},{25,37},{25,38},{25,39},{25,40},{25,41},{25,42},{25,43},{25,44},{25,45},{25,46},{25,47},{25,48},{25,49},{25,50},{25,54},{25,55},{25,56},{25,57},{25,58},{25,59},{25,60},{25,61},{25,62},{25,63},{25,64},{25,65},{25,66},{25,67},{25,68},{25,69},
            {26,35},{27,35},{28,35},{29,35},{30,35},{31,35},{32,35},{33,35},{34,35},{38,35},{39,35},{40,35},{41,35},{42,35},{43,35},{44,35},{45,35},{46,35},{47,35},{48,35},{49,35},{49,35},
            {49,36},{49,37},{49,38},{49,39},{49,40},{49,41},{49,42},{49,43},{49,44},{49,45},{49,46},{49,47},{49,48},{49,49},{49,50},{49,51},{49,52},{49,53},{49,54},{49,55},{49,56},{49,57},{49,58},{49,59},{49,60},{49,61},{49,62},{49,63},{49,64},{49,65},{49,66},{49,67},{49,68},{49,69},
            {26,69},{27,69},{28,69},{29,69},{30,69},{31,69},{32,69},{33,69},{34,69},{35,69},{36,69},{37,69},{38,69},{39,69},{40,69},{41,69},{42,69},{43,69},{44,69},{45,69},{46,69},{47,69},{48,69},{49,69},{49,69},
            {26,63},{27,63},{28,63},{29,63},{30,63},{31,63},{32,63},{33,63},{34,63},{35,63},{36,63},{37,63},{38,63},{39,63},{40,63},{41,63},{42,63},{43,63},{44,63},{45,63},{46,63},{47,63},{48,63},{49,63}
        };
    }
    bool isObstacle(int x, int y) const {
        for (auto i : obstC) {
            if (i.first == y && i.second == x) {
                return true;
            }
        }
        return false;
    }
};
class Map : public Player, public Chunks, public Obstacles, public Decorations {
    vector<Chunks> chunks;
public:
    void printMap() {
        clear();
        for (int y = chY * 25; y < 25 + (chY * 25); ++y) {
            for (int x = chX * 35; x < 35 + (chX * 35); ++x) {
                // человечек
                if (x == this->x && y == this->y) {
                    cout << "вы";
                }
                else if (isObstacle(x, y)) {
                    cout << "##";
                }
                // верхний левый чанек x<35 y<25                else if ((x > 3 && y > 2) && (x < 5 && y < 4)) { cout << "  "; }
                else if ((x >= 5 && y >= 4) && (x <= 5 && y <= 4)) { cout << " |"; }
                else if ((x >= 3 && y >= 2) && (x <= 3 && y <= 2)) { cout << " |"; }
                else if ((x >= 3 && y >= 2) && (x <= 5 && y <= 4)) { cout << "__"; }                // else if ((x >= 50 && y >= 24 ) && (x <= 57 && y <= 16)) { cout << "[]"; }
                //нижний левый чанк                // else if ((x >= 3 && y >= 30 ) && (x <= 5 && y <= 35)) { cout << "[]"; }
                // верхний правый чанк                else if ((x >= 40 && y >= 20) && (x <= 40 && y <= 23)) { cout << "| "; }
                else if ((x >= 50 && y >= 17) && (x <= 50 && y <= 17)) { cout << "[]"; }
                else if ((x >= 43 && y >= 23) && (x <= 44 && y <= 23)) { cout << "__"; }
                else if ((x >= 46 && y >= 20) && (x <= 46 && y <= 23)) { cout << "| "; }
                else if ((x >= 46 && y >= 19) && (x <= 47 && y <= 19)) { cout << "__"; }//C                else if ((x >= 46 && y >= 23) && (x <= 47 && y <= 23)) { cout << "__"; }
                else if ((x >= 50 && y >= 20) && (x <= 50 && y <= 23)) { cout << "| "; }//T
                else if ((x >= 50 && y >= 23) && (x <= 51 && y <= 23)) { cout << "__"; }
                else if ((x >= 53 && y >= 20) && (x <= 53 && y <= 23)) { cout << "| "; }
                else if ((x >= 53 && y >= 23) && (x <= 54 && y <= 23)) { cout << "__"; }
                else if ((x >= 55 && y >= 20) && (x <= 55 && y <= 23)) { cout << "| "; }
                else if ((x >= 56 && y >= 20) && (x <= 56 && y <= 23)) { cout << "| "; }
                else if ((x >= 59 && y >= 20) && (x <= 59 && y <= 23)) { cout << "| "; }//
                else if ((x >= 56 && y >= 23) && (x <= 58 && y <= 23)) { cout << "__"; }
                else if ((x >= 56 && y >= 19) && (x <= 58 && y <= 19)) { cout << "__"; }//P                         1 ВТОРОЙ ЧАНК ПРОПИСАН ЕЕЕЕЕЕ                else if ((x >= 58 && y >= 20) && (x <= 58 && y <= 21)) { cout << "| "; }
                else if ((x >= 55 && y >= 21) && (x <= 58 && y <= 21)) { cout << "__"; }
                else if ((x >= 46 && y >= 23) && (x <= 47 && y <= 23)) { cout << "__"; }
                else if ((x >= 54 && y >= 23) && (x <= 55 && y <= 23)) { cout << "__"; }//H                else if ((x >= 64 && y >= 20) && (x <= 64 && y <= 23)) { cout << "|  "; }
                else if ((x >= 52 && y >= 3) && (x <= 52 && y <= 3)) { cout << "mr"; }
                else if ((x >= 65 && y >= 27) && (x <= 65 && y <= 27)) { cout << "PAB"; }
                else if ((x >= 42 && y >= 31) && (x <= 59 && y <= 41)) { cout << "_|"; }
                else if ((x >= 42 && y >= 30) && (x <= 59 && y <= 30)) { cout << "_ "; }
                //4 чанк
                // Дерево
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
                // Трава
                else if (isDecoration(x - chX * 35, y - chY * 25, 1)) { cout << ".,"; }
                else if (isDecoration(x - 1 - chX * 35, y - chY * 25, 1)) { cout << "\"\""; }
                else if (isDecoration(x - 2 - chX * 35, y - chY * 25, 1)) { cout << ",."; }
                // Пустое 
                else {
                    cout << ". ";
                }
                if (x == 50 and y == 17) {
                    
                   
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
        
        
        Player p;
        Fight f{ &p };
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
            if (rand() % 5 == 0) { f.fight(); }
        }
    }

};
    


void game() {
    Map map;
    map.initMap();
}