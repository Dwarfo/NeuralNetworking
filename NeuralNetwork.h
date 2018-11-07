#pragma once

#include "NNBuilder.h"
#include "OutputNeuron.h"
#include "HiddenNeuron.h"
#include "InputNeuron.h"
#include <map>


class NeuralNetwork
{
private:
	bool debug;
	int layersNumber;
	std::list<Layer* > layers;
	std::map<Connection*, double> weights;
	std::list<Connection* > cons;
	friend void NNBuilder::AddHiddenLayer(int layerSize, Function* function);
	friend void NNBuilder::AddInputLayer(int inputSize);

public:
	void ForwardPropagaion();
	void BackPropagation();
	Layer* inputLayer;
	Layer* outputLayer;
	NeuralNetwork();
	~NeuralNetwork();
};

