#pragma once
#include "AbstractNeuron.h"

class HiddenNeuron : public AbstractNeuron {
public:
	HiddenNeuron(Function *function, double Bias);
	void adjustWeights();
	void calculateOutput();


};