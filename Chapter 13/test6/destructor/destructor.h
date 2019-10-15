#ifndef DESTRUCTOR_H
#define DESTRUCTOR_H

#include <iostream>

using namespace std;

class Destructor
{
private:
	int num;
public:
	Destructor(int n = 0);
	int ret_num() { return num; }
	virtual void print_f(bool flag);
	virtual ~Destructor() {cout << "Destructor is over!" << endl;}
	//virtual ~Destructor();
};

class Child : public Destructor
{
private:
	int apple;
public:
	Child(int n = 0, int a = 0);
	Child(const Destructor &des, int a = 0);
	virtual void print_f(bool flag);
	~Child();
};

#endif // DESTRUCTOR_H
