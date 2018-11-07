#include "stdafx.h"
#include "NNBuilder.h"


void NNBuilder::AddInputLayer(int inputSize)
{
	//std::shared_ptr<Layer<InputNeuron>> inputLayer(new Layer<InputNeuron>(inputSize));
	std::vector<AbstractNeuron*> neurons;

	neurons = BuildLayer(LayerType::Input, inputSize, NULL);
	Layer* inputLayer = new Layer(neurons);
	NN->layers.push_back(inputLayer);
	NN->layersNumber++;
	NN->inputLayer = inputLayer;
}

void NNBuilder::Build()
{
	if (layerNum != 0)
	{
		std::vector<AbstractNeuron*> neurons = BuildLayer(LayerType::Output, 1, new Sigmoid());
		Layer* outputLayer = new Layer(neurons);
		NN->outputLayer = outputLayer;
	}
	else
	{
		Function* funk = lastAdded->layerFunction;
		std::vector<AbstractNeuron*> neurons = lastAdded->neurons;

		for (auto neuron : lastAdded->neurons)
		{
			neuron = new OutputNeuron(funk, rg->getValue()));
		}

		Layer* outputLayer = new Layer(neurons);
		NN->outputLayer = outputLayer;
	}

	//TODO connect all neurons
}


std::vector<AbstractNeuron*> NNBuilder::BuildLayer(LayerType type, int layerSize, Function* function)
{
	std::vector<AbstractNeuron*> neurons;

	switch (type)
	{
	case(LayerType::Hidden):
		for (int i = 0; i < layerSize; i++)
		{
			AbstractNeuron * neuron = new HiddenNeuron(function, rg->getValue());
			neurons.push_back(neuron);
		}
		break;

	case(LayerType::Output):
		for (int i = 0; i < layerSize; i++)
		{
			AbstractNeuron * neuron = new OutputNeuron(function, rg->getValue());
			neurons.push_back(neuron);
		}
		break;

	case(LayerType::Input):
		for (int i = 0; i < layerSize; i++)
		{
			AbstractNeuron * neuron = new InputNeuron();
			neurons.push_back(neuron);
		}
		break;

	default:
		break;
	}
	return neurons;
}

NNBuilder::NNBuilder(int inputSize)
{
	NN = new NeuralNetwork();
	rg = new RandomGenerator(0,1);

	layerNum = 0;
	AddInputLayer(inputSize);
}

void NNBuilder::AddHiddenLayer(int layerSize, Function* function)
{
	//std::shared_ptr<Layer<HiddenNeuron>> newLayer(new Layer<HiddenNeuron>(layerSize));
	std::vector<AbstractNeuron*> neurons;

	neurons = BuildLayer(LayerType::Hidden, layerSize, function);
	Layer* newLayer = new Layer(neurons);

	NN->layers.push_back(newLayer);
	NN->layersNumber++;
	lastAdded = newLayer;
	lastAdded->layerFunction = function;
	layerNum++;
}

NeuralNetwork * NNBuilder::GetNetwork(int layerSize, Function * function)
{
	Build();

	return NN;
}


NNBuilder::~NNBuilder()
{
}
