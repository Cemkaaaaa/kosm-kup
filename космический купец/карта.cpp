#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "player.h"
#include "карта.h"
using namespace std;

void clear()
{
    system("cls");
}

class Chunks {
protected:
    int chX, chY;
    int oldChX, oldChY;
public:
    Chunks(int chX = 0, int chY = 0, int oldChX = 0, int oldChY = 0) : chX(chX), chY(chY), oldChX(oldChX), oldChY(oldChY) {}
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
        seed = 0;
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
                if (chance <= 1) {
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
        obstC = { {1,1},{1,3},{2,1},{3,1},{3,2},{3,3},{2,3} };
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
                    cout << "[]";
                }
                else if (x == this->x && y - 1 == this->y) {
                    cout << "TT";
                }
                else if (x == this->x && y + 1 == this->y) {
                    cout << "()";
                }
                else if (isObstacle(x, y)) {
                    cout << "##";
                }
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
            }
            cout << endl;
        }
        cout << getSeed(chX, chY) << " " << chX << ", " << chY << "\n";
        print();
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
            srand(seed);
            tick();
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
/*
int main()
{
    Map map;
    map.initMap();
}
*/