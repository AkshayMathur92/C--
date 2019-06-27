#include "BuyingStockOnce.h"

void BuyingStockOnce::demo()
{
	std::vector<int> arr = { 80,85,45,65,30,40,60,0,25,20 };
	std::cout << get_max_profit(arr) << std::endl;
}

std::string BuyingStockOnce::demoName()
{
	return R"(BuyingStockOnce
------------------------------)"s;
}

int BuyingStockOnce::get_max_profit(const std::vector<int>& arr)
{
	if (arr.empty()|| arr.size() < 2)
		return 0;
	auto local_min = arr.begin();
	auto itr = arr.begin() + 1;
	int max_profit = 0;
	while (itr != arr.end()) {
		max_profit = std::max(max_profit, *itr - *local_min);
		if (*itr < *local_min && itr + 1 != arr.end() && *(itr - 1) > *itr && (*itr + 1) > * itr) {
			local_min = itr;
		}
		itr++;
	}
	return max_profit;
}
