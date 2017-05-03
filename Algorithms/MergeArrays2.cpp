#include <vector>
#include <iostream>
#include <numeric>

template <typename T>
T&  merge_arrays(T &v1) {
	return v1;
}
template <typename T>
T&  merge_arrays(T &v1, T &v2) {
	int pos = v1.size() + v2.size();
	v1.resize(pos);
	pos--;
	auto iv1 = v1.rbegin() + v2.size() ;
	auto iv2 = v2.rbegin();
	while (iv1 != v1.rend() && iv2 != v2.rend()) {
		if (*iv1 > *iv2) {
			v1[pos] = *iv1;
			iv1++;
			pos--;
		}
		else {
			v1[pos] = *iv2;
			iv2++;
			pos--;
		}
	}
	while (iv1 != v1.rend()) {
		v1[pos] = *iv1;
		*iv1++;
		pos--;
	}
	while (iv2 != v2.rend()) {
		v1[pos] = *iv2;
		*iv2++;
		pos--;
	}
	return v1;
}
template <typename T, typename... Tail>
T& merge_arrays(T &v1, T &v2, Tail... tail) {
	merge_arrays(v1, v2);
	merge_arrays(v1, tail...);
	return v1;
}
int main() {
	std::vector<int> v1 = { 1,4,6 };
	std::vector<int> v2 = { 2,7,9 };
	std::vector<int> v3 = { 3,5,8 };
	std::vector<int> v4 = { 10 };
	std::vector<int> v5 = { 11 };
	for (auto i : merge_arrays(v1, v2, v3, v4, v5)) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (auto i : v1) {
		std::cout << i << " ";
	}
}