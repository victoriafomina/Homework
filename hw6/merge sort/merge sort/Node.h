#pragma once
#include "CompareInterface.h"
#include <string>

struct Node : CompareInterface
{
	explicit Node(std::string const & data); // ����������� � ����������
	Node();
	bool operator<(CompareInterface const & c) const;

	std::string data;
	Node* previous;
	Node* next;
};