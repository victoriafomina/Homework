#pragma once
#include <iostream>
#include <string>

struct Node;

struct List
{
	List();

	~List();

	void addElement(std::string const & data);

	int deleteElement(std::string const & data);

	Node & operator[](int const & index);

	int operator()(int const & index);

	friend std::ostream & operator<<(std::ostream & os, List const & list);

	bool isEmpty() const;

	int size() const;

	int numberOfElements() const;

	bool exists(std::string const & data) const;

private:

	void deleteList();

	void deleteHead(std::string const & data, Node* temp);

	void deleteElementThatIsNotHead(std::string const & data, Node* temp);

	int numOfElements;
	int sizeOfList;
	Node* head;
};