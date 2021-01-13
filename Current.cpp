#include "Current.h"

Current::Current() : Current(0,0) {}

Current::Current(float val, double val3): Checking(val3)
{
	MinimumBalance = val;
}

Current::Current(Current& obj) : Checking(obj.getFee())
{
	MinimumBalance = obj.MinimumBalance;
}

void Current::setMinimumBalance(float val)
{
	MinimumBalance = val;
}

float Current::getMinimumBalance()
{
	return MinimumBalance;
}
