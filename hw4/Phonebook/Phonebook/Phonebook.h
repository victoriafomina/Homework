//�������� ��������� - ���������� ����������.��� ������ ����� ������� ����� � ������ ���������, 
//� ������������� ������ ������������ ��������� �������� :
//0 - �����
//1 - �������� ������(��� � �������)
//2 - ����������� ��� ��������� ������
//3 - ����� ������� �� �����
//4 - ����� ��� �� ��������
//5 - ��������� ������� ������ � ����
//��� ������� ��������� ������ ������ ������ �� �����, ���� ����� ��� - �������� � ������ ���� �������.
//������ ���� ��������� ������ �������.

#pragma once
#include "Subscriber.h"
#include <stdio.h>

struct Phonebook
{
	// ������������ - �������� ������������ - ����������
	Phonebook();
	Phonebook & operator=(Phonebook const & p);
	~Phonebook();

	// getter - setter
	Subscriber operator[](int number) const;
	Subscriber & operator[](int number);
	int size() const;

	// ��������� ������
	void addNote(Subscriber const & note); // 1
	void printAllNotes() const; // 2
	void findNumberByName(char const * name) const; // 3
	void findNameByNumber(char const * number) const; // 4
	void saveToFile() const; // 5
private:
	Phonebook(Phonebook const & p); // ����������� �����������

	Subscriber* base;
	int numberOfNotes;
};

bool compareStr(char const * name1, char const * name2);