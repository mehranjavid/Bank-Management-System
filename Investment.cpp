#include "Investment.h"

Investment::Investment(): Investment(0,0,0)
{}

Investment::Investment(double val, float val2, double val3) : Current(val2, val3)
{
	profitPercent = val;
}

Investment::Investment(Investment& obj): Current(obj.getMinimumBalance(), obj.getFee())
{
	profitPercent = obj.profitPercent;
}

double Investment::getprofitPercent()
{
	return profitPercent;
}

void Investment::setprofitPercent(double val)
{
	profitPercent = val;
}
