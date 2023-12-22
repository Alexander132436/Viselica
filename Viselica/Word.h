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
#define MAX_WORD_LENGTH 21
class Word
{
public:
	//Метод декодирования слова из файла
	char* ReverceStr(char* s);
	bool LoadWord(FILE* file, char* word);
};

