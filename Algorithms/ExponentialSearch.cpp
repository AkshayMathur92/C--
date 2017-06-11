#include <iostream>
#include <vector>
using namespace std;

bool binary_search(const vector<int> &data, const int &low, const int &high, const int &item){

	if(low == high)
		return data[low] == item;
	if(low > high)
		return false;
	auto pos = low + (high - low) / 2; 
	if(data[pos] == item)
		return true;
	else if (data[pos] < item)
			return binary_search(data, pos + 1, high, item);
		else
			return binary_search(data, low, pos - 1, item);
}
bool exponential_search(const vector<int> &data, const int &item){

	if(data[0] == item)
		return true;
	if(data.size() < 2)
		return false;
	int i = 1;
	int n = data.size() - 1;
	while(i < n && data[i] < item)
		i = i * 2;

	return binary_search(data, i/2, min(i, n), item);
}

int main(){
	vector<int> v = {0, 7, 12, 17, 21, 26, 31, 33, 40, 43, 49, 51, 64, 66, 73, 74, 81, 87, 95, 97};
	cout << exponential_search(v, 64) << endl;
	cout << exponential_search(v, 65) << endl;
	cout << exponential_search(v, 100) << endl;
}