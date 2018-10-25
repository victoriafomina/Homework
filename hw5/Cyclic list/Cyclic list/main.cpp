// "����������" � ����� �� 41 - �� �������, ���������� ����������� �������� �������, 
// �� ������� ��������� � ���� ������������� ��� ������������� ����� ������.
// ������� ����� � ���� � ������������, ��� ������ ��� ����� ����� ������� ��������, ���� �� �������� ���.
// ������������ � ������ ����, �� ���, ��� � ����� ������ ��������� ���������, ������ ����� ��� ���������.
// ����� ������, ������������� ���� �������, ����� ������ ���������, ��� ����� ����� ��� � ��� �����, 
// ����� �������� ����������, �� �� ��� ����, ����� ����� ���� �����, � ����� ����� �������� ��������.
// � ����� ������ ��������� n ������ � ������� ������� m - ��.��������� ���������� ����� k ��������� ������� �����, 
// ������� ������ ����� �������� ���������.������� � ������� ������������ ������.

#include <iostream>
#include <fstream>

using namespace std;

int josephusProblem(int const numberOfWarriors, int const murderFrequency);
void tests();
int parser(int* numbers, char const * string);

int main()
{
	// ���� ������������� ����� ���� ��� ����, ����� ����������� ��������������

	//int n = 0;
	//cout << "Input number of warriors\n";
	//cin >> n;
	//int m = 0;
	//cout << "Input murder frequency\n";
	//cin >> m;
	//cout << "Safe position is " << josephusProblem(n, m) << endl;

	tests();

	system("pause");
	return 0;
}

void tests()
{
	ifstream file("tests.txt");
	int numberOfStrings = 0;
	if (!file.is_open())
	{
		cout << "File could not be opened\n";
	}
	else
	{
		int const size = 25;
		char buffer[size] {};
		int numbers[size] {};
		int count = 1;
		while (!file.eof())
		{
			file.getline(buffer, size);
			int sizeOfArray = parser(numbers, buffer);
			++numberOfStrings;
			for (int i = 0; i < 10; ++i)
			{
				int result = josephusProblem(numberOfStrings, i + 1);
				if (result == numbers[i])
				{
					cout << "Test " << count << " passed" << endl;
				}
				else
				{
					cout << "Test " << count << " FAILED" << endl;
				}
				count++;
			}
		}
	}
}

int parser(int* numbers, char const * string)
{
	int const sizeOfTemp = 100;
	char* temp = new char[sizeOfTemp];
	int size = 0;
	int iterator = 0;
	while (string[iterator] != '\0')
	{
		int j = 0;
		bool ifSpaceOrEndOfLineOrEndOfStr = false;
		while (string[iterator] != ' ' && string[iterator] != '\n' && string[iterator] != '\0')
		{
			temp[j] = string[iterator];
			++j;
			++iterator;
			ifSpaceOrEndOfLineOrEndOfStr = true;
		}
		if (ifSpaceOrEndOfLineOrEndOfStr)
		{
			temp[j] = '\0';
			numbers[size] = atoi(temp);
			++size;
		}
		else
		{
			++iterator;
		}
	}
	delete[] temp;
	return size;
}