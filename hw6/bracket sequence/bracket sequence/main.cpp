#include "Stack.h"
#include "bracket sequence.h"
#include <string>
#include <iostream>

// �������� ��������� �������� ������� ������ � ������, ������ ����� ���� ��� ����� 
// : (), [], {}.��������� ������������������ ����({ ) } ��������� ������������, ({}) - ����������.

using namespace std;

// bool ifBracketSequenceIsCorrect(string const & str);

int main()
{
	string s;
	cout << "Input string" << endl;
	cin >> s;
	bool result = ifBracketSequenceIsCorrect(s);
	cout << "res is " << result << endl;

	system("pause");
	return 0;
}