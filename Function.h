#pragma once
#include <math.h> 

class Function {
public:
	virtual double getValue(double x)=0;
	virtual double getDerivative(double x)=0;
};