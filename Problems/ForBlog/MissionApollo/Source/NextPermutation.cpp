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
	while (desc_itr + 1 != new_perm.rend() && *desc_itr < *(desc_itr + 1)) {
		desc_itr++;
	}
	if (desc_itr + 1 == new_perm.rend()) {
		return IntVector();
	}
	auto eligible = (desc_itr + 2).base();
	auto itr = std::lower_bound(new_perm.rbegin(), desc_itr + 1, *(desc_itr + 1));
	std::iter_swap(eligible, itr);
	std::sort(eligible + 1, new_perm.end());
	return new_perm;
}
