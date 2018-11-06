#include "stdafx.h"
#include "Layer.h"


Layer::Layer(std::vector<AbstractNeuron*> neuronList)
{
	neurons = neuronList;

}


void Layer::calculateValues()
{
	for (auto neuron : neurons)
		neuron->calculateOutput();
}


void Layer::adjustWeights()
{
	for (auto neuron : neurons)
		neuron->adjustWeights();
}