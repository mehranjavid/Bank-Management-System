#pragma once
#include "Accounts.h"
class Branch :protected Accounts
{
protected:
	Accounts* arraylist;
	int numberOfAcc;
	double totalBalance;

	Accounts* getarraylist();
	int getnumberOfAcc();
	double gettotalBalance();
	 
	void setnumberOfAcc(int);
	void settotalBalance(double);


	void addAccount(Accounts);
	void deleteAccount(string);
	void updateAccount(Accounts);
	void findAccount(long);
	void findAccount(string);

public:

	 bool operator==(Branch& obj);
	ostream& operator << (ostream&);
	istream& operator>>(istream&);
	Branch();
	Branch(Branch&);
	Branch(Accounts*, int, double);

	void menu();

	Branch& operator = (Branch&);

	~Branch();
};