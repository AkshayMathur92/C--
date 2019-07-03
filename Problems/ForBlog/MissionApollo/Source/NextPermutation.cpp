#include "NextPermutation.h"

void NextPermutation::demo()
{
	IntVector demoVec = { 1,2,3,4 };
	for (int i = 0; i < 24; i++) {
		for (auto &i : demoVec) {
			std::cout << i << " ";
		}
		demoVec = next_perm(demoVec);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::string NextPermutation::demoName()
{
	return R"(NextPermutation
----------------------------)"s;
}

IntVector NextPermutation::next_perm(const IntVector &init){
	IntVector new_perm = IntVector(init);
	auto desc_itr = new_perm.rbegin();
	while (desc_itr + 1 != new_perm.rend() && *desc_itr <= *(desc_itr + 1)) {
		desc_itr++;
	}
	if (desc_itr + 1 == new_perm.rend()) {
		return IntVector();
	}
	auto eligible = (desc_itr + 2).base();
	for (auto itr = new_perm.end() - 1; itr > eligible; itr--) {
		if (*itr > *eligible) {
			std::iter_swap(eligible, itr);
			break;
		}
	}
	std::reverse(eligible + 1, new_perm.end());
	return new_perm;
}
