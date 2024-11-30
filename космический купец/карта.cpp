#include <iostream>
#include <vector>
using namespace std;
class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
};
//Map::movePoint(int dx, int dy){реализация}.cpp
//class Map{void movePoint(int dx, int dy)}
class Map {
protected:
    int width, height;
    Point point;
    std::vector<std::vector<bool>> obstacles;

public:
    Map(int w = 35, int h = 25) : width(w), height(h), point(0, 0) {
        obstacles.resize(height, std::vector<bool>(width, false));
    }

    virtual ~Map() {}

    void movePoint(int dx, int dy) {
        int newX = point.x + dx;
        int newY = point.y + dy;

        if (newX >= 0 && newX < width && newY >= 0 && newY < height && !obstacles[newY][newX]) {
            point.x = newX;
            point.y = newY;
        }
    }

    void addObstacle(int x, int y) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            obstacles[y][x] = true;
        }
    }

    void printMap() {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x == point.x && y == point.y) {
                    std::cout << "P ";
                }
                else if (obstacles[y][x]) {
                    std::cout << "# ";
                }
                else {
                    std::cout << ". ";
                }
            }
            std::cout << std::endl;
        }
    }
};
// 
class CustomMap : public Map {
public:
    CustomMap(int w, int h) : Map(w, h) {}
};