#pragma once

#include <conio.h>
#include <iostream>
using namespace std;
namespace ansi {
    //������� �������
    string getCursorPos(); 
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
} // Namespace ansi
