#pragma once
#include <map>

class NeuralNetwork
{
private:
	bool debug;
	int layersNumber;
	std::list<Layer<AbstractNeuron>> _layers;
	std::map<Connection*, double> weights;
	std::list<Connection* > cons;
	//friend void NNBuilder::AddLayer(bool randValues, int layerSize, Function* function, NeuralNetwork* nn);
	//friend void NNBuilder::AddInputLayer(int inputSize, NeuralNetwork* nn);

public:
	void ForwardPropagaion();
	void BackPropagation();
	NeuralNetwork();
	~NeuralNetwork();
};

