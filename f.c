#include <stdio.h>
#include <stdlib.h>
#define N 128

int main()
{
	char str[N] = {'\0'};
	int count = 0;
	int first = 0;
	int numw = 0;
	char** words = NULL;
	int len = 0;

	printf("Type string: ");
	for (int i = 0; i < N - 1; ++i)		//считать строку и посчитать пробелы
	{
		str[i] = getchar();
		if (str[i] == ' ')
		       ++numw;
		if (str[i] == '\0' || str[i] == '\n')
		{
			str[i] = ' ';
			++numw;
			break;
		}
	}
	
	words = (char**) malloc(numw * sizeof(char*));		//создать массив адресов

	for (int j = 0; j < N; ++j)		//посчитать количество слов и создать слова
	{
		if (str[j] != ' ' && str[j] != '\0')
		{
			len = 0;
			first = j;
			while (str[j] != ' ' && str[j] != '\0')
			{
				++len;
				++j;
			}
			words[count] = (char*) malloc((len + 1) * sizeof(char));
			for (int i = 0; i <= len; ++i)
			{
				words[count][i] = str[first];
				++first;
			}
			words[count][len++] = '\0';
			++count;
		}
	}

	for (int i = count; i < numw; ++i)	//очистить лишние адреса
		free(words[i]);
		
	for (int i = 0; i < count; ++i)		//вывести слова в нужном порядке
	{
		len = 0;
		while (words[i][++len] != '\0');
		while (len >= 0)
			putchar(words[i][len--]);
		printf("\n");
		free(words[i]);		//очистить слова
	}
	free(words);

	return 0;
}
