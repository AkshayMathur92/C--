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
	int next_val = arr[0], next_pos = perm[0], next_cycle_at = 1;
	while (next_pos < arr.size()) {
		if (next_cycle_at < processed.size() && processed[next_cycle_at]) {
			next_cycle_at = find_if(processed.begin() + next_cycle_at + 1, processed.end(), [](const bool &b) {return !b; }) - processed.begin();
		}
		int temp = arr[next_pos];
		arr[next_pos] = next_val;
		processed[next_pos] = true;
		next_val = temp;
		next_pos = perm[next_pos];
		if (processed[next_pos]) {
			if (next_cycle_at < arr.size()) {
				next_val = arr[next_cycle_at];
				next_pos = perm[next_cycle_at];
				next_cycle_at++;
			}
			else {
				break;
			}
		}
	}
	return;
}
