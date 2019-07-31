#include "ComputePermutation.h"

void ComputePermutation::demo()
{
	for (auto &i : compute(4)) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (auto &i : compute(4)) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (auto &i : compute(4)) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (auto &i : compute(4)) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (auto &i : compute(4)) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (auto &i : compute(4)) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (auto &i : compute(4)) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (auto &i : compute(4)) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

}

std::string ComputePermutation::demoName()
{
	return R"(ComputePermutation
------------------------------)"s;
}

std::vector<int> ComputePermutation::compute(int n)
{
	std::random_device rd;
	std::mt19937_64 generator(rd());
	std::vector<int> result(n);
	std::iota(result.begin(), result.end(), 0);
	int range = n;
	while (range-- > 0) {
		int random = std::uniform_int_distribution<int>(0, range)(generator);
		std::swap(result[range], result[random]);
	}
	return result;
}
