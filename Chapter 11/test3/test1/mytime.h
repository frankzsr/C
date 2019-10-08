#ifndef MYTIME_H
#define MYTIME_H


class Time
{
private:
	int hours;
	int minutes;

public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time operator+(const Time & t) const; //后面的const标示不会修改被隐式的访问的对象，括号中的const标示不会修改被显示的访问的对象
	Time operator-(const Time & t) const;
	Time operator*(double n) const;
	void Show() const;
};

#endif // MYTIME_H
