#include "AdvancingThroughAnArray.h"

void AdvancingThroughAnArray::demo()
{
	std::vector<int> demoarr = { 3,3,1,0,2,0,1 };
	std::cout << "Can Advance "  << can_advance(demoarr) << std::endl;
	demoarr = { 3,2,0,0,2,0,1 };
	std::cout << "Can Advance " << can_advance(demoarr) << std::endl;
}



std::string AdvancingThroughAnArray::demoName()
{
	return R"(AdvancingThroughAnArray
----------------------------)"s;
}

bool AdvancingThroughAnArray::can_advance(std::vector<int> arr)
{
	if (arr.empty()) {
		return true;
	}
	unsigned int max_reach = arr[0];
	for (int i = 0; i <= max_reach && i < arr.size() && max_reach <= arr.size(); i++) {
		max_reach = std::max<int>(i + arr[i], max_reach);
	}
	if (max_reach >= arr.size())
		return true;
	return false;
}
