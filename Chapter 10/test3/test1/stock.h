#ifndef STOCK_H
#define STOCK_H

#include <string>

using namespace std;

class Stock
{
private:
	string company;
    long shares;//所持股票数量
    double share_val;//每股价格
    double total_val;//股票总值
    void set_tot() {total_val = shares * share_val;}
public:
	Stock();
	Stock(const string & co, long n = 0, double pr = 0.0);
	~Stock();

	//void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
	void show() const; //const成员函数
	const Stock & topval(const Stock & s) const;
};

#endif // STOCK_H
