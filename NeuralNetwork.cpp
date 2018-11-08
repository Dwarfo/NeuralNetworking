#include "stdafx.h"
#include "NeuralNetwork.h"


void NeuralNetwork::ForwardPropagaion()
{
	for (Layer* l : layers)
	{
		l->calculateValues();
	}
}

void NeuralNetwork::BackPropagation()
{
	for (Layer* l : layers)
	{
		l->adjustWeights();
	}
	for (Connection* con : cons)
	{
		con->applyWeights();
	}
}

NeuralNetwork::NeuralNetwork()
{
	
}


NeuralNetwork::~NeuralNetwork()
{
}
