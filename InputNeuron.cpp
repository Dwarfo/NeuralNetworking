#include "stdafx.h"
//#include "InputNeuron.h"

InputNeuron::InputNeuron(Function *function, double Bias) : AbstractNeuron(function, Bias)
{

}

InputNeuron::InputNeuron(double Bias) 
{
	this->Bias = Bias;
	this->Output = 0;
	this->Delta = 0;
	this->learningSpeed = 1;
}


void InputNeuron::adjustWeights()
{

}

void InputNeuron::calculateOutput()
{
	inputSum =  netInput;

	this->Output = inputSum;
}


