#pragma once
#include "Problem.h"
#include <vector>
#include <algorithm>

using BoolVector = std::vector<bool>;
using IntVector = std::vector<int>;

class ApplyPermutation : public Problem {
	// Inherited via Problem
	virtual void demo() override;
	virtual std::string demoName() override;
	void apply(IntVector *arr, const IntVector& p);
};