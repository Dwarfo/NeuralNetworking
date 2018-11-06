#pragma once

#include "Connection.h";

class Connection {
public:
	double Weight;
	class AbstractNeuron * start;
	class AbstractNeuron * destination;

	Connection(double Weight, AbstractNeuron *start, AbstractNeuron *destination);

	void adjustWeight(double delta);
	void applyWeights();

private:
	double newWeight;
};