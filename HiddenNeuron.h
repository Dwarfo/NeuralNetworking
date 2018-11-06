#pragma once
#include "AbstractNeuron.h"
#include <string>

class HiddenNeuron : public AbstractNeuron {
public:
	HiddenNeuron(Function *function, double Bias);
	void adjustWeights();
	void calculateOutput();
	std::string NameSelf();

};