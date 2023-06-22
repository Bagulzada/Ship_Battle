#pragma once
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<time.h>
#include<conio.h>

using namespace std;

HANDLE h;

FILE* file;

typedef unsigned short us;

enum controllers {
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};