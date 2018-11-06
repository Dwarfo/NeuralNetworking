#pragma once
#include "AbstractNeuron.h"
#include <string>

class OutputNeuron : public AbstractNeuron
{
public:
	double trueOutput;
	OutputNeuron(Function* function, double Bias);
	void adjustWeights();
	void calculateOutput();
	std::string NameSelf();
};

