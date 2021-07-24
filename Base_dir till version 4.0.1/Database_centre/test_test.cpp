//place this file on desktop and see the working

#include<iostream>
#include<cstring>
#include<fstream>
#include<conio.h>
#include<sstream>
#include<stdio.h>
#include<iomanip>
#include<ctype.h>
#include<windows.h>
#include<dir.h>
#include<math.h>
#include<limits>
#include<process.h>
#include<windows.h>

using namespace std;

//for positioning cursor at different locations on the console screen
#define console GetStdHandle(STD_OUTPUT_HANDLE)
//coordinate variable
COORD CursorPosition;

//definition of gotoxy() fn
void gotoXY(int x,int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console,CursorPosition);
}

int main()
{
    system("color a");
    char data[64];
    gets(data);
    ofstream file;
    file.open("open_file.bat",ios::out);
    file<<data;
    file.close();
    ShellExecute(NULL,"open","open_file.bat",NULL,NULL,SW_HIDE);
}
