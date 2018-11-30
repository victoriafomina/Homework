#pragma once
#include <string>

struct Node
{
	Node(std::string const & key, std::string const & value);

	std::string key; // ������ ������� �������� � 2 ����������� �������
	std::string value;
	int balanceFactor;
	Node* parent;
	Node* leftChild;
	Node* rightChild;
};