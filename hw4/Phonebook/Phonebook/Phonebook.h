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
	Phonebook(Phonebook const & p);
	Phonebook & operator=(Phonebook const & p);
	~Phonebook();

	// getter - setter

	void addNote(Subscriber const & s); // 1
	void printAllNotes() const; // 2
	void findNumberByName(char const * name) const; // 3
	void findNameByNumber(int const * number, int sizeOfNumber) const; // 4
	void saveToFile() const; // 5
private:
	Subscriber* base;
	int numberOfNotes;
};