#pragma once
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <time.h>
#include <sys\locking.h>
#include <string.h>
#include <ctype.h>
using namespace std;
class GameI
{
public:
	int Tries = 10;
	//���-�� ��������� ����
	int CountWords = 0;
	void Game(char* word);
	
};

