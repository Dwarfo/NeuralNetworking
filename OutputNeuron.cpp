#include "stdafx.h"
#include "OutputNeuron.h"
#include <iostream>


OutputNeuron::OutputNeuron(Function *function, double Bias) : AbstractNeuron(function,Bias)
{
}

void OutputNeuron::adjustWeights()
{
	Delta = function->getDerivative(inputSum) * (trueOutput - Output);
	std::cout << "Delta: " << Delta << std::endl;
	for(Connection *dendrite : inputDendrites)
	{
		dendrite->adjustWeight(Delta);
	}
	Bias += Delta * learningSpeed;
}

void OutputNeuron::calculateOutput()
{
	inputSum = Bias;
	for(Connection *dendrite : inputDendrites)
	{
		inputSum += dendrite->start->Output * dendrite->Weight;
	}

	Output = function->getValue(inputSum);
}


