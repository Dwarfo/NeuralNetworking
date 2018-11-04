#pragma once
#include "AbstractNeuron.h"

class InputNeuron : public AbstractNeuron
{
public:
	double netInput;
	InputNeuron(Function *function, double Bias);
	InputNeuron(double Bias);

	void adjustWeights();
	void calculateOutput();
};

