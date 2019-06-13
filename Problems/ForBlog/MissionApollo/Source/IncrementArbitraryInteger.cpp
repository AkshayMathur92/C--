#include "IncrementArbitraryInteger.h"

std::string IncrementArbitraryInteger::getProblemStatement()
{
	return "Write a program that takes an array of digits encoding a decimal number D and updates the array to represent the number D+1.";
}

std::string IncrementArbitraryInteger::getComplexityStatement()
{
	return std::string();
}

std::string IncrementArbitraryInteger::getLearningStatement()
{
	return std::string();
}

std::string IncrementArbitraryInteger::getProblemSolvingStatement()
{
	return std::string();
}

void IncrementArbitraryInteger::demo()
{
	std::vector<int> given_number = { 1,2,9 };
	increment_by_1(&given_number);
	for (auto&i : given_number) {
		std::cout << i;
	}
	std::cout << std::endl;
	given_number = { 9 };
	increment_by_1(&given_number);
	for (auto&i : given_number) {
		std::cout << i;
	}
	std::cout << std::endl;
	given_number = { 0 };
	increment_by_1(&given_number);
	for (auto&i : given_number) {
		std::cout << i;
	}
	std::cout << std::endl;
	given_number = { 9,9,9 };
	increment_by_1(&given_number);
	for (auto&i : given_number) {
		std::cout << i;
	}
}

void IncrementArbitraryInteger::increment_by_1(std::vector<int> *pVecNumber) {
	std::vector<int> &vec_number = *pVecNumber;
	auto itr = vec_number.rbegin();
	while ( itr != vec_number.rend()) {
		if (*itr != 9) {
			*itr = *itr + 1;
			return;
		}
		*itr = 0;
		itr++;
	}
	vec_number.insert(vec_number.begin(), 1);
}

