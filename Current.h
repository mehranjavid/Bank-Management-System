#pragma once
#include "Checking.h"
class Current: protected Checking
{
	float MinimumBalance;
public:
	Current();
	Current(float, double);
	Current(Current&);
	void setMinimumBalance(float);
	float getMinimumBalance();
};

