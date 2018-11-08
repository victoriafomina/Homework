#pragma once
#include "Compare interface.h"

struct Node : CompareInterface
{
	explicit Node(int data); // ����������� � ����������
	~Node(); // ����������
	int data;
	Node* previous;
	Node* next;
private:
	Node(); // ����������� ��� ����������
};