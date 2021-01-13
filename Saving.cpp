#include "Saving.h"

Saving::Saving(): Saving(0.0) {}

Saving::Saving(Saving& obj)
{
	obj.setInterest_Rate(this->getInterest_Rate());
}

Saving::Saving(float x)
{
	Interest_Rate = x;
}

void Saving::setInterest_Rate(float x)
{
	Interest_Rate = x;
}

float Saving::getInterest_Rate()
{
	return Interest_Rate;
}

float Saving::CalculateInterest(double value)
{
	return Interest_Rate / value;
}
