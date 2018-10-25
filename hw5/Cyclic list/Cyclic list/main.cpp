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
		int* numbers = new int[size] {};
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
		delete[] numbers;
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
		bool flag = false;
		while (string[iterator] != ' ' && string[iterator] != '\n' && string[iterator] != '\0')
		{
			temp[j] = string[iterator];
			++j;
			++iterator;
			flag = true;
		}
		if (flag)
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
//void tests()
//{
//	int numberOfTests = 0;
//	int const cols = 5;
//	int const rows = 5;
//	int** array{};
//	int count = 1;
//	for (int i = 1; i <= rows; ++i)
//	{
//		for (int j = 1; j <= cols; ++j)
//		{
//			if (array[i][j] == josephusProblem(i, j))
//			{
//				cout << "Test " << count << " passed\n";
//			}
//			else
//			{
//				cout << "Test " << count << " FAILED\n";
//				cout << "Input: " << i << ", " << j << endl;
//				cout << "Output: " << josephusProblem(i, j) << endl;
//				cout << "Right output: " << array[i][j] << endl << endl;
//			}
//			++count;
//		}
//	}
//}