#include "ansiUtils.h"
#include <string>
//������� �������
struct COORD {
    int x, y;
    COORD(int x, int y) : x{ x }, y{ y } {};
    COORD(string cords) {
        bool flag = true;
        string buffer;
        for (auto i : cords) {
            if (flag) {
                if (i == ';') {
                    x = stoi(buffer);
                    buffer.clear();
                    flag = false;
                }
                else {
                    buffer += i;
                }
            }
            else {
                if(i == 'R') {
                    y = stoi(buffer);
                    buffer.clear();
                    break;
                }
                else {
                    buffer += i;
                }

            }
        }
    }
};
string ansi::getCursorPos()
{
    cout << "\033[6n";
    string pos;
    char get = ' ';
    while (get != 'R') {
        get = _getch();
        
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
//������� ������
void ansi::clear()
{
    system("cls");
}
//��������� ����� ������� (��� UNIX)
void ansi::setFGColor(int code)
{
    cout << "\033[38;5;" << code << "m";
}
//��������� ����� ������� (RGB)
void ansi::setFGColor(int red, int green, int blue)
{
    cout << "\033[38;2;" << red << ";" << green << ";" << blue << ";" << "m";
}
//��������� ������� ����  (��� UNIX)
void ansi::setBGColor(int code) {
    cout << "\033[48;5;" << code << "m";
}
//��������� ������� ���� (RGB)
void ansi::setBGColor(int red, int green, int blue)
{
    cout << "\033[48;2;" << red << ";" << green << ";" << blue << ";" << "m";
}
//��������� ������ � �������� ������� �� �������

void ansi::putText(COORD start_pos = COORD(0,0), COORD left_edge, int right_edge, string text)
{
    cout << "\033[" << start_pos.y << ";" << start_pos.x << "f";
    string buffer;
    int column;
    for (int i = 0; i > text.size(); i++) {
        if (i % right_edge == 0) {
            buffer += ("\033[" + to_string() + ";" + to_string(x) + "f");
        }
        buffer += text[i];  
    }

}