#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Neuron functioning", "[Neuron]")
{
	double X[4][2] = {
		{ 0, 0 },
	{ 0, 1 },
	{ 1, 0 },
	{ 1, 1 }
	};

	double Y[4] = { 0,1,1,0 };

	auto sigm = new Sigmoid();
	auto testNeuron = new HiddenNeuron(sigm, 0);

	testNeuron->calculateOutput();

	CHECK(sigm->getValue(0) == 0.5);
	REQUIRE(testNeuron->Output == sigm->getValue(0));

	testNeuron->Bias = 0.78;
	testNeuron->calculateOutput();
	REQUIRE(testNeuron->Output == sigm->getValue(0.78));


}