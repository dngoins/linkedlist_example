#include "List.h"

using namespace std;

List::List() : mySize(1), first(0), currentPtr(0)
{
	//myArray = new(nothrow) Type[maxSize];
	//assert(myArray != 0);
	first = (List::NodePointer)new(nothrow) List::Node(0);
	currentPtr = first;
}

List::~List()
{
	clearLinkedList(this->first);
}

void List::clearLinkedList(NodePointer link)
{
	if (link->next != NULL)
	{
		clearLinkedList(link->next);
	}
	delete link;
	link = 0;
}

List::List(const List& original)
	: mySize(original.mySize), first(0), currentPtr(0)
{	
	copyList(original);
}

void List::copyList(const List& original)
{
	// now we must copy contents of linked list
	first = (List::NodePointer)new(nothrow) List::Node(original.first->data);
	currentPtr = first;
	mySize = original.mySize;

	auto origPtr = original.first;
	while (origPtr != NULL)
	{
		origPtr = origPtr->next;
		currentPtr->next = (List::NodePointer)new(nothrow) List::Node(origPtr->data);
		currentPtr= currentPtr->next;
	}
}

const List& List::operator=(const List& rightHandSide)
{
	if (this != &rightHandSide)
	{
		if (mySize != rightHandSide.mySize)
		{
			clearLinkedList(this->first);
		}		
		copyList(rightHandSide);
	}
	return *this;
}

bool List::empty() const
{
	return (first != NULL);
}

void List::display(ostream& out) const
{ 	
	auto _ptr = first;
	while (_ptr != NULL)
	{
		out << _ptr->data << " ";
		_ptr = _ptr->next;
	}
	out << endl;
}

ostream& operator<<(ostream& out, const List& aList)
{
	aList.display(out);
	return out;

}

void List::insert(Type item, int pos)
{
	List::NodePointer _newPtr = (List::NodePointer)new(nothrow) Node(item);
	auto curPointer = findNode(pos);
	auto prePointer = findNode(pos - 1);

	if (curPointer == NULL)
	{
		insert(item);
		return;
	}

	if (prePointer == NULL)
	{
		// pre is beginning
		_newPtr->next = first;
		first = _newPtr;
		currentPtr = _newPtr;
		return;
	}
		
	_newPtr->next = prePointer->next;
	prePointer->next = _newPtr;
	mySize++;
}

void List::insert(Type item)
{
	List::NodePointer _newPtr = (List::NodePointer)new(nothrow) Node(item);
	auto lastPointer = findNode(mySize);
	if (lastPointer == NULL) lastPointer = _newPtr;
	else lastPointer->next = _newPtr;
	currentPtr = _newPtr;
	mySize++;
}

List::NodePointer List::findNode(const int pos) const
{
	// find the node at this position	
	auto _ptr = first;
	for (int i = 1; i < pos; i++)
		_ptr= _ptr->next;

	return _ptr;
}

void List::erase(int pos)
{
	if (mySize == 0)
	{
		cerr << "*** list empty ***\n";
		return;
	}
	if (pos < 0 || pos >= mySize)
	{
		cerr << "*** Illegal action ***\n";
		return;
	}

	NodePointer ptrToDelete = NULL;
	auto _prePtr = findNode(pos - 1);
	if (_prePtr != NULL)
	{
		ptrToDelete = _prePtr->next;
		_prePtr->next = ptrToDelete->next;
	}
	else
	{
		ptrToDelete = first;
		first = ptrToDelete->next;
	}
	delete ptrToDelete;

	mySize--;

}