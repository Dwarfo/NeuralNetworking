#pragma once
#include "AbstractNeuron.h"

class InputNeuron : public AbstractNeuron
{
public:
	double netInput;
	InputNeuron(Function *function, double Bias);
	InputNeuron();

	std::string NameSelf();
	void adjustWeights();
	void calculateOutput();
};

