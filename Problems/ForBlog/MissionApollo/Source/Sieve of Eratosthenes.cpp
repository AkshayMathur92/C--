#include "Sieve of Eratosthenes.h"

void SieveOfEratosthenes::demo()
{
	print_primes(100);
}

std::string SieveOfEratosthenes::demoName()
{
	return R"(SieveOfEratosthenes
------------------------------)"s;
}

void SieveOfEratosthenes::print_primes(unsigned int n) {
	std::vector<int> primes(n + 1);
	std::iota(primes.begin(), primes.end(), 0);
	for (auto itr = primes.begin() + 1; itr < primes.end(); itr++) {
		if (*itr == 1)
			continue;
		auto stride = (itr - primes.begin());
		auto multiple = itr;
		while ((primes.end() - multiple) > stride) {
			std::advance(multiple, stride);
			*multiple = 1;
		}
	}
	for (auto &i : primes) {
		if(i >= 2)
			std::cout << i << " ";
	}
	std::cout << std::endl;
}
