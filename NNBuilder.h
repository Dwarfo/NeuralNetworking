#pragma once
#include <vector>

class NeuralNetwork;

enum class LayerType
{
	Input, Output, Hidden
};

class NNBuilder
{
private:
	int layerNum;
	RandomGenerator* rg;
	NeuralNetwork* NN;
	void Build();
	std::vector<AbstractNeuron*> BuildLayer(LayerType type, int layerSize, Function* function );
	Layer* lastAdded;
public:
	NNBuilder(int inputSize);
	void AddHiddenLayer(int layerSize, Function* function);
	void AddInputLayer(int inputSize);
	NeuralNetwork* GetNetwork(int layerSize, Function* function);

	~NNBuilder();
};
