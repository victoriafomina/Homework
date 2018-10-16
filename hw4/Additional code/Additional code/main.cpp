#include "Header.h"
#include "locale.h"

// ������ ��� �����, ��������� � �������� ������������� � �������������� ���� � ����������, 
// ������� � ������� � �������� �������������, ������� �����, ��������� � ����������, 
// ������� ����� � ���������� ����.��� ��������� ������ �� - ������(������������� ������������ ������� setlocale, 
// ����� ��������� ���������� �� - ������ � ��� Windows ����).

int main()
{
	// ��� ������ ������

	setlocale(LC_ALL, "Russian");
	int number1 = 0;
	printf("������� ������ �����\n");
	scanf("%i", &number1);
	int number2 = 0;
	printf("������� ������ �����\n");
	scanf("%i", &number2);
	auto num1 = additionalCode(number1);
	auto num2 = additionalCode(number2);
	printf("������ ����� � �������������� ����:\n");
	num1.print();
	printf("\n");
	printf("������ ����� � �������������� ����:\n");
	num2.print();
	printf("\n");
	auto sum = num1 + num2;
	printf("����� � �������������� ����\n");
	sum.print();
	printf("\n");
	printf("����� � ���������� �������\n");
	sum.printInDecimalSystem();
	printf("\n");

	return 0;
}