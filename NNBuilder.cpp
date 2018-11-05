#include "stdafx.h"
#include "NNBuilder.h"


void NNBuilder::AddInputLayer(int inputSize, NeuralNetwork* nn)
{
	//std::shared_ptr<Layer<InputNeuron>> inputLayer(new Layer<InputNeuron>(inputSize));
	Layer<InputNeuron>* inputLayer = new Layer<InputNeuron>(inputSize);

}

NNBuilder::NNBuilder(int inputSize)
{
	NN = new NeuralNetwork();
	rg = new RandomGenerator();

	AddInputLayer(inputSize, NN);
}

void NNBuilder::AddLayer(bool randValues, int layerSize, Function* function, NeuralNetwork* nn)
{
	//std::shared_ptr<Layer<HiddenNeuron>> newLayer(new Layer<HiddenNeuron>(layerSize));
	Layer<HiddenNeuron>* inputLayer = new Layer<HiddenNeuron>(layerSize);
}

NeuralNetwork* NNBuilder::GetNetwork()
{

	return NN;
}




NNBuilder::~NNBuilder()
{
}
