#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <time.h>
#include <sys\locking.h>
#include <string.h>
#include <ctype.h>
#include "Word.h"
#include "Game.h"
using namespace std;

int Tries = 10;
//Кол-во угаданных слов
int CountWords = 0;

void main()
{
	GameI a;
	Word c;

	//Открываем файл на чтение в двоичном режиме 
	FILE* f;
	
	if (fopen_s(&f, "1.txt", "rb") != 0)
	{
		//Ошибка
		perror("Open");
		return;
	}
	srand(time(0));
	char Word[21];
	//Пытаемся загрузить слово
	if (!c.LoadWord(f, Word))
	{
		//Если неудачно
		cout << "Error !!!" << endl;
		fclose(f);
		return;
	}
	char answer;
	//Играем, пока не надоест
	do
	{
		a.Game(Word);
		//Если попыток не осталось, то выход
		if (Tries == 0)
		{
			cout << "Count of words: " << CountWords << endl;
			cout << "Bye-bye" << endl;
			break;
		}
		//Если остались
		cout << "Continue ??? (Y/N)\t";
		cin >> answer;
		//Еще играем?
		if (answer == 'Y' || answer == 'y')
			if (!c.LoadWord(f, Word))
			{
				cout << "Error !!!" << endl;
				fclose(f);
				return;
			}
	} while (answer == 'Y' || answer == 'y');
	//получаем дескриптор
	int hFile = _fileno(f);
	//Разблокировка файла
	int size = _filelength(hFile);
	fseek(f, 0, 0);
	_locking(hFile, _LK_UNLCK, size);
	fclose(f);
}