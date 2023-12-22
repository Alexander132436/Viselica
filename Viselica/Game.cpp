#include "Game.h"

void GameI::Game(char* word)
{
	//Перевод в большие буквы
	_strupr_s(word, 21);
	int len = strlen(word);
	//Строка-копия
	char* copy = new char[len + 1];
	memset(copy, '*', len);
	copy[len] = 0;
	//Алфавит + пробелы
	char letters[52];
	int i, j = 0;
	for (i = 0; i < 26; i++)
	{
		letters[j++] = i + 'A';
		letters[j++] = ' ';
	}
	//Замыкающий ноль
	letters[51] = 0;
	//Буква
	char letter;
	char* pos;
	bool replace = false;
	do {
		//Очистка экрана
		system("cls");
		cout << copy << endl << endl;
		cout << letters << endl << endl;
		cout << "Count of tries: " << Tries << endl
			<< endl;
		cout << "Input any letter:\t";
		cin >> letter;
		//Звуковой сигнал
		Beep(500, 200);
		//if(letter >= 'A' && letter <= 'Z'
		//|| letter >= 'a' && letter <= 'z')
		//Буква?
		if (!isalpha(letter))
		{
			cout << "It's not a letter" << endl;
			//Задержка на 1 секунду
			Sleep(1000);
			continue;
		}
		//Перевод буквы в большую
		letter = toupper(letter);
		//Поиск буквы в алфавите
		pos = strchr(letters, letter);
		//Такая буква уже была
		if (pos == 0)
		{
			cout << "This letter have been already pressed" << endl;
			Sleep(1000);
			continue;
		}
		else
		{
			//Убираем букву из алфавита 
			pos[0] = ' ';
		}
		//Поиск буквы в слове
		for (i = 0; i < len; i++)
		{
			if (word[i] == letter)
			{
				copy[i] = letter;
				replace = true;
			}
		}
		if (replace == false)
			Tries--;
		else
			replace = false;
		//Условие победы
		if (strcmp(word, copy) == 0)
		{
			system("cls");
			cout << copy << endl << endl;
			cout << letters << endl << endl;
			cout << "Count of tries: " << Tries << endl << endl;
			cout << "Congratulation !!!" << endl;
			CountWords++;
			break;
		}
	} while (Tries != 0);
	delete[] copy;
}
