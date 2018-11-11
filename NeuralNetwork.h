#pragma once

#include "NNBuilder.h"
#include "OutputNeuron.h"
#include "HiddenNeuron.h"
#include "InputNeuron.h"
#include <map>
#include <vector>

class NNBuilder;

class NeuralNetwork
{
	friend class NNBuilder;
private:
	int currentEpoch = 0;
	bool debug;
	int layersNumber;
	std::list<Layer* > layers;
	std::map<Connection*, double> weights;
	//friend void NNBuilder::AddHiddenLayer(int layerSize, Function* function);
	//friend void NNBuilder::AddInputLayer(int inputSize);

public:
	int epochs;
	void ForwardPropagaion();
	void BackPropagation();
	void TrainNetwork(std::vector<std::vector<double>> inputs, std::vector<std::vector<double>> outputs);
	std::list<Connection* > cons;
	Layer* inputLayer;
	Layer* outputLayer;

	void GetNeuronNames();
	NeuralNetwork();
	~NeuralNetwork();
};

