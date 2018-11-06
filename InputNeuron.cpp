#include "stdafx.h"
//#include "InputNeuron.h"
#include <iostream>

InputNeuron::InputNeuron(Function *function, double Bias) : AbstractNeuron(function, Bias)
{

}

InputNeuron::InputNeuron() 
{
	this->Bias = 0;
	this->Output = 0;
	this->Delta = 0;
	this->learningSpeed = 1;
}

std::string InputNeuron::NameSelf() 
{
	return "Input";
}

void InputNeuron::adjustWeights()
{

}

void InputNeuron::calculateOutput()
{
	inputSum =  netInput;

	this->Output = inputSum;
}


