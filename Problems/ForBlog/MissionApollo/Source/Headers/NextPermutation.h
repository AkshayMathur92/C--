#pragma once
#include "Problem.h"
#include <vector>
#include <algorithm>

using IntVector = std::vector<int>;

class NextPermutation : public Problem {
	// Inherited via Problem
	virtual void demo() override;
	virtual std::string demoName() override;
private :
	IntVector next_perm(const IntVector &init);
};