//�������� ���������, ������� � ���������� ������ ��������� ������������ ��������� �������� :
//0 � �����
//1 � �������� �������� � ������������� ������
//2 � ������� �������� �� ������
//3 � ����������� ������
//��� �������� ������ ��������� ���������������.�������� � ������� ������.

#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List l;
	l.addNode(1);
	l.addNode(2);
	l.addNode(3);
	l.addNode(0);
	// cout << l << endl;
	l.deleteNode(2);
	l.deleteNode(1);
	l.deleteNode(3);
	l.deleteNode(0);
	l.deleteNode(2);
	cout << l << endl;
	

	// auto* temp = l.getHeadPtr();


	system("pause");
	return 0;
}