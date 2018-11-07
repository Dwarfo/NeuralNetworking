#pragma once
#include <vector>;

class AbstractNeuron;


class Layer
{
public:
	Function* layerFunction;
	Layer(std::vector<AbstractNeuron*> neuronList);
	std::vector<AbstractNeuron*> neurons;
	int numberOfNeurons;

	void calculateValues();
	void adjustWeights();


	//~Layer();
};
