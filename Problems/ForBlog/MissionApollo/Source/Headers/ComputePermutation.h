#pragma once
#include "Problem.h"
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

class ComputePermutation : public Problem {
	// Inherited via Problem
	virtual void demo() override;
	virtual std::string demoName() override;
private:
	std::vector<int> compute(int);
};