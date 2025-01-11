#pragma once

#include <conio.h>
#include <iostream>
using namespace std;
namespace ansi {
    //Позиция Курсора
    string getCursorPos(); 
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
    //Установка текста в заданной позиции со сжатием
    void putText(int x, int y, int left_edge, int right_edge, string text);
} // Namespace ansi
