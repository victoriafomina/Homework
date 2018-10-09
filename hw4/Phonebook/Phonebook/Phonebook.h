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
#include <stdio.h>
#include <string.h>

struct Subscriber
{
	explicit Subscriber(char* name, char* number);
	Subscriber();
	Subscriber(Subscriber const & s);
	~Subscriber();
	void getName();
	void getNumber();
private:
	char* name;
	char* number;
};

struct Phonebook
{
	Phonebook();
	~Phonebook();
	void addNote(Subscriber const & s); // 1
	void printAllNotes() const; // 2
	void findNumberByName(char* name) const; // 3
	void findNameByNumber(int* number, int sizeOfNumber) const; // 4
	void saveCurrentDataToFile() const; // 5
private:
	Subscriber* base;
	int numberOfNotes;
};