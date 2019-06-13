#include "MultipleArbitraryInteger.h"

void MultiplyArbitraryInteger::demo()
{
	auto vec = multiply({ 1,2,3 }, { 1,1 });
	for (auto &i : vec) {
		std::cout << i;
	}
	std::cout << std::endl;
	vec = multiply({ 1,2,3 }, { 2 });
	for (auto &i : vec) {
		std::cout << i;
	}
	std::cout << std::endl;
	vec = multiply({ 1,2,3 }, { 9,9 });
	for (auto &i : vec) {
		std::cout << i;
	}
	std::cout << std::endl;
	vec = multiply({ 1,2,3 }, { 1 });
	for (auto &i : vec) {
		std::cout << i;
	}
	std::cout << std::endl;
}

int MultiplyArbitraryInteger::get_digit_with_offset(const std::vector<int> &arr, const int &offset, const int &index) {
	//because we know the array here will be already reversed. 
	int rev_index = arr.size() - index - 1;
	if (rev_index + offset >= arr.size())
		return 0;
	else
		return arr[rev_index + offset];
}

std::vector<int> MultiplyArbitraryInteger::add_vectors_with_offsets(const std::vector<std::vector<int>> &sums) {
	if (sums.size() < 2) {
		return sums[0];
	}
	int max_itr = sums[sums.size() - 1].size() + sums.size() - 1;
	std::vector<int> result;
	int carry = 0;
	int sum = 0;
	for (int i = 0; i < max_itr; i++) {
		sum += carry;
		for (unsigned int j = 0; j < sums.size(); j++) {
			sum += get_digit_with_offset(sums[j], j, i);
		}
		result.push_back(sum % 10);
		carry = sum / 10;
		sum = 0;
	}
	std::reverse(result.begin(), result.end());
	return result;
}

std::vector<int> MultiplyArbitraryInteger::multiply_vector_to_digit(const std::vector<int> &arr, const int &i) {
	std::vector<int> result;
	auto itr = arr.rbegin();
	int carry = 0;
	while (itr != arr.rend()) {
		int product = (i * *itr) + carry;
		result.push_back(product % 10);
		carry = product / 10;
		itr++;
	}
	while (carry) {
		result.push_back(carry % 10);
		carry /= 10;
	}
	std::reverse(result.begin(), result.end());
	return result;
}

std::vector<int> MultiplyArbitraryInteger::multiply(const std::vector<int>& b1, const std::vector<int> &b2) {
	const std::vector<int> &smaller = (b1.size() < b2.size()) ? b1 : b2;
	const std::vector<int> &larger = (smaller == b1) ? b2 : b1;

	std::vector<std::vector<int>> individual_sum;
	for (auto i = smaller.rbegin(); i != smaller.rend(); i++) {
		individual_sum.emplace_back(multiply_vector_to_digit(larger, *i));
	}
	return add_vectors_with_offsets(individual_sum);
}

