#pragma once
class RandomGenerator
{
public:
	RandomGenerator(double lowerValue, double higherValue);
	double getValue();
	std::mt19937 randomDevice;
	std::uniform_real_distribution<double> dist;
	~RandomGenerator();
};

