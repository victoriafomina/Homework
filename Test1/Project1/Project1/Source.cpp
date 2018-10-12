// ����������� ���������� �������.����������� ������(�������� � 10 ���������) 
// �������� � ����������.���������� ������� - ��� ��, ��� � ����������������� ����� ������� 
// ������ ����������� ������� � ����������� � ��������������� �����.

#include "Header.h"

void swap(int & a, int & b);

void selectionSort(int size, int* array)
{
	for (int i = 0; i < size; ++i)
	{
		int min = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		swap(array[i], array[min]);
	}
}

void swap(int & a, int & b)
{
	int const c = a;
	a = b;
	b = c;
}