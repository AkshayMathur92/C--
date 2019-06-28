#include "ApplyPermutation.h"

void ApplyPermutation::demo()
{
	IntVector demovector = { 1,2,3,4,5 };
	IntVector permVector = { 2,0,1,4,3 };
	apply(&demovector, permVector);
	for (auto &i : demovector) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	demovector = { 1,2,3,4,5 };
	permVector = { 2,0,1,3,4 };
	apply(&demovector, permVector);
	for (auto &i : demovector) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

std::string ApplyPermutation::demoName()
{
	return R"(ApplyPermutation
----------------------------)"s;
}

void ApplyPermutation::apply(IntVector* parr, const IntVector& perm)
{
	IntVector &arr = *parr;
	if (arr.size() < 2) {
		return;
	}
	BoolVector processed(arr.size(), false);
	for (int i = 0; i < arr.size(); i++) {
		int next_pos = i;
		while (!processed[next_pos]) {
			std::swap(arr[perm[next_pos]], arr[next_pos]);
			processed[perm[next_pos]] = true;
			next_pos = perm[next_pos];
		}
	}
	
	return;
}
