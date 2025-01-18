#include "ansiUtils.h"
#include <iostream>
#include <string>
//Позиция Курсора

ansi::COORD ansi::getCursorPos()
{

    cout << "\033[6n";
    string pos;
    COORD poss;
    char get = ' ';
    bool flag = false;
    while (get != 'R') {
        get = _getch();
        
        if (get == ';')
        {
            poss.y = stoi(pos);
            flag = true; 
            pos.clear();
        }
        if (flag) {
            try {

                if (isalnum(get)) { pos += get; }

            }
            catch (...) {
                continue;
            }
        }
        else {
            try {

                if (isalnum(get)) { pos += get; }

            }
            catch (...) {
                continue;
            }
        }
        
    }
    poss.x = stoi(pos);
    return poss;
}
//Очистка экрана
void ansi::clear()
{
    system("cls");
}
//Установка цвета Символа (Код UNIX)
void ansi::setFGColor(int code)
{
    cout << "\033[38;5;" << code << "m";
}
//Установка цвета Символа (RGB)
void ansi::setFGColor(int red, int green, int blue)
{
    cout << "\033[38;2;" << red << ";" << green << ";" << blue << ";" << "m";
}
//Установка Заднего фона  (Код UNIX)
void ansi::setBGColor(int code) {
    cout << "\033[48;5;" << code << "m";
}
//Установка Заднего фона (RGB)
void ansi::setBGColor(int red, int green, int blue)
{
    cout << "\033[48;2;" << red << ";" << green << ";" << blue << ";" << "m";
}
//Установка текста в заданной позиции со сжатием

void ansi::putText(COORD left_edge = ansi::getCursorPos(), int right_edge = 0, string text = "")
{
    string buffer;
    
    int column = 0;
    
    for (int i = 0; i < text.size(); i++) {
        if (i % right_edge == 0) {
            column++;
            buffer += ("\033[" + to_string(left_edge.y+column) + ";" + to_string(left_edge.x) + "f");
        }
        else if (text[i] == '\\' && text[i + 1] == 'n') {
            column++;
            buffer += ("\033[" + to_string(left_edge.y + column) + ";" + to_string(left_edge.x) + "f");
        }
        else {
            buffer += text[i];
        }
    }
    cout << buffer;
}
int main() {

    ansi::putText(ansi::COORD(4,1), 20, "12312323\n22222");
    return 0;
}