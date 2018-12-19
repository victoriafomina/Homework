#include "graph.h"

using namespace std;

//���� ��������� ������� � ������, ����������� ��� ������.��� ������ ������ ������ � �����.
//������ � ������������ ������ ����� ������������� �� ������ ��������� : �������� k ������ ������� �����������, 
//����� �� ������� ������� ����������� ����������� ��������� ��������� �����, ��������������� ��������� ������� 
//� ����� - ���� �������, ��� ������������� �����������(�������� ��� ����� - ���� �������, ����������� �� ����� 
//	�� ���������� �����).������� ������������ �� ��� ���, ���� ��� ������ �� ����� ������������.
//	���� ����� �������.�� ������� ����� : n � ����� ������� � m � ����� �����.����� ������� ���� 
//	������ � ������� : i j len, i � j � ������ �������, len � ����� ������.����� ������ ����� k � ����� ������, 
//	����� � k ����� � ������ ������.���� ������� �� ������� ������ ���������� � ������ �������, ������������� 
//	������������.

Graph::Graph(int const numberOfVertexes)
{
	this->numberOfVertexes = numberOfVertexes;
	adjacencyMatrix = new int*[numberOfVertexes];
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		adjacencyMatrix[i] = new int[numberOfVertexes] {};
	}
}

Graph::~Graph()
{
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		delete[] adjacencyMatrix[i];
	}
	delete[] adjacencyMatrix;
}

int & Graph::operator()(int const i, int const j)
{
	return adjacencyMatrix[i][j];
}

int const & Graph::operator()(int const i, int const j) const
{
	return adjacencyMatrix[i][j];
}

ostream & operator<<(ostream & os, Graph const & graph)
{
	for (int i = 0; i < graph.numberOfVertexes; ++i)
	{
		for (int j = 0; j < graph.numberOfVertexes; ++j)
		{
			os << graph(i, j) << " ";
		}
		os << endl;
	}
	return os;
}

istream & operator>>(istream & is, Graph & graph)
{
	for (int i = 0; i < graph.numberOfVertexes; ++i)
	{
		for (int j = 0; j < graph.numberOfVertexes; ++j)
		{
			is >> graph(i, j);
		}
	}
	return is;
}