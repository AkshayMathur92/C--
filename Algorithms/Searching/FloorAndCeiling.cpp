#include <iostream>
#include <vector>
using namespace std;

int floor(const vector<int> &data, const int &item){
	if(data.size() < 1)
		return -1;
	if(data[0] >item)
		return -1;
	
	int low = 0;
	int high = data.size() - 1;
	while(high - low > 1){
		int mid = low + (high - low) / 2;
		if(data[mid] <= item)
			low = mid;
		else
			high = mid;
	}
	return (data[low] < item)? low : low - 1;
}
int ceil(const vector<int> &data, const int &item){
	if(data.size() < 1)
		return -1;
	if(data[data.size() -1] < item)
		return -1;
	
	int low = 0;
	int high = data.size() - 1;
	while(high - low > 1){
		int mid = low + (high - low) / 2;
		if(data[mid] <= item)
			low = mid;
		else
			high = mid;
	}
	if(high < data.size())
		return (data[high] > item)? high : high + 1;
	else
		return -1;
}
int main(){
	vector<int> v = {1,3,5,7,9};
	cout << v[floor(v,6)] << endl; //5
	cout << v[ceil(v,6)] << endl; //7

}