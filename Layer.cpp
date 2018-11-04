#include "stdafx.h"
/*#include "Layer.h"

template <class T>
Layer<T>::Layer(int numberOfNeurons, RandomGenerator* rg)
{
	this->numberOfNeurons = numberOfNeurons;
	this->rg = rg;
}

template <class T>
void Layer<T>::build(Function* function)
{
	if (!neurons.empty())
	{
		for (int i = 0; i < numberOfNeurons; i++)
			neurons.push_back(new HiddenNeuron(function, rg->getValue()));
	}
}

template <class T>
void Layer<T>::buildOut(Function *function)
{
	if (!neurons.empty())
	{
		for (int i = 0; i < numberOfNeurons; i++)
			neurons.push_back(new OutputNeuron(function, rg->getValue()));
	}
}

template <class T>
void Layer<T>::buildIn(Function *function)
{
	if (!neurons.empty())
	{
		for (int i = 0; i < numberOfNeurons; i++)
			neurons.push_back(new InputNeuron(function, rg->getValue()));
	}
}

template <class T>
void Layer<T>::calculateValues()
{
	for (AbstractNeuron* neuron : neurons)
		neuron->calculateOutput();
}

template <class T>
void Layer<T>::adjustWeights()
{
	for (AbstractNeuron* neuron : neurons)
		neuron->adjustWeights();
}


template <class T>
Layer<T>::~Layer()
{
}
*/