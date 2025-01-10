#include "ansiUtils.h"
//Позиция Курсора
string ansi::getCursorPos()
{
    cout << "\033[6n";
    string pos;
    char get = ' ';
    while (true) {
        get = _getch();
        if (get == 'R') { break; }
        if (get == ';') { pos += get; }
        try {

            if (isalnum(get)) { pos += get; }

        }
        catch (...) {
            continue;
        }
    }
    return pos;
}
//Очистка экрана
void ansi::clear()
{
    system("\033[2j\033[0;0f    ");
}
//Установка цвета Символа (Код UNIX)
void ansi::setFGColor(int code) {
    cout << "\033[38;5;" << code << "m";
}
//Установка цвета Символа (RGB)
void ansi::setFGColor(int red, int green, int blue) {
    cout << "\033[38;2;" << red << ";" << green << ";" << blue << ";" << "m";
}
//Установка Заднего фона  (Код UNIX)
void ansi::setBGColor(int code) {
    cout << "\033[48;5;" << code << "m";
}
//Установка Заднего фона (RGB)
void ansi::setBGColor(int red, int green, int blue) {
    cout << "\033[48;2;" << red << ";" << green << ";" << blue << ";" << "m";
}

