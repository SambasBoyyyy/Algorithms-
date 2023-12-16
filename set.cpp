// INTEGER SET EXAMPLE
// CPP program to illustrate
// Implementation of erase() function
#include <iostream>
#include <set>

using namespace std;

int main()
{
	// set declaration
	set<int> myset{ 1, 2, 3, 4, 5 };
	set<int>::iterator it;

	// defining iterator pointing
	// to the first element
	// it = myset.begin();

	// erasing the first element
    
	// myset.erase(it);
    it = myset.find(3);
    myset.erase(it);
    myset.insert(myset.begin(),3);
	// Printing the set
	for (auto it = myset.begin();
		it != myset.end(); ++it)
		cout << ' ' << *it;
	return 0;
}
