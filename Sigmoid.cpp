#include "stdafx.h"
#include "Sigmoid.h"

double Sigmoid::getValue(double x)
{
	return 1 / (1 + exp(-x));
}

double Sigmoid::getDerivative(double x)
{
	return getValue(-x) * (1 - getValue(-x));
}
