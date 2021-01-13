#include "Checking.h"

Checking::Checking(): Checking(0) {}

Checking::Checking(double value)
{
	Fee = value;
}

Checking::Checking(Checking& obj)
{
	this->Fee = obj.Fee;
}

double Checking::getFee()
{
	return Fee;
}

void Checking::setFee(double value)
{
	Fee = value;
}
