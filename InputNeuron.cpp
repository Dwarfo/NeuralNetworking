#include "stdafx.h"
#include "InputNeuron.h"


InputNeuron::InputNeuron(Function *function, double Bias) : AbstractNeuron(function, Bias)
{
}


void InputNeuron::adjustWeights()
{

}

void InputNeuron::calculateOutput()
{
	inputSum =  netInput;

	this->Output = inputSum;
}


