#pragma once
#include <iostream>

using namespace std;

struct Element;

struct Stack
{
	// �����������
	Stack();
	// ����������
	~Stack();
	// ����������� �����������

	// �������� ������������

	// ���������� �������� � ������
	void push(char data);
	// �������� �������� �� ������
	bool pop();
	// ���������� �� �������� �������
	char peek() const;
	// ��������� �������� �� ���� ������
	bool isEmpty() const;
private:
	Element* head;
};