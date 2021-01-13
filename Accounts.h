#pragma once
#include<string>
#include<iostream>
using namespace std;

class Accounts
{
protected:
	string title;
	long AccNumber;
	double AccBalance;

public:
	Accounts();
	Accounts(Accounts&);
	Accounts(string,long,double);

	string getTitle();
	long getAccNumber();
	double getAccBalance();

	void setTitle(string);
	void setAccNumber(long);
	void setAccBalance(double);

	void deposit(double);
	void withdraw(double);

	void display();

	Accounts& operator=(Accounts& obj);
	bool operator==(Accounts& obj);
	bool operator!=(Accounts& obj);
	ostream& operator << (ostream&);
	istream& operator>>(istream&);

	~Accounts();
};

