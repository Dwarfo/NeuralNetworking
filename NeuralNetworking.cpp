// NeuralNetworking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

int main()
{
	// Simple realization of network of 3 neurons( + 2 input nodes) capable of solving XOR problem
	/*
	RandomGenerator* rg = new RandomGenerator(0, 1);
	Sigmoid sigmoidFunction;
	Sigmoid* sigmoid = &sigmoidFunction;

	Layer<InputNeuron> inputLayer(2, rg);
	Layer<HiddenNeuron> hiddenLayer(2, rg);
	Layer<OutputNeuron> outputLayer(1, rg);


	std::list<Connection* > cons;

	double X[4][2] = {
	{ 0, 0 },
	{ 0, 1 },
	{ 1, 0 },
	{ 1, 1 }
	};

	double Y[4] = { 0,1,1,0 };

	int epochs = 3000;
	int current = 0;

	//inputLayer.buildIn(sigmoid);
	//hiddenLayer.build(sigmoid);
	//outputLayer.buildOut(sigmoid);

	for (AbstractNeuron *neuron1 : inputLayer.neurons)
		for (AbstractNeuron *neuron2 : hiddenLayer.neurons)
		{
			Connection* co = new Connection(rg->getValue(), neuron1, neuron2);
			cons.push_back(co);
		}

	for (AbstractNeuron *neuron1 : hiddenLayer.neurons)
		for (AbstractNeuron *neuron2 : outputLayer.neurons)
		{
			Connection* co = new Connection(rg->getValue(), neuron1, neuron2);
			cons.push_back(co);
		}

	while (epochs > 0)
	{
		for (int i = 0; i < 2; i++)
		{
			inputLayer.neurons.at(i)->netInput = X[current][i];
		}

		inputLayer.calculateValues();
		hiddenLayer.calculateValues();
		outputLayer.calculateValues();

		for (OutputNeuron* neuron : outputLayer.neurons)
		{
			neuron->trueOutput = Y[current];
			neuron->adjustWeights();
		}

		for (HiddenNeuron* neuron : hiddenLayer.neurons)
		{
			neuron->adjustWeights();
		}

		for (Connection *con : cons)
			con->applyWeights();

		std::cout << "Input Values: " << inputLayer.neurons.at(0)->Output << " " << inputLayer.neurons.at(1)->Output << std::endl;
		std::cout << "True out = " << Y[current] << std::endl;
		std::cout << "Actual out " << outputLayer.neurons.at(0)->Output << std::endl;

		current++;
		if (current > 3)
			current = 0;

		epochs--;

	}



	
	std::getchar();

    return 0;*/
	std::vector<std::vector<double>> input = { {0,0}, {0,1}, {1,0}, {1,1} };
	std::vector<std::vector<double>> output = { {0},{1},{1},{0} };

	Sigmoid* sigm = new Sigmoid();
	NNBuilder* builder = new NNBuilder(2);
	builder->AddLayer(2, sigm);
	builder->AddLayer(1, sigm);
	auto NN = builder->GetNetwork();

	NN->epochs = 6000;
	NN->TrainNetwork(input, output);

	//NN->GetNeuronNames();
	/*
	OutputNeuron* out = dynamic_cast<OutputNeuron*>(NN->outputLayer->neurons[0]);
	out->trueOutput = 1;
	
	std::cout << "out->trueOutput: " << out->trueOutput;
	*/

	std::getchar();
	return 0;
}

