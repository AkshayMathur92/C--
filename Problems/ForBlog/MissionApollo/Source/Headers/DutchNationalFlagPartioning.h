#pragma once
#include "Problem.h"
#include <vector>
using namespace std;

class DutchNationalFlagPartioning :
	public Problem
{
	void dutch_national_partitioning(vector<int>* A_ptr, const int & i);
public:
	DutchNationalFlagPartioning();
	~DutchNationalFlagPartioning();

	// Inherited via Problem
	void demo() override;
	virtual std::string demoName() override;

};

