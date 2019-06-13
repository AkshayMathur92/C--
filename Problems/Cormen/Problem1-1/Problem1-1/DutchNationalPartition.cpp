#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

void dutch_national_partitioning(vector<int>* A_ptr, const int &i) {
	vector<int> &A = *A_ptr;
	auto left_itr = A.begin();
	auto right_itr = A.end() - 1;
	while (left_itr < right_itr) {
		if (*left_itr < A[i]) {
			left_itr++;
		}
		else if (*right_itr > A[i]) {
			right_itr--;
		}
		else {
			break;
		}
	}
	auto itr = left_itr;
	itr++;
	while (itr <= right_itr) {
		if (*itr < A[i]) {
			iter_swap(left_itr, itr);
			left_itr++;
		}
		else if (*itr > A[i]) {
			iter_swap(right_itr, itr);
			right_itr--;
		}
		else {
			itr++;
		}
		for (auto &i : A) {
			cout << i << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<int> A = { 4,9,1,5,2,7,3,5,8 };
	dutch_national_partitioning(&A, 3);
	for (auto &i : A) {
		cout << i << " ";
	}
	return 0;
}