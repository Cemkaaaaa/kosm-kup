#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <sstream> 
#include "player.h"
#include "fight.h"
#include "ansiUtils.h"
using namespace ansi;
using namespace std;




class Chunks1 {
protected:
    int chX, chY;
    int oldChX, oldChY;
public:
    Chunks1(int chX = 0, int chY = 0, int oldChX = 0, int oldChY = 0) : chX(chX), chY(chY), oldChX(oldChX), oldChY(oldChY) {}
};

class NPC {
protected:
    pair<int, int> npc;
public:
    NPC(int x, int y) {
        npc = { x, y };
    }
    pair<int, int> getNPC() {
        return npc;
    }
    bool isNpcAround(int x, int y) {
        if ((x >= npc.first - 1 && x <= npc.first + 1) && (y >= npc.second - 1 && y <= npc.second + 1)) {
            return true;
        }
        else {
            return false;
        }
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
    // skip
    void fillChunk() {
        for (int y = 0; y < 7; y++) {
            for (int x = 0; x < 5; x++) {
                addRandomDeco(x, y, 1);
                int chance = rand() % 10;
                if (chance <= 1) {
                    addRandomDeco(x, y, 2);
                    addRandomDeco(x, y, 3);
                }
            }
        }
    }
    // skip
    void addSeedToChs(int seed, int x, int y) {
        decoratedChunks.push_back({ seed, {x, y} });
    }
    // skip
    int getSeed(int x, int y) {
        for (auto i : decoratedChunks) {
            if (i.second.first == x && i.second.second == y) {
                return i.first;
            }
        }
        return 0;
    }
    // skip
    void print() {
        for (auto i : decoratedChunks) {
            cout << i.first << " " << i.second.first << " " << i.second.second << endl;
        }
    }
    void clearChunk() {
        decoC1 = {};
        decoC2 = {};
        korobochka = {};
    }
};

class Obstacles {
    vector<pair<int, int>> obstC;
    vector<pair<pair<int, int>, pair<int, int>>> largeObstC;
    vector<pair<int, int>> deleteObstC;
    vector<pair<pair<int, int>, pair<int, int>>> deleteLargeObstC;
public:
    Obstacles() {
        largeObstC = { {{1,1}, {12,7}}, {{22,1}, {47,7}} }; // коорды для больших препятствий
        deleteLargeObstC = { {{2,2},{11,6}}, {{23,2}, {46,6}} }; // удалять большие коорды препятствий
        obstC = {}; // коорды для точечных препятствий
        deleteObstC = { {12,4},{12,5},{12,3},{22,3},{22,4},{22,5},{47,3},{47,4},{47,5} }; // удалять точечно препятствия
        for (auto i : largeObstC) {
            for (int j = i.first.first; j <= i.second.first; ++j) {
                for (int k = i.first.second; k <= i.second.second; ++k) {
                    obstC.push_back({ j,k });
                }
            }
        }
        deleteObstacles();
    }

    bool isObstacle(int x, int y) const {
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

            // Пройдем по всем точкам в obstC и удалим те, которые лежат в диапазоне
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
};
class MapEarth : public Player, public Chunks1, public Obstacles, public Decorations {
    vector<NPC> npc;
public:
    MapEarth() {
        npc.push_back(NPC(12, 1));
    }
    void movePlayer(int dx, int dy) {
        int newX = x + dx;
        int newY = y + dy;
        oldChX = chX;
        oldChY = chY;
        if (isObstacle(newX, newY) == false) {
            x = newX;
            y = newY;
            if (x < 0) {
                chX = x / 35 - 1;
            }
            else {
                chX = x / 35;
            }
            if (y < 0) {
                chY = y / 25 - 1;
            }
            else {
                chY = y / 25;
            }
        }
    }
    void tick() {
        static bool showMessage = false;
        if (oldChY != chY || oldChX != chX) {
            clearChunk();
            bool check = false;
            for (auto i : nullChunks) {
                if (chX == i.first && chY == i.second) {
                    check = true;
                }
            }
            if (!check) {
                seed = getSeed(chX, chY);
                if (seed == 0) {
                    seed = rand();
                    addSeedToChs(seed, chX, chY);
                }
                srand(seed);
                fillChunk();
            }
            //Fight::fight();
        }
        showMessage = false;
        for (auto& i : npc) {
            if (i.isNpcAround(x, y)) {
                showMessage = true;
                break;
            }
        }
        if (showMessage) {
            cout << "Я ИГРАЛ В ЭТИИ ИГРЫ РАНЬШЕ!!!!" << endl;
        }
    }

    void initMap() {
        Player p;
        Fight f{ &p };
        int n = 3;
        while (true) {
            int temp = 0; 
            tick();
            if (getSeed(chX, chY) != 0) { seed = getSeed(chX, chY); }
            srand(seed);
            clear();
            if ((x >= 1 && x <= 11) && (y >= 44 && y >= 46)) {
                //функция для перехода
            }
            printMap();
            cout << seed << "\n";
            cout << x << ", " << y << "\n";
            char input = _getch();
            switch (input) {
            case 'd':
                movePlayer(1 * n, 0);
                break;
            case 's':
                movePlayer(0, 1 * n);
                break;
            case 'a':
                movePlayer(-1 * n, 0);
                break;
            case 'w':
                movePlayer(0, -1 * n);
                break;
            }
            if (rand() % x + temp == 0 && rand() % y + temp == 0) { clear(); f.fight(); temp++; }
        }
    }
    string getTile(int x, int y) {
        // человечек
        if (x == this->x && y == this->y) { return "><"; }
        // крыши для домиков
        else if (((x > 22 && x < 47) && (y > 1 && y < 7)) && !((this->x >= 22 && this->x <= 47) && (this->y >= 2 && this->y <= 6))) { return "\033[48;5;239m  \033[0m"; }
        else if (((x > 1 && x < 12) && (y > 1 && y < 7)) && !((this->x >= 2 && this->x <= 12) && (this->y >= 2 && this->y <= 6))) { return "\033[48;5;239m  \033[0m"; }
        else if (((x >= 22 && x <= 47) && (y >= 1 && y <= 7)) && !((this->x >= 22 && this->x <= 47) && (this->y >= 2 && this->y <= 6))) { return "\033[48;5;7m  \033[0m"; }
        else if (((x >= 1 && x <= 12) && (y >= 1 && y <= 7)) && !((this->x >= 2 && this->x <= 12) && (this->y >= 2 && this->y <= 6))) { return "\033[48;5;7m  \033[0m"; }
        // Интерьер домиков
        else if ((x == 2) && (y == 2)) { return "\033[48;5;9m()\033[0m"; }
        else if ((x >= 2 && x <= 4) && (y == 2)) { return "\033[48;5;9m  \033[0m"; }
        // Препятствия
        else if (isObstacle(x, y)) { return "  "; }
        // Полы
        else if ((x >= 1 && x <= 12) && (y >= 1 && y <= 7)) { return "\033[48;5;130m  \033[0m"; }
        else if ((x >= 1 && x <= 13) && (y >= 3 && y <= 5)) { return "\033[48;5;130m  \033[0m"; }
        else if ((x >= 22 && x <= 47) && (y >= 1 && y <= 7)) { return "\033[48;5;130m  \033[0m"; }
        else if ((x >= 21 && x <= 48) && (y >= 3 && y <= 5)) { return "\033[48;5;130m  \033[0m"; }
        // надпись
        else if (x == 4 && y == 8) { return "\033[48;5;41m\033[38;5;232mТв\033[0m"; }
        else if (x == 5 && y == 8) { return "\033[48;5;41m\033[38;5;232mой\033[0m"; }
        else if (x == 6 && y == 8) { return "\033[48;5;41m\033[38;5;232m д\033[0m"; }
        else if (x == 7 && y == 8) { return "\033[48;5;41m\033[38;5;232mом\033[0m"; }
        else if (x == 8 && y == 8) { return "\033[48;5;41m\033[38;5;232mик\033[0m"; }
        else if (x == 22 && y == 17) { return "\033[48;5;41m\033[38;5;232mVe\033[0m"; }
        else if (x == 23 && y == 17) { return "\033[48;5;41m\033[38;5;232mno\033[0m"; }
        else if (x == 24 && y == 17) { return "\033[48;5;41m\033[38;5;232mm \033[0m"; }
        else if (x == 25 && y == 17) { return "\033[48;5;41m\033[38;5;232mбр\033[0m"; }
        else if (x == 26 && y == 17) { return "\033[48;5;41m\033[38;5;232mат\033[0m"; }
        else if (x == 36 && y == 17) { return "\033[48;5;41m\033[38;5;232mЯ \033[0m"; }
        else if (x == 37 && y == 17) { return "\033[48;5;41m\033[38;5;232mхз\033[0m"; }
        else if (x == 38 && y == 17) { return "\033[48;5;41m\033[38;5;232m ч\033[0m"; }
        else if (x == 39 && y == 17) { return "\033[48;5;41m\033[38;5;232mто\033[0m"; }
        else if (x == 40 && y == 17) { return "\033[48;5;41m\033[38;5;232m п\033[0m"; }
        else if (x == 41 && y == 17) { return "\033[48;5;41m\033[38;5;232mис\033[0m"; }
        else if (x == 42 && y == 17) { return "\033[48;5;41m\033[38;5;232mат\033[0m"; }
        else if (x == 43 && y == 17) { return "\033[48;5;41m\033[38;5;232mь \033[0m"; }
        else if (x == 60 && y == 16) { return "\033[48;5;41m\033[38;5;232mТу\033[0m"; }
        else if (x == 61 && y == 16) { return "\033[48;5;41m\033[38;5;232mт \033[0m"; }
        else if (x == 62 && y == 16) { return "\033[48;5;41m\033[38;5;232mБа\033[0m"; }
        else if (x == 63 && y == 16) { return "\033[48;5;41m\033[38;5;232mси\033[0m"; }
        else if (x == 64 && y == 16) { return "\033[48;5;41m\033[38;5;232mк \033[0m"; }
        // Самлёт
        else if ((x == 0) && (y == 44)) { return "\033[38;5;9m\033[48;5;238m~~\033[0m"; }
        else if ((x == 0) && (y == 45)) { return "\033[38;5;9m\033[48;5;238m~~\033[0m"; }
        else if ((x == 0) && (y == 46)) { return "\033[38;5;9m\033[48;5;238m~~\033[0m"; }
        else if ((x == 11) && (y == 44)) { return "\033[48;5;14m\033[38;5;15m\\\\\033[0m"; }
        else if ((x == 11) && (y == 45)) { return "\033[48;5;14m\033[38;5;15m||\033[0m"; }
        else if ((x == 11) && (y == 46)) { return "\033[48;5;14m\033[38;5;15m//\033[0m"; }
        else if ((x == 7) && (y >= 43 && y <= 47)) { return "\033[48;5;15m  \033[0m"; }
        else if ((x == 6) && (y >= 42 && y <= 48)) { return "\033[48;5;15m  \033[0m"; }
        else if ((x >= 1 && x <= 11) && (y >= 44 && y <= 46)) { return "\033[48;5;15m  \033[0m"; }
        else if (x == 12 && y == 45) { return "\033[48;5;15m  \033[0m"; }
        // Платформы
        else if ((x > 0 && x < 13) && (y > 41 && y < 49)) { return "\033[48;5;248m  \033[0m"; }
        else if ((x >= 0 && x <= 13) && (y >= 41 && y <= 49)) { return "\033[48;5;238m  \033[0m"; }
        // басик
        else if ((x > 1 && x < 12) && (y > 17 && y < 32) && y % 2 == 0) { return "\033[48;5;33m\033[38;5;14m ~\033[0m"; }
        else if ((x > 1 && x < 12) && (y > 17 && y < 32)) { return "\033[48;5;33m\033[38;5;14m~ \033[0m"; }
        else if ((x >= 1 && x <= 12) && (y >= 17 && y <= 32)) { return "\033[48;5;7m  \033[0m"; }
        else if ((x > 57 && x < 68) && (y > 17 && y < 32) && y % 2 == 0) { return "\033[48;5;33m\033[38;5;14m ~\033[0m"; }
        else if ((x > 57 && x < 68) && (y > 17 && y < 32)) { return "\033[48;5;33m\033[38;5;14m~ \033[0m"; }
        else if ((x >= 57 && x <= 68) && (y >= 17 && y <= 32)) { return "\033[48;5;7m  \033[0m"; }
        // нана нанана дороги
        else if ((x > 15 && x < 19) && (y >= -1 && y <= 50)) { return "\033[48;5;241m  \033[0m"; }
        else if ((x > 15 + 35 && x < 19 + 35) && (y >= -1 && y <= 50)) { return "\033[48;5;241m  \033[0m"; }
        else if ((x >= -1 && x <= 70) && (y > 10 && y < 14)) { return "\033[48;5;241m  \033[0m"; }
        else if ((x >= -1 && x <= 70) && (y > 10 + 25 && y < 14 + 25)) { return "\033[48;5;241m  \033[0m"; }
        else if ((x >= 15 && x <= 19) && (y >= 0 && y <= 49)) { return "\033[48;5;237m[]\033[0m"; }
        else if ((x >= 15 + 35 && x <= 19 + 35) && (y >= 0 && y <= 49)) { return "\033[48;5;237m[]\033[0m"; }
        else if ((x >= 0 && x <= 69) && (y >= 10 && y <= 14)) { return "\033[48;5;237m[]\033[0m"; }
        else if ((x >= 0 && x <= 69) && (y >= 10 + 25 && y <= 14 + 25)) { return "\033[48;5;237m[]\033[0m"; }
        // кустики красиви
        else if ((x >= 14 + 35 && x <= 20 + 35) && (y >= 0 && y <= 49)) { return "\033[48;5;41m\033[38;5;2m88\033[0m"; }
        else if ((x >= 14 && x <= 20) && (y >= 0 && y <= 49)) { return "\033[48;5;41m\033[38;5;2m88\033[0m"; }
        else if ((x >= 0 && x <= 69) && (y >= 9 && y <= 15)) { return "\033[48;5;41m\033[38;5;2m88\033[0m"; }
        else if ((x >= 0 && x <= 69) && (y >= 9 + 25 && y <= 15 + 25)) { return "\033[48;5;41m\033[38;5;2m88\033[0m"; }
        // Грани карты
        else if ((x > -1 && x < 70) && (y > -1 && y < 50)) { return "\033[48;5;41m  \033[0m"; }
        else if ((x >= -1 && x <= 70) && (y >= -1 && y <= 50)) { return "\033[48;5;237m##\033[0m"; }
        // Дерево
        else if (isDecoration(x - chX * 35, y - chY * 25, 2)) { return "\033[48;5;2m/#\033[0m"; }
        else if (isDecoration(x - 1 - chX * 35, y - chY * 25, 2)) { return "\033[48;5;2m&#\033[0m"; }
        else if (isDecoration(x - 2 - chX * 35, y - chY * 25, 2)) { return "\033[48;5;2m#\\\033[0m"; }
        else if (isDecoration(x - chX * 35, y - 1 - chY * 25, 2)) { return "\033[48;5;2m#&\033[0m"; }
        else if (isDecoration(x - 1 - chX * 35, y - 1 - chY * 25, 2)) { return "\033[48;5;2m##\033[0m"; }
        else if (isDecoration(x - 2 - chX * 35, y - 1 - chY * 25, 2)) { return "\033[48;5;2m&#\033[0m"; }
        else if (isDecoration(x - chX * 35, y - 2 - chY * 25, 2)) { return "\033[48;5;2m\\#\033[0m"; }
        else if (isDecoration(x - 1 - chX * 35, y - 2 - chY * 25, 2)) { return "\033[48;5;2m#&\033[0m"; }
        else if (isDecoration(x - 2 - chX * 35, y - 2 - chY * 25, 2)) { return "\033[48;5;2m#/\033[0m"; }
        else if (isDecoration(x - 1 - chX * 35, y - 3 - chY * 25, 2)) { return "\033[48;5;41m\033[38;5;130m||\033[0m"; }
        else if (isDecoration(x - 1 - chX * 35, y - 4 - chY * 25, 2)) { return "\033[48;5;41m\033[38;5;130m||\033[0m"; }
        // МАК
        else if (isDecoration(x - chX * 35, y - chY * 25, 1)) { return "\033[1m\033[48;5;41m\033[38;5;9m@ \033[0m"; }
        else if (isDecoration(x - chX * 35, y - 1 - chY * 25, 1)) { return "\033[1m\033[48;5;41m\033[38;5;22m| \033[0m"; }
        // Трава
        else if (isDecoration(x - chX * 35, y - chY * 25, 1)) { return "\033[48;5;41m\033[38;5;22m.,\033[0m"; }
        else if (isDecoration(x - 1 - chX * 35, y - chY * 25, 1)) { return "\033[48;5;41m\033[38;5;22m\"\"\033[0m"; }
        else if (isDecoration(x - 2 - chX * 35, y - chY * 25, 1)) { return "\033[48;5;41m\033[38;5;22m,.\033[0m"; }
        // Пустое
        else {
            return "\033[48;5;41m  \033[0m";
        }
    }

    void printMap() {
        stringstream buffer;

        for (int y = chY * 25; y < 25 + (chY * 25); ++y) {
            for (int x = chX * 35; x < 35 + (chX * 35); ++x) {
                buffer << getTile(x, y);
            }
            buffer << endl;
        }
        cout << buffer.str();
    }

};

