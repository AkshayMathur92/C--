#pragma once
#include "Problem.h"
#include <iostream>
#include <vector>
#include <algorithm>
class IncrementArbitraryInteger : public Problem {
	// Inherited via Problem
	virtual std::string getProblemStatement() override;
	virtual std::string getComplexityStatement() override;
	virtual std::string getLearningStatement() override;
	virtual std::string getProblemSolvingStatement() override;
	virtual void demo() override;
private:
	void increment_by_1(std::vector<int> *pVecNumber);
};