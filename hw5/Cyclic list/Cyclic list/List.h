#pragma once
#include <iostream>

using namespace std;

struct Node;

struct List
{
	List();
	~List();
	void addNode(int const data);
	void deleteNode(int const data);
	bool isEmpty() const;
	bool ifOneNode() const;
	friend ostream & operator<<(ostream & os, List const & list);
	Node* getHead() const;
private:
	void deleteNodeIfOneNode(int const data);
	void deleteNodeIfMoreThanOneNode(int const data);
	void deleteHeadNodeIfMoreThanOneNode(int const data);
	void deleteNotHeadNodeIfMoreThanOneNode(int const data);
	void addNodeIfNextIsNotHead(Node * const newElement);
	void addNodeIfNextIsHead(Node * const newElement);
	Node* head;
};