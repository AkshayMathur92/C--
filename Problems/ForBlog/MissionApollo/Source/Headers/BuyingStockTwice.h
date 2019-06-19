#pragma once
#include "Problem.h"
#include <vector>
#include <algorithm>
#include <iostream>
class BuyingStockTwice :public Problem {
	// Inherited via Problem
	virtual void demo() override;
	virtual std::string demoName() override;
private:
	int get_max_profit(const std::vector<int> &arr);
};
