#pragma once

struct Element;

struct Stack
{
	// �����������
	Stack();

	// ����������
	~Stack();

	// ���������� �������� � ������
	void push(int data);

	// �������� �������� �� ������
	bool pop();

	// ���������� �� �������� �������
	int peek() const;

	// ��������� �������� �� ���� ������
	bool isEmpty() const;
private:
	Element * head;
};