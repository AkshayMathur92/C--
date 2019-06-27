// MissionApollo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "DutchNationalFlagPartioning.h"
#include "IncrementArbitraryInteger.h"
#include "MultipleArbitraryInteger.h"
#include "AdvancingThroughAnArray.h"
#include "DeleteDuplicatesFromSortedArray.h"
#include "BuyingStockOnce.h"
#include "BuyingStockTwice.h"
#include "Sieve of Eratosthenes.h"
#include "ApplyPermutation.h"

int main()
{
	vector<std::unique_ptr<Problem>> problems;
	problems.emplace_back(std::unique_ptr<Problem>(new DutchNationalFlagPartioning()));
	problems.emplace_back(std::unique_ptr<Problem>(new IncrementArbitraryInteger()));
	problems.emplace_back(std::unique_ptr<Problem>(new MultiplyArbitraryInteger()));
	problems.emplace_back(std::unique_ptr<Problem>(new AdvancingThroughAnArray()));
	problems.emplace_back(std::unique_ptr<Problem>(new DeleteDuplicatesFromSortedArray()));
	problems.emplace_back(std::unique_ptr<Problem>(new BuyingStockOnce()));
	problems.emplace_back(std::unique_ptr<Problem>(new BuyingStockTwice()));
	problems.emplace_back(std::unique_ptr<Problem>(new SieveOfEratosthenes()));
	problems.emplace_back(std::unique_ptr<Problem>(new ApplyPermutation()));
	for (auto &problem : problems) {
		problem.get()->runDemo();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
