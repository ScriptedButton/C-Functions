// Easy++ Development Release

#pragma once
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

void print(string text)
{
	// Print Function | print(text)
	cout << text;
}

void pause()
{
	// Pause Function
	system("pause");
}

void open(string url)
{
	// Open Function | open(path)
	ShellExecute(0, 0, url.c_str(), 0, 0, SW_SHOW);
}

void wait(int time)
{
	// Wait Function | wait(1) | wait 1 second
	Sleep(time + 000);
}

void color(string color)
{
	// Color Function | color(color) |
	string res = "color " + color;
	system(res.c_str());
}

void colorList()
{
	/*
	The different color codes are

	0   BLACK
	1   BLUE
	2   GREEN
	3   CYAN
	4   RED
	5   MAGENTA
	6   BROWN
	7   LIGHTGRAY
	8   DARKGRAY
	9   LIGHTBLUE
	10  LIGHTGREEN
	11  LIGHTCYAN
	12  LIGHTRED
	13  LIGHTMAGENTA
	14  YELLOW
	15  WHITE
	*/
}

void title(string var)
{
	string res = "title " + var;
	system(res.c_str());
}

void msgBox(string msg, string title = "Notification")
{
	MessageBox(0, msg.c_str(), title.c_str(), MB_OK);
}

void clear()
{
	system("cls");
}

void close()
{
	exit(0);
}

string currentPath()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}
