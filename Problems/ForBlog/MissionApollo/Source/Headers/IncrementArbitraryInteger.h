#pragma once
#include "Problem.h"
#include <iostream>
#include <vector>
#include <algorithm>
class IncrementArbitraryInteger : public Problem {
	// Inherited via Problem
	virtual void demo() override;
private:
	void increment_by_1(std::vector<int> *pVecNumber);
};