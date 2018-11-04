#pragma once
#include "Function.h";

class Sigmoid : public Function
{
public:
	double getValue(double x);
	double getDerivative(double x);


};