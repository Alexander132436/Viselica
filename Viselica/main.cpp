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
//���-�� ��������� ����
int CountWords = 0;

void main()
{
	GameI a;
	Word c;

	//��������� ���� �� ������ � �������� ������ 
	FILE* f;
	
	if (fopen_s(&f, "1.txt", "rb") != 0)
	{
		//������
		perror("Open");
		return;
	}
	srand(time(0));
	char Word[21];
	//�������� ��������� �����
	if (!c.LoadWord(f, Word))
	{
		//���� ��������
		cout << "Error !!!" << endl;
		fclose(f);
		return;
	}
	char answer;
	//������, ���� �� �������
	do
	{
		a.Game(Word);
		//���� ������� �� ��������, �� �����
		if (Tries == 0)
		{
			cout << "Count of words: " << CountWords << endl;
			cout << "Bye-bye" << endl;
			break;
		}
		//���� ��������
		cout << "Continue ??? (Y/N)\t";
		cin >> answer;
		//��� ������?
		if (answer == 'Y' || answer == 'y')
			if (!c.LoadWord(f, Word))
			{
				cout << "Error !!!" << endl;
				fclose(f);
				return;
			}
	} while (answer == 'Y' || answer == 'y');
	//�������� ����������
	int hFile = _fileno(f);
	//������������� �����
	int size = _filelength(hFile);
	fseek(f, 0, 0);
	_locking(hFile, _LK_UNLCK, size);
	fclose(f);
}