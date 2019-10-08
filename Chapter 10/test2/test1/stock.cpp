#include "stock.h"
#include <iostream>

Stock::Stock()
{
	std::cout << "Default constructor called\n";

	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const string & co, long n, double pr)
{
	std::cout << "Constructor using " << co << " called\n";
	company = co;

	if (n < 0)
	{
		std::cerr << "Number of shares can't be negative; "
				  << company << " shares set to 0.\n";

		shares = 0;
	}
	else {
		shares = n;
	}

	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	std::cout << "bye, " << company << "!\n";
}

/*
void Stock::acquire(const std::string &co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}
*/

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Numbers of shares purchased can't be negative. "
                  << "Transation is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transation is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transation is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    /*
    std::cout << "Company: " << company
              << " Shares: " << shares << '\n'
              << " Share Price: $" << share_val
              << " Total Worth: $" << total_val << '\n';
    */
    using std::cout;
    using std::ios_base;

    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    std::cout << "Company: " << company
              << " Shares: " << shares << '\n';
         cout << " Share Price: $" << share_val;

    cout.precision(2);
    cout << " Total worth: $" << total_val << '\n';

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}
