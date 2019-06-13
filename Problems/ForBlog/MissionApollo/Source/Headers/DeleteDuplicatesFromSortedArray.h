#pragma once
#include "Problem.h"
#include <vector>
class DeleteDuplicatesFromSortedArray : public Problem {
	// Inherited via Problem
	virtual void demo() override;
	virtual std::string demoName() override;
	void delete_duplicate(std::vector<int>* pVecArr);
};