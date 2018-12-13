#include "hashTable.h"
#include <algorithm>
#include <string>
#include <iostream>
#include "List.h"

using namespace std;

//��������� ������� ������������� ���� � ������ � ������� ��� - �������. �� ����� ���� � �������, 
//������� �� ������� ��� �����, ������������� � ���� ������ � ����������� ���, ������� ����������� ������ �����.
//������ ��������� ������������������ ��������, ���������� ���������, ������ ���������� ��������� ������� �������.
//��� - ������� ����������� � ��������� ������, ������������ ������ "������". ���������� � ������� ����� 
//����������� ���������� ��� - �������, ������������ � ������� ����� ������ � �������� �������.

Set::Set()
{
	int size = 100;
	buckets.resize(size);
}

void Set::addElement(std::string const & str)
{
	if (!exists(str))
	{
		int hash = hashFunction(str) % size();
		buckets[hash].addElement(str);
	}
}

void Set::deleteElement(std::string const & str)
{
	if (exists(str))
	{
		int hash = hashFunction(str) % size();
		buckets[hash].deleteElement(str);
	}
}

bool Set::exists(std::string const & str) const
{
	int hash = hashFunction(str) % size();
	return buckets[hash].exists(str);
}

int Set::hashFunction(std::string const & str) const
{
	int sum = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		sum += sum * 5 + str[i];
	}
	return sum;
}

double Set::loadFactor() const
{
	int sum = numberOfElements();
	return (double)sum / size();
}

int Set::numberOfElements() const
{
	int sum = 0;
	for (int i = 0; i < size(); ++i)
	{
		sum += buckets[i].numberOfElements();
	}
	return sum;
}

int Set::maxSizeOfList() const
{
	int max = 0;
	for (int i = 0; i < size(); ++i)
	{
		if (buckets[i].numberOfElements() > max)
		{
			max = buckets[i].numberOfElements();
		}
	}
	return max;
}

double Set::averageSizeOfList() const
{
	int sum = 0;
	for (int i = 0; i < size(); ++i)
	{
		sum += buckets[i].size();
	}
	return double(sum) / size();
}

int Set::size() const
{
	return buckets.size();
}

void Set::frequencyOfEveryWord()
{
	for (int i = 0; i < size(); ++i)
	{
		if (!buckets[i].isEmpty())
		{
			for 
		}
	}
}