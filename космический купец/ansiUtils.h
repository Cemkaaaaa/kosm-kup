#pragma once
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

namespace ansi {
    struct COORD {
        int x, y;
        COORD() : x{ 0 }, y{ 0 } {}
        COORD(int x, int y) : x{ x }, y{ y } {}

    };
    //������� �������
    COORD getCursorPos(); 
    //������� ������
    void clear();
    //��������� ����� ������� (��� UNIX)
    void setFGColor(int code);
    //��������� ����� ������� (RGB)
    void setFGColor(int red, int green, int blue);
    //��������� ������� ����  (��� UNIX)
    void setBGColor(int code);
    //��������� ������� ���� (RGB)
    void setBGColor(int red, int green, int blue);
    void putText(COORD left_edge, int right_edge, string text);
    //��������� ������ � �������� ������� �� �������
} // Namespace ansi
