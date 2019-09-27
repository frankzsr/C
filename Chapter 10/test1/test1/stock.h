#ifndef STOCK_H
#define STOCK_H

#include <string>

class Stock
{
private:
    std::string company;
    long shares;//所持股票数量
    double share_val;//每股价格
    double total_val;//股票总值
    void set_tot() {total_val = shares * share_val;}
public:
    Stock();

    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif // STOCK_H
