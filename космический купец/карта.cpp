#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
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

class Player {
protected:
    int x, y;
public:
    Player(int x = 0, int y = 1) : x(x), y(y) {}
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
    // skip
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
        largeObstC = { {{4,3}, {12,15}} }; // коорды для больших препятствий
        deleteLargeObstC = { {} }; // удалять большие коорды препятствий
        //ТУТ МНЕ НАДО СДЕЛДЛАТЬ КОД ДЛЯ УДАЛЕНИЯ КООРДИНАТ ДАААААААААААААААААА
        obstC = {}; // коорды для точечных препятствий
        deleteObstC = {}; // удалять точечно препятсвтия
    }
    bool isObstacle(int x, int y) const {
        for (auto i : obstC) {
            if (i.first == x && i.second == y) {
                return true;
            }
        }
        return false;
    }
    void printObst() {
        for (auto i : obstC) {
            cout << i.first << ", " << i.second << "\n";
        }
    }
};
class Map : public Player, public Chunks, public Obstacles, public Decorations {
    vector<Chunks> chunks;
public:
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
        }
    }

    void initMap() {
        while (true) {
            tick();
            if (getSeed(chX, chY) != 0) {
                seed = getSeed(chX, chY);
            }
            srand(seed);
            printMap();
            cout << seed << "\n";
            cout << x << ", " << y;
            char input = _getch();
            switch (input) {
            case 'd':
                movePlayer(1, 0);
                break;
            case 's':
                movePlayer(0, 1);
                break;
            case 'a':
                movePlayer(-1, 0);
                break;
            case 'w':
                movePlayer(0, -1);
                break;
            }
        }
    }
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
                // Препятствие
                else if (isObstacle(x, y)) {
                    cout << "##";
                }
                // korobochka
                else if (isDecoration(x - chX * 35, y - chY * 25, 3)) { cout << "88"; }
                else if (isDecoration(x - 1 - chX * 35, y - chY * 25, 3)) { cout << "88"; }
                else if (isDecoration(x - chX * 35, y - 1 - chY * 25, 3)) { cout << "88"; }
                else if (isDecoration(x - 1 - chX * 35, y - 1 - chY * 25, 3)) { cout << "88"; }
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
                // venom
                else if ((x > 5 && x < 10) && (y > 5 && y < 10)) { cout << "  "; }
                else if ((x >= 5 && x <= 10) && (y >= 5 && y <= 10)) { cout << "[]"; }
                // Трава
                else if (isDecoration(x - chX * 35, y - chY * 25, 1)) { cout << ".,"; }
                else if (isDecoration(x - 1 - chX * 35, y - chY * 25, 1)) { cout << "\"\""; }
                else if (isDecoration(x - 2 - chX * 35, y - chY * 25, 1)) { cout << ",."; }
                // Пустое 
                else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Map map;
    map.initMap();
}