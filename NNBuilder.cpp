#include "stdafx.h"
#include "NNBuilder.h"


void NNBuilder::AddInputLayer(int inputSize, NeuralNetwork* nn)
{
	//std::shared_ptr<Layer<InputNeuron>> inputLayer(new Layer<InputNeuron>(inputSize));
	std::vector<AbstractNeuron*> neurons;

	for (int i = 0; i < inputSize; i++)
	{
		InputNeuron* neuron = new InputNeuron();
		AbstractNeuron* newNeuron = neuron;
		neurons.push_back(newNeuron);
	}
	Layer* inputLayer = new Layer(neurons);
	nn->inputLayer = inputLayer;
}

NNBuilder::NNBuilder(int inputSize)
{
	NN = new NeuralNetwork();
	rg = new RandomGenerator(0,1);

	AddInputLayer(inputSize, NN);
}

void NNBuilder::AddLayer(bool randValues, int layerSize, Function* function, NeuralNetwork* nn)
{
	//std::shared_ptr<Layer<HiddenNeuron>> newLayer(new Layer<HiddenNeuron>(layerSize));
	//Layer<HiddenNeuron>* newLayer = new Layer(layerSize);
	//nn->layers.push_back(newLayer);
}

NeuralNetwork* NNBuilder::GetNetwork()
{

	return NN;
}




NNBuilder::~NNBuilder()
{
}
