#pragma once
#include "Problem.h"
#include <vector>
#include <algorithm>
#include <iostream>
class MultiplyArbitraryInteger : public Problem {
	// Inherited via Problem
	virtual void demo() override;
private:
	int get_digit_with_offset(const std::vector<int> &arr, const int &offset, const int &index);

	std::vector<int> add_vectors_with_offsets(const std::vector<std::vector<int>> &sums);

	std::vector<int> multiply_vector_to_digit(const std::vector<int> &arr, const int &i);

	std::vector<int> multiply(const std::vector<int>& b1, const std::vector<int> &b2);
};