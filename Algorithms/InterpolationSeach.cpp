//Use when item to seach is numeric and the dataset is fairly uniformly distributed. 
#include <iostream>
#include <vector>
using namespace std;

bool interpolation_search(const vector<int> &data, const int &low, const int &high, const int &item){

	if(low == high)
		return data[low] == item;
	if(low > high)
		return false;

	auto distance = item - data[low];
	auto data_range = data[high] - data[low];
	auto index_range = high - low; 
	auto fraction = distance / double(data_range);
	int pos = low + int (fraction * index_range);

	if(data[pos] == item)
		return true;
	else if (data[pos] < item)
			return interpolation_search(data, pos + 1, high, item);
		else
			return interpolation_search(data, low, pos - 1, item);
}

bool interpolation_search(const vector<int> &data, const int &item){
	return interpolation_search(data, 0, data.size() - 1, item);
}

int main(){
	vector<int> v = {0, 7, 12, 17, 21, 26, 31, 33, 40, 43, 49, 51, 64, 66, 73, 74, 81, 87, 95, 97};
	cout << interpolation_search(v, 64) << endl;
	cout << interpolation_search(v, 65) << endl;
	cout << interpolation_search(v, 100) << endl;

}