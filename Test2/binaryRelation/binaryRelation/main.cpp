//�� ��������� ��������� �� ��������� �� n ��������� ��������� ��� ������������ ���������.
//� ����� ������� ����� n � ������� n*n, �������� ���������(� ������(i, j) ����� 1, ���� ���� ���������(i, j) 
//	����������� ��������� � 0 � ��������� ������).������� � ������ ���� �������, �������� ������������ 
//	��������� ����� ���������.

#include <iostream>
#include "workWithFiles.h"

using namespace std;

int main()
{
	ifstream fileToRead;
	fileToRead.open("input.txt", ios::in);
	int size = readNumberFromFile(fileToRead);
	int** matrix = createMatrix(size);
	readMatrixFromFile(fileToRead, matrix, size);
	ofstream fileToWrite;
	fileToWrite.open("output.txt");
	int** matrixToWrite = createMatrix(size);
	transitiveClosure(matrix, matrixToWrite, size, fileToWrite);
	fileToRead.close();
	fileToWrite.close();
	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
		delete[] matrixToWrite[i];
	}
	delete matrix;
	delete matrixToWrite;

	return 0;
}