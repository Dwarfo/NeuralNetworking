#pragma once
#include <vector>

class NeuralNetwork;

class NNBuilder
{
private:
	int layerNum;
	RandomGenerator* rg;
	NeuralNetwork* NN;
public:
	NNBuilder(int inputSize);
	void AddLayer(bool randValues, int layerSize, Function* function, NeuralNetwork* nn);
	void AddInputLayer(int inputSize, NeuralNetwork* nn);
	NeuralNetwork* GetNetwork();

	~NNBuilder();
};

