#pragma once

struct Node
{
	explicit Node(int data);
	~Node();
	int data;
	Node* previous;
	Node* next;
private:
	Node();
};