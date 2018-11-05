#pragma once
#include <vector>;

template <class T>
class Layer
{
	static_assert(std::is_base_of<AbstractNeuron, T>::value, "T must be a Neuron type");
public:
	Layer(int numberOfNeurons);
	std::vector<T*> neurons;
	int numberOfNeurons;

	void calculateValues();
	void adjustWeights();


	//~Layer();
};


template <class T>
Layer<T>::Layer(int numberOfNeurons)
{
	this->numberOfNeurons = numberOfNeurons;
	for (int i = 0; i < numberOfNeurons; i++)
	{
		neurons.push_back(T);
	}
}

template <class T>
void Layer<T>::calculateValues()
{
	for (auto neuron : neurons)
		neuron->calculateOutput();
}

template <class T>
void Layer<T>::adjustWeights()
{
	for (auto neuron : neurons)
		neuron->adjustWeights();
}

