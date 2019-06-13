#pragma once
#include "Problem.h"
#include <vector>
#include <algorithm>

class AdvancingThroughAnArray : public Problem {
	// Inherited via Problem
	virtual void demo() override;
	virtual std::string demoName() override;
private:
	bool can_advance(std::vector<int> arr);
};