﻿#pragma once
#include <iostream>
#include "Sort.h"
#include <string>

#include "Node.h"

struct Node;

struct List
{
	List();

	~List();

	void addNode(std::string const & data);

	int deleteNode(std::string const & data);

	Node & operator[](int const & index);
									
	friend std::ostream & operator<<(std::ostream & os, List const & list);

	bool isEmpty() const;

	int size() const;

private:
	void deleteList();

	void deleteHead(Node* temp);

	void deleteElementThatIsNotHead(std::string const & data, Node* temp);

	int sizeOfList;
	Node* head;
};