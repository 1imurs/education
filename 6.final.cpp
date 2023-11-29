/*
+	������� ������������ ����� ����� n
+	����� � n ������� ���������� ������ ������ �� ����� 20 ��������
+	����� ������� ������ ������ � ����������� �����
+	� ����� ����� ������ ��������� ������ �� ������������ ������ �������� ������ � ������������ ������ ����� - ��������� ������ �����, � ������� ������� strcpy
+	����� ������� ��� ������ � ������� ����������
+	� � ����� ������� ����� �����, � ������� ����������� �������� part
	����� ������� �������� �����, � ������� ����� ��������� ��� ������ �� ������� ����� � ������� ���. ������ ��������� � ������� ����� �������������
*/
/*
#include <iostream>
using namespace std;

char* mystrcpy(char* destination, const char* source);
int mystrcmp(const char* string1, const char* string2);
const char* mystrstr(const char* string1, const char* string2);
char* mystrcat(char* destptr, const char* srcptr);

int main()
{
	int n;
	cout << "Enter strings count: ";
	cin >> n;

	int gensize = 0, strsize = 1;
	char** array = new char* [n];
	char buffer[32];

	// ���������� ����� � ����������� � ������������ �������

	cout << "Enter " << n << " strings no longer than 20:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> buffer;
		if (strlen(buffer) > 20)
		{
			cout << "Error! String limit (20) overload!" << endl;
			return 0;
		}
		strsize = strlen(buffer);
		gensize = gensize + strsize;
		array[i] = new char[strsize];
		mystrcpy(array[i], buffer);
	}

	char* general = new char[gensize];

	// ���������� ����� � ������� �����

	for (int i = 0; i < n; i++)
	{
		mystrcat(general, array[i]);
	}

	// ����� ����� � ������� ����������

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

	// ����� ���������� �������� part

	int partcnt = 0;
	char part[] = { "ful" };
	cout << "Number of matches in strings: ";
	for (int i = 0; i < n; i++)
	{
		mystrstr(array[i], part);
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
*/