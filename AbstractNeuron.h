#pragma once
#include "Function.h"
#include "Connection.h"
#include <list>;

class AbstractNeuron
{
public:
	AbstractNeuron(Function *function, double Bias);

	double Bias;
	double Delta;
	double Output;
	double learningSpeed;
	virtual void calculateOutput() = 0;
	virtual void adjustWeights() = 0;
	void addToInputs(Connection* connection);
	void addToOutputs(Connection* connection);
	std::list<Connection* > inputDendrites;
	std::list<Connection* > outputAxons;

protected:
	double inputSum;
	Function * function;
};