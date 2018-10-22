// "����������" � ����� �� 41 - �� �������, ���������� ����������� �������� �������, 
// �� ������� ��������� � ���� ������������� ��� ������������� ����� ������.
// ������� ����� � ���� � ������������, ��� ������ ��� ����� ����� ������� ��������, ���� �� �������� ���.
// ������������ � ������ ����, �� ���, ��� � ����� ������ ��������� ���������, ������ ����� ��� ���������.
// ����� ������, ������������� ���� �������, ����� ������ ���������, ��� ����� ����� ��� � ��� �����, 
// ����� �������� ����������, �� �� ��� ����, ����� ����� ���� �����, � ����� ����� �������� ��������.
// � ����� ������ ��������� n ������ � ������� ������� m - ��.��������� ���������� ����� k ��������� ������� �����, 
// ������� ������ ����� �������� ���������.������� � ������� ������������ ������.

#include <iostream>

using namespace std;

int josephusProblem(int const numberOfWarriors, int const murderFrequency);
void tests();

int main()
{
	int n = 0;
	cout << "Input number of warriors\n";
	cin >> n;
	int m = 0;
	cout << "Input murder frequency\n";
	cin >> m;
	cout << "Safe position is " << josephusProblem(n, m) << endl;

	system("pause");
	return 0;
}

void tests()
{
	int numberOfTests = 0;
	int const cols = 5;
	int const rows = 5;
	int** array{};
	int count = 1;
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 1; j <= cols; ++j)
		{
			if (array[i][j] == josephusProblem(i, j))
			{
				cout << "Test " << count << " passed\n";
			}
			else
			{
				cout << "Test " << count << " FAILED\n";
				cout << "Input: " << i << ", " << j << endl;
				cout << "Output: " << josephusProblem(i, j) << endl;
				cout << "Right output: " << array[i][j] << endl << endl;
			}
			++count;
		}
	}
}