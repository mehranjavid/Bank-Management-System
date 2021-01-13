#pragma once
#include "Accounts.h"
class Checking :protected Accounts
{
	double Fee;
public:
	Checking();
	Checking(double);
	Checking(Checking&);
	double getFee();
	void setFee(double);
};

