#pragma once
#include "Problem.h"
#include <vector>

class OfflineSampling : public Problem {
	// Inherited via Problem
	virtual void demo() override;
	virtual std::string demoName() override;
	void RandomSampling(std::vector<int>* parr, int k);
};