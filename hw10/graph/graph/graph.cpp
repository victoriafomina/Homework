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

int & Graph::edgeWeight(int const vertex1, int const vertex2)
{
	return adjacencyMatrix[vertex1][vertex2];
}

int const & Graph::edgeWeight(int const vertex1, int const vertex2) const
{
	return adjacencyMatrix[vertex1][vertex2];
}

int Graph::getNumberOfVertexes() const
{
	return numberOfVertexes;
}

void Graph::printVertexes() const
{
	for (set<int>::iterator i = vertexes.begin(); i != vertexes.end(); ++i)
	{
		cout << *i << " ";
	}
}

ostream & operator<<(ostream & os, Graph const & graph)
{
	for (int vertex1 = 0; vertex1 < graph.getNumberOfVertexes(); ++vertex1)
	{
		for (int vertex2 = 0; vertex2 < graph.getNumberOfVertexes(); ++vertex2)
		{
			os << graph.edgeWeight(vertex1, vertex2) << " ";
		}
		os << endl;
	}
	return os;
}

istream & operator>>(istream & is, Graph & graph)
{
	for (int vertex1 = 0; vertex1 < graph.getNumberOfVertexes(); ++vertex1)
	{
		graph.vertexes.insert(vertex1);
		for (int vertex2 = 0; vertex2 < graph.getNumberOfVertexes(); ++vertex2)
		{
			is >> graph.edgeWeight(vertex1, vertex2);
		}
	}
	return is;
}

set<int> Graph::subGraphFrontier(set<int> subGraph)
{
	set<int> frontier;
	for (set<int>::iterator vertex = subGraph.begin(); vertex != subGraph.end(); ++vertex)
	{
		// check if adjacent vertexes are in subgraph. if not add to frontier 
		for (set<int>::iterator frontierCandidate = vertexes.begin();
				frontierCandidate != vertexes.end(); ++frontierCandidate)
		{
			if (subGraph.find(*frontierCandidate) == subGraph.end() && 
					edgeWeight(*vertex, *frontierCandidate) != 0)
			{
				frontier.insert(*frontierCandidate);
			}
		}
	}
	return frontier;
}