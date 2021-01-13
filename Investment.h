#pragma once
#include "Current.h"
class Investment :protected Current
{
	double profitPercent;

public:
	Investment();
	Investment(double, float, double);
	Investment(Investment&);

	double getprofitPercent();
	void setprofitPercent(double);

	virtual void setMinimumBalance(float)=0;
	virtual float getMinimumBalance() = 0;

	virtual double getFee() = 0;
	virtual void setFee(double) = 0;
};

