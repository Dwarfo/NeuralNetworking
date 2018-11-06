#pragma once
#include <vector>;

class AbstractNeuron;


class Layer
{
public:
	Layer(std::vector<AbstractNeuron*> neuronList);
	std::vector<AbstractNeuron*> neurons;
	int numberOfNeurons;

	void calculateValues();
	void adjustWeights();


	//~Layer();
};
