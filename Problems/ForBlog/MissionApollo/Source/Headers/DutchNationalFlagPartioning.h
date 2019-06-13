#pragma once
#include "Problem.h"
#include <vector>
#include <iostream>
using namespace std;

class DutchNationalFlagPartioning :
	public Problem
{
	void dutch_national_partitioning(vector<int>* A_ptr, const int & i);
public:
	DutchNationalFlagPartioning();
	~DutchNationalFlagPartioning();

	// Inherited via Problem
	std::string getProblemStatement() override;
	std::string getComplexityStatement() override;
	std::string getLearningStatement() override;
	std::string getProblemSolvingStatement() override;
	void demo() override;
};

