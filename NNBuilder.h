#pragma once

class NNBuilder
{
private:
	int layerNum;
	RandomGenerator* rg;
	NeuralNetwork* NN;
	void AddInputLayer(int inputSize, NeuralNetwork* nn);
public:
	NNBuilder(int inputSize);
	void AddLayer(bool randValues, int layerSize, Function* function, NeuralNetwork* nn);
	NeuralNetwork* GetNetwork();

	~NNBuilder();
};

