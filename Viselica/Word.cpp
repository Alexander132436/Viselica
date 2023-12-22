#include "Word.h"

char* Word::ReverceStr(char* s)
{
	char  c;
	char* s0 = s - 1;
	char* s1 = s;

	while (*s1) ++s1;

	while (s1-- > ++s0)
	{
		c = *s0;
		*s0 = *s1;
		*s1 = c;
	}

	return s;
}

bool Word::LoadWord(FILE* file, char* word)
{
	int i = 0;
	char s[MAX_WORD_LENGTH] = { 0 };
	//���-�� ���� � �����
	static int count = -1;
	if (count == -1)
	{
		//������� ���������� ����
		while (!feof(file))
		{
			fgets(s, MAX_WORD_LENGTH, file);
			count++;
		}
		//���� ���?
		if (count == 0)
			return false;
		//������� ��������� ��������� � ������ ����� 
		fseek(file, 0, 0);
	}
	//��������� �����
	int n = rand() % count;
	//����� �����
	while (i <= n)
	{
		fgets(s, MAX_WORD_LENGTH, file);
		i++;
	}
	//���������� ����� �����
	int wordlen = strlen(s);
	//����������� ����� ����� 2 �����
	if (wordlen <= 1)
		return false;
	//������� Enter (� DOS'� 2 ����� 13 10)
	if (s[wordlen - 1] == 10)
	{
		s[wordlen - 2] = 0;
	}
	else if (s[wordlen - 1] == 13)
	{
		s[wordlen - 1] = 0;
	}
	ReverceStr(s);
	//�������� �����
	strcpy_s(word, 21, s);
	//�������� ���������� �����
	int hFile = _fileno(file);
	//��������� ������ �����
	int size = _filelength(hFile);

	//���������� �����
	fseek(file, 0, 0);
	_locking(hFile, _LK_NBLCK, size);
	return true;
}


