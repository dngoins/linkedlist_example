#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <new>
#include <cassert>

const int CAPACITY = 10;
typedef int Type;

using namespace std;

class List
{
private:
	class Node
	{
	public:
		Node() {}
		Node(Type _data) : data(_data) {}
		Type data;
		Node * next = NULL;
	};

	typedef Node* NodePointer;

public:
	List();
	~List();
	List(const List& original);
	const List& operator=(const List& rightHandSide);
	bool empty() const;
	void insert(Type item);
	void insert(Type item, int pos);
	void erase(int pos);
	void display(ostream & out) const;

private:
	void clearLinkedList(NodePointer link);
	void copyList(const List& original);
	List::NodePointer findNode(const int pos) const;

private:
	int mySize = 0;
	//int myCapacity = 0;
	//Type* myArray = NULL;
	NodePointer first =NULL;
	NodePointer currentPtr = NULL;


};

ostream& operator<< (ostream& out, const List& aList);
