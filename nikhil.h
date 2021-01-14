#ifndef NIKHIL_H_INCLUDED 
#define NIKHIL_H_INCLUDED
#include "windows.h"
// function for moving to a specific location on output screen
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Macros for clear screen
#define cls (system("cls"))

// Macros for pause screen
#define pause (system("pause"))

/*// Macros for text color
#define col(x) ({HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);SetConsoleTextAttribute(color,x);})
*/
//function for text color
void setcolor(int x)
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color,x);
}
// Macros for text color
/*#define blue      (system("color 1"))
#define green     (system("color 2"))
#define aqua      (system("color 3"))
#define red       (system("color 4"))
#define purple    (system("color 5"))
#define yellow    (system("color 6"))
#define white     (system("color 7"))
#define grey      (system("color 8"))
#define black     (system("color 0"))

#define lblue     (system("color 9"))
#define lgreen    (system("color A"))
#define laqua     (system("color B"))
#define lred      (system("color C"))
#define lpurple   (system("color D"))
#define lyellow   (system("color E"))
#define bwhite    (system("color F"))
*/

#endif // NIKHIL_H_INCLUDED
