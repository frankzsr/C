#ifndef BRASS_H
#define BRASS_H

#include <string>

//Brass Account Class
class Brass
{
private:
	std::string fullName; //客户姓名
	long acctNum;//账号
	double balance;//当前余额
public:
	Brass(const std::string &s = "Nullbody", long an = -1,
		  double bal = 0.0);

	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};

//Brass Plus Account Class
class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0,
			  double ml = 500, double r = 0.11125);
	BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);

	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0;}
};

#endif // BRASS_H
