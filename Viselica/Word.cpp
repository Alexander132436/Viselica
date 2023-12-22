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
	//Кол-во слов в файле
	static int count = -1;
	if (count == -1)
	{
		//Подсчет количества слов
		while (!feof(file))
		{
			fgets(s, MAX_WORD_LENGTH, file);
			count++;
		}
		//Слов нет?
		if (count == 0)
			return false;
		//Возврат файлового указателя в начало файла 
		fseek(file, 0, 0);
	}
	//Случайное слово
	int n = rand() % count;
	//Поиск слова
	while (i <= n)
	{
		fgets(s, MAX_WORD_LENGTH, file);
		i++;
	}
	//Определяем длину слова
	int wordlen = strlen(s);
	//Минимальная длина слова 2 буквы
	if (wordlen <= 1)
		return false;
	//Убираем Enter (в DOS'е 2 байта 13 10)
	if (s[wordlen - 1] == 10)
	{
		s[wordlen - 2] = 0;
	}
	else if (s[wordlen - 1] == 13)
	{
		s[wordlen - 1] = 0;
	}
	ReverceStr(s);
	//Копируем слово
	strcpy_s(word, 21, s);
	//Получаем дескриптор файла
	int hFile = _fileno(file);
	//Вычисляем размер файла
	int size = _filelength(hFile);

	//Блокировка файла
	fseek(file, 0, 0);
	_locking(hFile, _LK_NBLCK, size);
	return true;
}


