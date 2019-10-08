#include <iostream>
#include "mytime.h"

Time::Time()
{
	this->hours = this->minutes = 0;
}

Time::Time(int h, int m)
{
	this->hours = h;
	this->minutes = m;
}

void Time::AddMin(int m)
{
	this->minutes += m;
	this->hours += this->minutes / 60;
	this->minutes %= 60;
}

void Time::AddHr(int h)
{
	this->hours += h;
}

void Time::Reset(int h, int m)
{
	this->hours = h;
	this->minutes = m;
}

//Sum()的参数是引用，但返回类型不是引用
//将参数声明为引用的目的是提高效率
//如果按值传递Time对象，代码的功能相同，但传递引用速度会更快，使用的内存将更少
//如果返回类型是Time &，则引用的将是sum对象，但是sum对象是局部变量，在函数结束时将被删除，因此引用将指向一个不存在的对象
//使用返回类型Time意味着程序在删除sum之前构造它的拷贝，调用函数将得到它的拷贝
Time Time::operator+(const Time &t) const
{
	Time sum;
	sum.minutes = this->minutes + t.minutes;
	sum.hours = this->hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator-(const Time &t) const
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = this->minutes + 60 * this->hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}

Time Time::operator*(double n) const
{
	Time result;
	long totalminutes = this->hours * n * 60 + this->minutes * n;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

void Time::Show() const
{
	std::cout << hours << " hours, " << minutes << " minutes";
}
