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
	testNeuron->Bias = 0;

}

TEST_CASE("Input-hidden-Output weights logic", "[Neuron]")
{
	double X[2] = { 0,1 };
	double Y[2] = { 0,1 };

	std::list<Connection* > cons;

	auto sigm = new Sigmoid();

	auto testNeuron = new HiddenNeuron(sigm, 0);
	auto outNeuron = new OutputNeuron(sigm, 0);
	auto inNeuron = new InputNeuron(sigm, 0);

	auto testConnection1 = new Connection(0.5, inNeuron, testNeuron);
	cons.push_back(testConnection1);
	auto testConnection2 = new Connection(0.5, testNeuron, outNeuron);
	cons.push_back(testConnection2);

	inNeuron->netInput = X[0];
	inNeuron->calculateOutput();
	testNeuron->calculateOutput();
	outNeuron->calculateOutput();
	outNeuron->trueOutput = Y[0];


	REQUIRE(inNeuron->Output == 0);
	REQUIRE(testNeuron->Output == 0.5);
	REQUIRE(outNeuron->Output == sigm->getValue(0.25));

	outNeuron->adjustWeights();
	testNeuron->adjustWeights();

	testConnection2->applyWeights();

	REQUIRE(testConnection2->Weight == (0.5 + testNeuron->Output*sigm->getDerivative(testNeuron->Output * 0.5) * (outNeuron->trueOutput - outNeuron->Output)));

	testConnection1->applyWeights();
	REQUIRE(testConnection1->Weight == (0.5 + inNeuron->Output * sigm->getDerivative(inNeuron->Output * 0.5) * (outNeuron->Delta * testConnection2->Weight)));
}

SCENARIO("Three neurons are connected with an input value of 0, and desired of 0 as well")
{
	double X[2] = { 0,1 };
	double Y[2] = { 0,1 };

	std::list<Connection* > cons;

	auto sigm = new Sigmoid();

	auto testNeuron = new HiddenNeuron(sigm, 0);
	auto outNeuron = new OutputNeuron(sigm, 0);
	auto inNeuron = new InputNeuron(sigm, 0);

	auto testConnection1 = new Connection(0.5, inNeuron, testNeuron);
	cons.push_back(testConnection1);
	auto testConnection2 = new Connection(0.5, testNeuron, outNeuron);
	cons.push_back(testConnection2);

	WHEN("neurons are connected and values are forward propagated")
	{
		inNeuron->netInput = X[0];
		inNeuron->calculateOutput();
		testNeuron->calculateOutput();
		outNeuron->calculateOutput();
		outNeuron->trueOutput = Y[0];

		REQUIRE(inNeuron->Output == 0);
		REQUIRE(testNeuron->Output == 0.5);
		REQUIRE(outNeuron->Output == sigm->getValue(0.25));

		THEN("and then back propagated with desired new weights")
		{
			outNeuron->adjustWeights();
			testNeuron->adjustWeights();

			testConnection2->applyWeights();

			REQUIRE(testConnection2->Weight == (0.5 + testNeuron->Output*sigm->getDerivative(testNeuron->Output * 0.5) * (outNeuron->trueOutput - outNeuron->Output)));

			testConnection1->applyWeights();
			REQUIRE(testConnection1->Weight == (0.5 + inNeuron->Output * sigm->getDerivative(inNeuron->Output * 0.5) * (outNeuron->Delta * testConnection2->Weight)));
		}
	}


}



