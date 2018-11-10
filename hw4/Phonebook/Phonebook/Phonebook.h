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
#define _CRT_SECURE_NO_WARNINGS
#include "Subscriber.h"
#include <stdio.h>
#include <string.h>

struct Phonebook
{
	// ������������ - ����������
	Phonebook();
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
	void readInfoFromFile(); // ��������������� ����� � ������������
	Phonebook(Phonebook const & p) = delete; // ����������� �����������
	void operator=(Phonebook const & p) = delete; // �������� ������������

	Subscriber* base;
	int numberOfNotes;
};