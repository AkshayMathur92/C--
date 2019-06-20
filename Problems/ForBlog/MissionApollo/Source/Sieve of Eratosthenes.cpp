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
	if (n < 2) {
		std::cout << "1" << std::endl;
		return;
	}
	std::cout << "1 " ;
	std::vector<int> sieve (n + 1);
	std::iota(sieve.begin(), sieve.end(), 0);
	auto itr = sieve.begin() + 2;
	while (itr != sieve.end()) {
		while (itr != sieve.end() && *itr == -1) {
			itr++;
		}
		if (itr == sieve.end())
			return;
		std::cout << *itr << " ";
		for (int i = 2; (*itr) * i <= n; i++) {
			sieve[(*itr) * i] = -1;
		}
		itr++;
	}
}
