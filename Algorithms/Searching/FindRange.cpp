//Given a sorted array with possible duplicate elements. Find number of occurrences of input ‘key’ in log N time.
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int getRight(const vector<int> &data, int &item){
	int low = 0;
	int high = data.size() - 1;

	int mid = 0;
	while(high - low > 1){
		mid = low + (high - low) / 2;
		if(data[mid] <= item)
			low = mid;
		else
			high = mid;
	}
	return (data[low + 1] == item)? low + 1 : low;
}

int getLeft(const vector<int> &data, int &item){
	int low = 0;
	int high = data.size() - 1;

	int mid = 0;
	while(high - low > 1){
		mid = low + (high - low) / 2;
		if(data[mid] >= item)
			high = mid;
		else
			low = mid;
	}
	return (data[high - 1] == item)? high - 1 : high ;
}

pair<int,int> getRange(const vector<int> &data, int item){
	auto right = getRight(data, item);
	auto left = getLeft(data, item);
	return std::move(make_pair(left,right));
}

int main(){
	vector<int> v = {1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7};
	auto range = getRange(v, 1);
	cout << range.first << " " << range.second << endl;
}