#include "Node.h"

// ����������� - ����������

Node::Node(int data = 0)
{
	this->data = data;
	previous = nullptr;
	next = nullptr;
}

Node::~Node() {}