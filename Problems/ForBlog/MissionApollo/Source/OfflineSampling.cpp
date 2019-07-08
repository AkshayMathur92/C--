#include "OfflineSampling.h"

void OfflineSampling::demo()
{
	std::vector<int> demo = { 1,2,3,4,5,6,7,8,9 };
	RandomSampling(&demo, 5);
	for (auto &i : demo)
		std::cout << i << " ";
	std::cout << std::endl;
	RandomSampling(&demo, 5);
	for (auto &i : demo)
		std::cout << i << " ";
	std::cout << std::endl;
}

std::string OfflineSampling::demoName()
{
	return R"(OfflineSampling
----------------------------)"s; 
}

void OfflineSampling::RandomSampling(std::vector<int> *parr, int k) {
	std::vector<int> & arr = *parr;
	if (k >= arr.size())
		return;
	int eliminate = arr.size() - k;
	while (eliminate-- > 0) {
		int pick = (rand() % (arr.size() - eliminate));
		std::swap(arr[pick], arr[arr.size() - eliminate - 1]);
	}
}
