#include "Game.h"

void GameI::Game(char* word)
{
	//������� � ������� �����
	_strupr_s(word, 21);
	int len = strlen(word);
	//������-�����
	char* copy = new char[len + 1];
	memset(copy, '*', len);
	copy[len] = 0;
	//������� + �������
	char letters[52];
	int i, j = 0;
	for (i = 0; i < 26; i++)
	{
		letters[j++] = i + 'A';
		letters[j++] = ' ';
	}
	//���������� ����
	letters[51] = 0;
	//�����
	char letter;
	char* pos;
	bool replace = false;
	do {
		//������� ������
		system("cls");
		cout << copy << endl << endl;
		cout << letters << endl << endl;
		cout << "Count of tries: " << Tries << endl
			<< endl;
		cout << "Input any letter:\t";
		cin >> letter;
		//�������� ������
		Beep(500, 200);
		//if(letter >= 'A' && letter <= 'Z'
		//|| letter >= 'a' && letter <= 'z')
		//�����?
		if (!isalpha(letter))
		{
			cout << "It's not a letter" << endl;
			//�������� �� 1 �������
			Sleep(1000);
			continue;
		}
		//������� ����� � �������
		letter = toupper(letter);
		//����� ����� � ��������
		pos = strchr(letters, letter);
		//����� ����� ��� ����
		if (pos == 0)
		{
			cout << "This letter have been already pressed" << endl;
			Sleep(1000);
			continue;
		}
		else
		{
			//������� ����� �� �������� 
			pos[0] = ' ';
		}
		//����� ����� � �����
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
		//������� ������
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
