#include "stdafx.h"
#include "AbstractNeuron.h"

AbstractNeuron::AbstractNeuron()
{
}

AbstractNeuron::AbstractNeuron(Function *function, double Bias)
{
	this->function = function;
	this->Bias = Bias;
	this->Output = 0;
	this->Delta = 0;
	this->learningSpeed = 1;
}

void AbstractNeuron::addToInputs(Connection * connection)
{
	this->inputDendrites.push_back(connection);
}

void AbstractNeuron::addToOutputs(Connection * connection)
{
	this->outputAxons.push_back(connection);
}
