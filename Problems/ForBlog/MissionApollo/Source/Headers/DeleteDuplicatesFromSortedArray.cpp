#include "DeleteDuplicatesFromSortedArray.h"

void DeleteDuplicatesFromSortedArray::demo()
{
	std::vector<int> arr = { 2,2,3,3,3,5,5,7,10,10 };
	delete_duplicate(&arr);
	for (auto &i : arr)
		std::cout << i << "  ";
	std::cout << std::endl;
	arr = { 2,3,5,7,10};
	delete_duplicate(&arr);
	for (auto &i : arr)
		std::cout << i << "  ";
	std::cout << std::endl;
}

std::string DeleteDuplicatesFromSortedArray::demoName()
{
	return R"(DeleteDuplicatesFromSortedArray
---------------------------------------------)"s;
}

void DeleteDuplicatesFromSortedArray::delete_duplicate(std::vector<int>* pVecArr)
{
	std::vector<int> &arr = *pVecArr;
	if (arr.empty())
		return;
	auto find_non_dup_itr = arr.begin() + 1;
	auto last_found_itr = arr.begin();
	while (find_non_dup_itr != arr.end()) {
		if (*find_non_dup_itr != *last_found_itr) {
			last_found_itr++;
			*last_found_itr = *find_non_dup_itr;
		}
		find_non_dup_itr++;
	}
}