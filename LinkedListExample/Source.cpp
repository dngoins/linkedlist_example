#include "List.h"
#include <string>

using namespace std;

int main()
{
	List l;

	l.insert(1);
	l.insert(2);
	l.insert(3);
	cout << l;

	return 0;
}