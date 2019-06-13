#include "DutchNationalFlagPartioning.h"

void DutchNationalFlagPartioning::demo()
{
	vector<int> A = { 4,9,1,5,2,7,3,5,8 };
	for (auto &i : A) {
		cout << i << " ";
	}
	cout << endl;
	dutch_national_partitioning(&A, 3);
	for (auto &i : A) {
		cout << i << " ";
	}
	cout << endl;

	vector<int> B = { 4,9,1,4,5,2,9,7,2,1,8,3,5,8 };
	for (auto &i : B) {
		cout << i << " ";
	}
	cout << endl;
	dutch_national_partitioning(&B, 3);
	for (auto &i : B) {
		cout << i << " ";
	}
	cout << endl;
}

std::string DutchNationalFlagPartioning::demoName()
{
	return R"(DutchNaitonalFlagPartioning
------------------------------------)"s;
}


DutchNationalFlagPartioning::DutchNationalFlagPartioning()
{
}

DutchNationalFlagPartioning::~DutchNationalFlagPartioning()
{
}

void DutchNationalFlagPartioning::dutch_national_partitioning(vector<int>* A_ptr, const int &i) {
	vector<int> &A = *A_ptr;
	const int val = A[i];
	auto left_itr = A.begin();
	auto right_itr = A.end() - 1;
	while (left_itr < right_itr) {
		if (*left_itr <val) {
			left_itr++;
		}
		else if (*right_itr > val) {
			right_itr--;
		}
		else {
			break;
		}
	}
	auto mid_itr = left_itr;
	mid_itr++;
	while (mid_itr <= right_itr) {
		if (*mid_itr < val) {
			iter_swap(left_itr, mid_itr);
			left_itr++;
		}
		else if (*mid_itr >val) {
			iter_swap(right_itr, mid_itr);
			right_itr--;
		}
		else {
			mid_itr++;
		}
	}
}