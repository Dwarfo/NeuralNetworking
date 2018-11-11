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
	std::list<std::pair<int, Function*>> layerNeuronNum;
	RandomGenerator* rg;
	NeuralNetwork* NN;
	void Build();
	std::vector<AbstractNeuron*> BuildLayer(LayerType type, int layerSize, Function* function );
	Layer* lastAdded;
public:
	NNBuilder(int inputSize);
	void AddLayer(int layerSize, Function* function);
	NeuralNetwork* GetNetwork();
	~NNBuilder();
};
