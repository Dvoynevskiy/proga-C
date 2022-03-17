#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>// стандартный заголовочный файл ввода-вывода
#include <stdlib.h>// содержит в себе функции, занимающиеся 
//выделением памяти, контролем процесса выполнения программы, преобразованием типов и другие.
#include <stdbool.h>// содержит четыре макроса для работы с типом данных bool
// Макрос можно условно назвать функцией обработки и замены программного кода (убирает лишний программный код)
#include <string.h>// содержащий функции для работы со строками, оканчивающимися на 0, и различными функциями работы с памятью.

// Реализовать функции нахождения наибольшего общего делителя и наименьшего общего
// кратного двух натуральных чисел.

int gcd(int a, int b) {
	if (a == b) {
		return a;
	}
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}

int lcm(int a, int b)
{
	return (a*b) / gcd(a, b);
}


//Разработать рекурсивную функцию, удаляющую из строки все лишние пробелы. Пробелы
//считаются лишними, если их подряд идет более двух, если они стоят в конце строки после
//последней точки, если стоят после открывающегося парного знака препинания.
void spaceDeleterAlgorithm(char *str, int *length, int pos) {
	// Если это конец строки
	if (pos == *length - 1)
	{
		// Если строка, заканчивающаяся на [space symbol]
		if (str[pos] == ' ')
		{
			str[pos] = str[pos + 1];
			*length = *length - 1;
		}
		return;
	}

	// Если это первая позиция строки
	if (pos == 0) {
		// Если строка, начинающаяся с [space symbol]
		if (str[pos] == ' ')
		{
			// Перемещение всех строковых элементов влево на одну позицию
			for (int i = pos; i < *length; i++)
			{
				str[i] = str[i + 1];
			}
			// Укорочение строки
			*length = *length - 1;
			// Вызов одного и того же алгоритма
			spaceDeleterAlgorithm(str, length, pos);
		}
		else if (pos != *length - 1) {
			// Если мы не перейдем к концу строки
			// Вызов того же алгоритма для следующего строкового элемента
			spaceDeleterAlgorithm(str, length, pos + 1);
		}

		return;
	}

	// Создание флага: Если
	bool deleteFlag = 0;
	// ...обнаружены два пробела
	deleteFlag |= (str[pos] == ' ' && str[pos + 1] == ' ');
	// ...обнаруженный символ пары и пробел рядом с ним
	deleteFlag |= (str[pos] == '<' && str[pos + 1] == ' ');
	deleteFlag |= (str[pos] == ' ' && str[pos + 1] == '>');

	// В одной из таких ситуаций
	if (deleteFlag)
	{
		// Если обнаружен пробел перед символом пары
		if (str[pos] == ' ')
		{
			// Сохранение этого символа пары
			str[pos] = str[pos + 1];
		}

		for (int i = pos + 1; i < *length; i++)
		{
			str[i] = str[i + 1];
		}
		*length = *length - 1;

		spaceDeleterAlgorithm(str, length, pos);
		return;
	}

	// Если бы не было обнаружено никаких проблем
	// И мы не в конце цепочки
	if (pos != *length - 1)
	{
		// Вызовем проверку следующего элемента
		spaceDeleterAlgorithm(str, length, pos + 1);
	}
	return;
}


//Функция, которую нам нужно вызвать
void spaceDeleter(char *str)
{
	// Сохранение значения длины начальной строки
	int stringLength = strlen(str);

	// Вызов функции рекурсивного алгоритма
	spaceDeleterAlgorithm(str, &stringLength, 0);
}





int main()
{
	int n;
	// Task 1
	printf("Task 1...\n");

	printf("%i\n", gcd(4, 8));
	printf("%i\n", lcm(4, 8));

	// Task 2: Space deleter
	printf("Task 2...\n");

	// Пример строки:
	char str[BUFSIZ] = "     This     is the test string.  <     you       can see    that program is working  >.    ";

	printf("----- Original string -----\n|%s|\n", str);

	// Удаление лишних пробелов из строки
	spaceDeleter(str);
	printf("----- Cleared  string -----\n|%s|\n", str);
	scanf("%i", &n);
	return 0;
}