#include "stdafx.h";
#include "Connection.h";
#include "AbstractNeuron.h";

Connection::Connection(double Weight, AbstractNeuron * start, AbstractNeuron * destination)
{
	this->Weight = Weight;
	this->destination = destination;
	this->start = start;

	destination->addToInputs(this);
	start->addToOutputs(this);
}

Connection::Connection(double Weight, AbstractNeuron * destination)
{

}

void Connection::adjustWeight(double delta)
{
	newWeight = Weight + delta * start->Output * destination->learningSpeed; // add learning rate
}

void Connection::applyWeights()
{
	Weight = newWeight;
}
