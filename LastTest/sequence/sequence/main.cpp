#include <iostream>
#include "List.h"

//�������� ���������, ������� ������ � ���������� ����� ����� �����(� ����� �������, ����� � ����� 0), 
//� ��������� ����� �� ����� ������ � ������� ����������� � ��� ����������, � ��������� ����, ������� ������ ����� 
//��� ����������� � ���� ������.

using namespace std;

int main()
{
	int number = 1;
	List l;
	cout << "Input numbers. 0 - is symbol of the end of input" << endl;
	while (number != 0)
	{
		cin >> number;
		if (number != 0)
		{
			l.addElement(number);
		}
	}
	l.sort();
	cout << l << endl;

	return 0;
}