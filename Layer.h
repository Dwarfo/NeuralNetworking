#pragma once
#include <vector>;

template <class T>
class Layer
{
	static_assert(std::is_base_of<AbstractNeuron, T>::value, "T must be a Neuron type");
public:
	Layer(int numberOfNeurons, RandomGenerator* rg);
	std::vector<T* > neurons;
	int numberOfNeurons;
	void build(Function *function);
	void buildOut(Function *function);
	void buildIn(Function *function);

	void calculateValues();
	void adjustWeights();
	RandomGenerator* rg;


	//~Layer();
};

template <class T>
Layer<T>::Layer(int numberOfNeurons, RandomGenerator* rg)
{
	this->numberOfNeurons = numberOfNeurons;
	this->rg = rg;
}

template <class T>
void Layer<T>::build(Function* function)
{
	if (neurons.empty())
	{
		for (int i = 0; i < numberOfNeurons; i++)
			neurons.push_back(new HiddenNeuron(function, rg->getValue()));
	}
}

template <class T>
void Layer<T>::buildOut(Function *function)
{
	if (neurons.empty())
	{
		for (int i = 0; i < numberOfNeurons; i++)
			neurons.push_back(new OutputNeuron(function, rg->getValue()));
	}
}

template <class T>
void Layer<T>::buildIn(Function *function)
{
	if (neurons.empty())
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