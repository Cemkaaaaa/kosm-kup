#include "ansiUtils.h"
#include <iostream>
#include <string>
//������� �������

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

void ansi::putText(COORD left_edge = ansi::getCursorPos(), int right_edge = 0, string text = "")
{
    string buffer;

    int column = 0;
    bool flag = false;
    for (int i = 0; i < text.size(); i++) {
        if (!flag) {
            if (i % right_edge == 0) {
                column++;
                buffer += ("\033[" + to_string(left_edge.y + column) + ";" + to_string(left_edge.x) + "f");
            }
            else if (text[i] == '\\') flag = true;
            else {
                buffer += text[i];
            }
        }
        else {
            if (text[i] == 'n') {
                column++;
                buffer += ("\033[" + to_string(left_edge.y + column) + ";" + to_string(left_edge.x) + "f");
                flag = false;
            }
            else {
                flag = false;
                buffer += text[i - 1] + text[i];
            }
            
        }
    }
    cout << buffer;
}
int main() {

    ansi::putText(ansi::COORD(6,6), 20, "11111111111111111\n1111111111111111111111111111111111111111111111111111111111111111111111111111111111");
    return 0;
}