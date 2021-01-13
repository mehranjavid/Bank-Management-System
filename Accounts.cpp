#include "Accounts.h"

void Accounts::deposit(double value)
{
		AccBalance += value;
}

void Accounts::withdraw(double value)
{
	if (value > AccBalance)
	{
		AccBalance -= value;
	}
	else
	{
		cout << "insufficient balance";
	}
}

Accounts::~Accounts()
{
}

Accounts::Accounts(): Accounts("",0,0)
{}

Accounts::Accounts(Accounts& obj)
{
	title = obj.title;
	AccNumber = obj.AccNumber;
	AccBalance = obj.AccBalance;
}

Accounts::Accounts(string name, long an, double ab)
{
	title = name;
	an = AccNumber;
	ab = AccBalance;
}

string Accounts::getTitle()
{
	return title;
}

long Accounts::getAccNumber()
{
	return AccNumber;
}

double Accounts::getAccBalance()
{
	return AccBalance;
}

void Accounts::setTitle(string name)
{
	title = name;
}

void Accounts::setAccNumber(long val)
{
	AccNumber = val;
}

void Accounts::setAccBalance(double val)
{
	AccBalance = val;
}

void Accounts::display()
{
	cout << "\nTitle " << title << ";Account number " << AccNumber <<
		";Account balance " << AccBalance;
}

Accounts& Accounts::operator=(Accounts& obj)
{
	this->title = obj.getTitle();
	this->AccNumber = obj.AccNumber;
	this->AccBalance= obj.AccBalance;
	return *this;
}

bool Accounts::operator==(Accounts& obj)
{
	if(this->title == obj.getTitle())
		if (this->AccNumber = obj.AccNumber) {

			if (this->AccBalance = obj.AccBalance)
			{
				return true;
			}
		}
	return false;
}


bool Accounts::operator!=(Accounts& obj)
{
	if (*this == obj)
	{
		return false;
	}
	return true;
}

ostream& Accounts::operator<<(ostream& fout) {
	fout <<"\nTitle; "<< title
		<< "\nAccount Number;" << AccNumber
		<< "\nAccount Balance;" <<AccBalance<<endl;
	return fout;
}

istream& Accounts::operator>>(istream& fin)
{
	fin >> title >> AccNumber; 
		fin >> AccBalance;
		return fin;
}
