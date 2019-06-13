#pragma once
#include "Problem.h"
#include <vector>
#include <algorithm>
class IncrementArbitraryInteger : public Problem {
	// Inherited via Problem
	virtual void demo() override;
private:
	void increment_by_1(std::vector<int> *pVecNumber);

	// Inherited via Problem
	virtual std::string demoName() override;
};