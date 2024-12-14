#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <map>
using namespace std;

void clear()
{
    system("cls");
}

class Chunks {
protected:
    int chX, chY;
public:
    Chunks(int chX = 0, int chY = 0) : chX(chX), chY(chY) {}
};

class Player {
protected:
    int x, y;
public:
    Player(int x = 0, int y = 0) : x(x), y(y) {}
};

class Decorations {
    vector<pair<int, int>> decoC1;
public:
    Decorations() {
        decoC1 = {  };
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
        }
        return false;
    }
    void addRandomDeco() {
        srand(time(NULL));
        int rngY = rand() % 35;
        int rngX = rand() % 25;
        decoC1.push_back({ rngX,rngY });
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
//Кинь генереацию автоматическую
class Map : public Player, public Chunks, public Obstacles, public Decorations {
public:
    void printMap() {
        clear();
        for (int y = chY * 25; y < 25 + (chY * 25); ++y) {
            for (int x = chX * 35; x < 35 + (chX * 35); ++x) {
                if (x == this->x && y == this->y) {
                    cout << "[]";
                }
                else if (isObstacle(x, y)) {
                    cout << "##";
                }
                else if (isDecoration(x, y, 1)) {
                    cout << "#!";
                }
                else if (isDecoration(x - 1, y, 1)) {
                    cout << "11";
                }
                else if (isDecoration(x - 2, y, 1)) {
                    cout << "!#";
                }
                else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    }

    void movePlayer(int dx, int dy) {
        int newX = x + dx;
        int newY = y + dy;

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

    void initMap() {
        addRandomDeco();
        while (true) {
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

/*int main()
{
    Map map;
    map.initMap();
}*/