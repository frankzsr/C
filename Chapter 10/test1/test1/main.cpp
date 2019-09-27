#include <iostream>
#include "stock.h"

using namespace std;

int main()
{
    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.25);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.buy(300000, 40.1);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(30000, 0.123);
    fluffy_the_cat.show();

    return 0;
}
