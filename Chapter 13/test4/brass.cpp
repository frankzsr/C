#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const std::string &s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

//创建账户
void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed; "
			 << "deposit is cancelled.\n";
	else {
		balance += amt;
	}
}

//取款
void Brass::Withdraw(double amt)
{
	printf("Brass\n");
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if (amt < 0)
	{
		cout << "Withdrawl amount must be positive; "
			 << "withdrawl canceled.\n";
	}
	else if (amt <= balance)
		balance -= amt;
	else {
		cout << "Withdrawl amount of $" << amt
			 << " exceeds your balance.\n"
			 << "Withdrawl canceled.\n";
	}
	restore(initialState, prec);
}

//
double Brass::Balance() const
{
	return balance;
}

//显示账户信息
void Brass::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << fullName << endl;
	cout << "Account Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
	restore(initialState, prec);
}

BrassPlus::BrassPlus(const std::string &s, long an, double bal,
					 double ml, double r) : Brass (s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : Brass (ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();

	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3); //###.### format
	cout << "Loan Rate: $" << 100 * rate << "%\n";
	restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt)
{
	printf("BrassPlus\n");
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
	{
		Brass::Withdraw(amt);
	} else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Bank adcance: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else {
		cout << "Credit limit exceeded. Transaction cancelled.\n";
	}
	restore(initialState, prec);
}

format setFormat()
{
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}
