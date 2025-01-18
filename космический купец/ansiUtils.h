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
    //Позиция Курсора
    COORD getCursorPos(); 
    //Очистка Экрана
    void clear();
    //Установка цвета Символа (Код UNIX)
    void setFGColor(int code);
    //Установка цвета Символа (RGB)
    void setFGColor(int red, int green, int blue);
    //Установка Заднего фона  (Код UNIX)
    void setBGColor(int code);
    //Установка Заднего фона (RGB)
    void setBGColor(int red, int green, int blue);
    void putText(COORD left_edge, int right_edge, string text);
    //Установка текста в заданной позиции со сжатием
} // Namespace ansi
