#pragma once
#include "Problem.h"
#include <vector>
#include <numeric>

class SieveOfEratosthenes : public Problem {
	// Inherited via Problem
	virtual void demo() override;
	virtual std::string demoName() override;

	void print_primes(unsigned int n);
};


