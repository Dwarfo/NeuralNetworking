#include "stdafx.h"
#include "RandomGenerator.h"


RandomGenerator::RandomGenerator(double lowerValue, double higherValue)
{
	std::random_device rd;
	std::mt19937 randomDevice(rd());
	std::uniform_real_distribution<double> dist(lowerValue, higherValue);
}

double RandomGenerator::getValue()
{
	return dist(randomDevice);
}


RandomGenerator::~RandomGenerator()
{
}
