#include <iostream>
#include "destructor.h"

using namespace std;

Destructor::Destructor(int n)
{
	num = n;
}

void Destructor::print_f(bool flag)
{
	if (flag)
		cout << "num is : " << num << endl;
	else {
		cout << "Destructor is false!" << endl;
	}
}

//Destructor::~Destructor()
//{
//	cout << "Destructor is over!" << endl;
//}

Child::Child(int n, int a) : Destructor (n)
{
	apple = a;
}

Child::Child(const Destructor &des, int a) : Destructor (des)
{
	apple = a;
}

void Child::print_f(bool flag)
{
	int num = ret_num();
	if (flag)
	{
		cout << "apple is : " << apple << ", num is : " << num << endl;
	}
	else {
		cout << "Class is false!" << endl;
	}
}

Child::~Child()
{
	cout << "Child is over!" << endl;
}
