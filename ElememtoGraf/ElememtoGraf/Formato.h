#pragma once
#include <windows.h>

// Procedimiento GOTOXY
inline void gotoxy(short x, short y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
// Procedimiento COLOR
inline void color(WORD col)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}
