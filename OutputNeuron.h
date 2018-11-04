#pragma once
#include "AbstractNeuron.h"
class OutputNeuron : public AbstractNeuron
{
public:
	double trueOutput;
	OutputNeuron(Function* function, double Bias);
	void adjustWeights();
	void calculateOutput();
};

