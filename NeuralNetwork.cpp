#include "stdafx.h"
#include "NeuralNetwork.h"


void NeuralNetwork::ForwardPropagaion()
{
	for (Layer* l : layers)
	{
		l->calculateValues();
	}
}


void NeuralNetwork::BackPropagation()
{
	for (std::list<Layer* >::reverse_iterator rit = layers.rbegin(); rit != layers.rend(); ++rit)
	{
		(*rit)->adjustWeights();
	}
	for (Connection* con : cons)
	{
		con->applyWeights();
	}
}



void NeuralNetwork::TrainNetwork(std::vector<std::vector<double>> inputs, std::vector<std::vector<double>> outputs)
{
	int j = 0;
	int inputSize = inputLayer->neurons.size();
	int outputSize = outputLayer->neurons.size();

	std::cout << inputSize << " " << outputSize;
	
	for (int i = 0; i < epochs; i++)
	{
		j = 0;
		for (AbstractNeuron* neuron : inputLayer->neurons)
		{
			InputNeuron* in = dynamic_cast<InputNeuron*>(neuron);
			if (inputSize == 1)
			{
				in->netInput = inputs[0][j];
			}
			else
			{
				in->netInput = inputs[i % (4)][j];
			}
			j++;
		}

		ForwardPropagaion();
		
		j = 0;
		for (AbstractNeuron* neuron : outputLayer->neurons)
		{
			OutputNeuron* out = dynamic_cast<OutputNeuron*>(neuron);

			out->trueOutput = outputs[i % (4)][j];

			j++;
		}
		
		BackPropagation();

		for (AbstractNeuron* neuron : outputLayer->neurons)
		{
			OutputNeuron* out = dynamic_cast<OutputNeuron*>(neuron);

			std::cout << "Inputs: " << inputLayer->neurons[0]->Output << " " << inputLayer->neurons[1]->Output << " |  True Out: " << out->trueOutput << " ;Real out: " << out->Output << std::endl;
		}
		
		
		/*
		for (Connection* con : cons)
		{
			std::cout << " " << con->Weight << std::endl;
		}
		BackPropagation();*/
	}
	
}

void NeuralNetwork::GetNeuronNames()
{
	auto nnIterator = layers.begin();

	std::cout << cons.size();
	std::cout << layers.size();

	for (int i = 0; i < layers.size(); i++)
	{
		auto l1 = std::next(nnIterator, i );

		for (AbstractNeuron* neuron1 : (*l1)->neurons)
			std::cout << neuron1->NameSelf();
		//NN->cons.push_back(new Connection(0.5, neuron1, neuron2));

	}
}


NeuralNetwork::NeuralNetwork()
{
	
}


NeuralNetwork::~NeuralNetwork()
{
}
