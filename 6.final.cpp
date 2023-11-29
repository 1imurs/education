/*
+	Сначала пользователь пишет число n
+	Затем в n строках записывает строки длиной не более 20 символов
+	Нужно считать каждую строку в статический буфер
+	И сразу после чтения очередной строки из статического буфера закинуть строку в динамический массив строк - двумерный массив чаров, с помощью функции strcpy
+	Далее вывести все строки в порядке неубывания
+	И в конце вывести число строк, в котором встречается подстрок part
+	Затем создать огромный буфер, в который можно поместить все строки из массива строк и вывести его. Строки склеивать в порядке ввода пользователем
*/

#include <iostream>
using namespace std;

int mystrlen(char* source);
char* mystrcpy(char* destination, const char* source);
int mystrcmp(const char* string1, const char* string2);
const char* mystrstr(const char* string1, const char* string2);
char* mystrcat(char* destptr, const char* srcptr);

int main()
{
	int n;
	cout << "Enter strings count: ";
	cin >> n;

	int gensize = 0, strsize = 0;
	char** array = new char* [n];
	char buffer[32];

	// СЧИТЫВАНИЕ СТРОК В СТАТИЧЕСКИЙ И ДИНАМИЧЕСКИЙ МАССИВЫ

	cout << "Enter " << n << " strings no longer than 20:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> buffer;
		if (mystrlen(buffer) > 20)
		{
			cout << "Error! String limit (20) overload!" << endl;
			return 0;
		}
		strsize = mystrlen(buffer);
		gensize += strsize;
		array[i] = new char[strsize + 1];
		mystrcpy(array[i], buffer);
	}

	char* general = new char[gensize + 1];
	general[0] = '\0';

	// СКЛЕИВАНИЕ СТРОК В ПОРЯДКЕ ВВОДА

	for (int i = 0; i < n; i++)
	{
		mystrcat(general, array[i]);
	}

	// ВЫВОД СТРОК В ПОРЯДКЕ НЕУБЫВАНИЯ

	cout << "Strings sorted by name:" << endl;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (mystrcmp(array[j], array[j + 1]) == -1)
			{
				swap(array[j], array[j + 1]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << endl;
	}

	// ВЫВОД КОЛИЧЕСТВА ПОДСТРОК part

	int partcnt = 0;
	char part[] = { "ful" };
	cout << "Number of matches in strings: ";
	for (int i = 0; i < n; i++)
	{
		if (mystrstr(array[i], part) != nullptr)
		{
			partcnt++;
		}
	}
	cout << partcnt << endl;

	cout << "Common string output: " << general << endl;

	for (int i = 0; i < n; i++)
	{
		delete[] array[i];
	}
	delete[] array;

	delete[] general;

	return 0;
}

int mystrlen(char* source)
{
	int i = 0;
	while (source[i] != '\0')
	{
		i++;
	}

	return i;
}

char* mystrcpy(char* destination, const char* source)
{
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';

	return destination;
}

int mystrcmp(const char* string1, const char* string2)
{
	int i = 0;
	for (; string1[i] != '\0' && string2[i] != '\0'; i++)
	{
		if (string1[i] > string2[i])
		{
			return -1;
		}

		else if (string1[i] < string2[i])
		{
			return 1;
		}
	}

	if (string1[i] != '\0')
	{
		return -1;
	}
	else if (string2[i] != '\0')
	{
		return 1;
	}

	return 0;
}

const char* mystrstr(const char* string1, const char* string2)
{
	int i = 0, j = 0;
	while (string1[i] != '\0')
	{
		while (string1[i] != string2[j] && string1[i] != '\0')
		{
			i++;
		}
		int k = i;
		while (string1[i] == string2[j])
		{
			j++;
			i++;
			if (string2[j] == '\0')
			{
				return string1 + k;
			}
		}
		j = 0;
	}
	return nullptr;
}

char* mystrcat(char* destptr, const char* srcptr)
{
	int i = 0;
	while (destptr[i] != '\0')
	{
		i++;
	}
	int j = 0;

	while (srcptr[j] != '\0')
	{
		destptr[i] = srcptr[j];
		i++;
		j++;
	}
	destptr[i] = '\0';

	return destptr;
}
