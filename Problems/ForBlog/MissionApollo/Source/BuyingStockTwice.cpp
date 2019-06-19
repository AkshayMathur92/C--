#include "BuyingStockTwice.h"

void BuyingStockTwice::demo()
{
	std::vector<int> arr = { 12, 11, 13, 9, 12, 8, 14, 13, 15 };
	std::cout << get_max_profit(arr) << std::endl;
	arr = { 2, 30, 15, 10, 8, 25, 80 };
	std::cout << get_max_profit(arr) << std::endl;
	
}

std::string BuyingStockTwice::demoName()
{
	return R"(BuyingStockTwice
------------------------------)"s;
}

int BuyingStockTwice::get_max_profit(const std::vector<int>& arr)
{
	if (arr.size() < 2)
		return 0;
	std::vector<int> profit(arr.size(), 0);
	int max_price = arr.back();
	profit[arr.size() - 1] = 0;
	for (int i = arr.size() - 2; i >= 0; i--) {
		if (arr[i] > max_price) {
			max_price = arr[i];
		}
		profit[i] = std::max(profit[i + 1], max_price - arr[i]);
	}
	int min_price = arr.front();
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] < min_price) {
			min_price = arr[i];
		}
		profit[i] = std::max(profit[i - 1], profit[i] + (arr[i] - min_price));
	}
	return profit.back();
}
