#pragma once
#include <string>

struct Node;
struct List;

struct Set
{
	Set();
	~Set();
	bool add(char const data);
	bool exists(char const data) const;
	bool isEmpty() const;
	bool printExpression() const;
	bool printInAscendingOrder() const;
	bool printInDescendingOrder() const;
	void addExpression(char * str);
private:
	int readInfoFromFile();
	void printRecursion(Node const * const current) const;
	void addExpressionRecursion(char * str, Node*& current, int interator);
	void addIfOperator(char* str, Node*& current, int iterator);
	void addNodeNotToHead(Node* node, char const data);
	void removeRecursion(Node*& current);
	bool isOperator(char const symbol) const;
	bool isNumber(char const symbol) const;
	int getPositionOfClosingBracket(char const * str, int iterator) const;
	void treeTraversal(List & l) const;
	void treeTraversalRecursion(Node const * current, List & l) const;
	void existsRecursion(char const data, Node const * const current, bool & exists) const;
	Node* head;
};