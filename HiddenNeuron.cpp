#include "stdafx.h"
#include "HiddenNeuron.h"

HiddenNeuron::HiddenNeuron(Function *function, double Bias) : AbstractNeuron(function, Bias) 
{
}

void HiddenNeuron::adjustWeights()
{
	if (!inputDendrites.empty())
	{
		Delta = 0;

		for (Connection* axon : outputAxons)
		{
			Delta += axon->destination->Delta * axon->Weight;
		}
		Delta = Delta * function->getDerivative(inputSum);

		for (Connection* dendrite : inputDendrites)
		{
			dendrite->adjustWeight(Delta);
		}

		Bias +=  Delta * learningSpeed;
	}
}

void HiddenNeuron::calculateOutput()
{
	inputSum = Bias;

	for(Connection* dendrite : inputDendrites)
	{
		inputSum += dendrite->start->Output * dendrite->Weight;
	}

	Output = function->getValue(inputSum);
}
