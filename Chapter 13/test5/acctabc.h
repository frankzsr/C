#ifndef ACCTABC_H
#define ACCTABC_H

#include <iostream>
#include <string>

//’xxx‘ has no out-of-line virtual method definitions；
//its vtable will be emitted in every translation unit.
//如果在头文件中定义了一个类并且具有vtable（它具有虚方法或者它来自具有虚方法的类），
//则它必须始终在类中具有至少一个外联虚拟方法。 如果没有这个，编译器会将vtable和RTTI
//复制到每个.o文件中，其中#include标题，膨胀.o文件大小和增加链接时间。

//也就是说，当类中定义了虚函数时，编译器会自动生成虚函数表vtable，用来对应每一个虚函数。
//那么，如果所有虚拟方法都是内联的（在头文件中定义），那么编译器不知道哪个翻译单元（.cpp文件）
//在其中发出vtable，因此它会在所有这些中发出一个副本，并且链接器会处理用它。
//这会在目标文件中产生额外的工作和并且是.o文件变得更庞大。另一方面，
//如果虚拟函数是在线外定义的（在.cpp中），则可以在那里发射vtable，因此只会发出一个副本。

class AcctABC
{
private:
	std::string fullName;
	long acctNum;
	double balance;

protected:
	struct Formating
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string &FullName() const { return fullName; }
	long AcctNum() const { return acctNum; }
	Formating SetFormat() const;
	void Restore(Formating &f) const;

public:
	AcctABC(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;
	double Balance() const { return balance; }
	virtual void ViewAcct() const = 0;
	virtual ~AcctABC();
};

class Brass : public AcctABC
{
public:
	Brass(const std::string &s = "Nullbody", long an = -1,
		  double bal = 0.0) : AcctABC(s, an, bal) {}
	virtual void Withdraw( double amt );
	virtual void ViewAcct() const;
	virtual~Brass() {}
};

class BrassPlus : public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string &s = "Nullbody", long an = -1,
			  double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus(const Brass &ba, double ml = 500, double r = 0.1);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate( double r ) { rate = r; }
	void ResetOwes() { owesBank = 0; }
//	virtual ~BrassPlus() {}
};

#endif // ACCTABC_H
