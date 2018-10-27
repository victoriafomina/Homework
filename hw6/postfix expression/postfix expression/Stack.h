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
	void push(int data);
	// �������� �������� �� ������
	int pop();
	// ���������� �� �������� �������
	int peek();
	// ��������� �������� �� ���� ������
	bool isEmpty();
private:
	Element * head;
};