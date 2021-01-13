#pragma once
#include "Accounts.h"
class Saving: protected Accounts
{
	float Interest_Rate;
public:
	Saving();
	Saving(Saving&);
	Saving(float);
	void setInterest_Rate(float);
	float getInterest_Rate();
	float CalculateInterest(double);
};

