#include "DutchNationalFlagPartioning.h"


std::string DutchNationalFlagPartioning::getProblemStatement()
{
	return "Partitioning is a common process used in other algorithms such a quicksort.\
	In this problem, we are given an Array A and an index i.\
	We have to rearrange A such that, all elements less than A[i] appears first followed by all elements equal to A[i] followed by all elements greater than A[i].";
}

std::string DutchNationalFlagPartioning::getComplexityStatement()
{
	return "Both Time and Space complexity are constant time.";
}

std::string DutchNationalFlagPartioning::getLearningStatement()
{
	return "Never doubt yourself In the first attempt the answer came out wrong and I immediately jumped to the conclusion that the comparison mechanism is incorrect since I have recalled it from past memory.\
		However it turns out that all that was missing was one more iteration that I did not perform.\
		This also makes me aware of the fact whenever we talk about iteration we need to be accurate about what are iteration limits.\
		The complexity for this solution straight forward is constant since we are only swapping elements by traversing the array once and no extra memory is required.\
		Also I learned the best way to swap elements of iterators are iter_swap a built in function in algorithms library.\
		Hmm..simple one but panic caused a lot of time waste.";
}

std::string DutchNationalFlagPartioning::getProblemSolvingStatement()
{
	return "Not lying but since I have done such a problem sometime in past, this has quickly led me to think of using iterators that spans 3 ranges of less than, equal to and greater than values.\
		However the first question is to where to position each initially.\
		First I thought of positioning them at begin and end - 1 position, but just initializing them there because we do not have other option is breaking the invariant that at any time those iterator should point to correct values.\
		Also there can be a case where all values are same then there would be no point in doing anything.\
		This also means that we should skip the part that is correct and hence post skipping we could arrive at the correct iterator location.\
		So first iterate from both ends and get to a location for both iterators where they are in accordance with the arrangement that left iterator has values less than A[i] and the right one has values greater than A[i]\
		when this process ends we would reach the exact range we need to actually rearrange and bonus point if there is no range left to process.\
		Once we reach this range.We need to create another iterator that starts at begin + 1, to iterate till right iterator.\
		at every point we check if the iterator is less than val then we swap it with left itr and increment left itr and similarly if it is greater than A[i] then we swap it with right itr.\
		And yes that should do it.\
		It should also be able to handle cases where all values fall into one range, since that we would skip at the beginning only.\
		I wrote it, it failed and corrected it and ran correctly then.";
}

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
		cout << (mid_itr - A.begin()) << ":      ";
		for (auto &i : A) {
			cout << i << " ";
		}
		cout << endl;
	}
}