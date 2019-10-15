#include <iostream>
#include "destructor.h"

using namespace std;

int main()
{
	cout << "Hello World!" << endl;

	Destructor d(5);
	Child c(9, 9);

	d.print_f(true);
	c.print_f(true);

	return 0;
}
