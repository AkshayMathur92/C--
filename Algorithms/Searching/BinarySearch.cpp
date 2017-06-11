#include <iostream>
#include <vector>
using namespace std; 

struct Person{
	int age;
	float weight;		
};

bool operator== (const Person &p1, const Person &p2){
			return (p1.age == p2.age && p1.weight == p2.weight) ? true : false;
}

using lint = long int; 
template <typename T> 
bool binary_search(const vector<T> &data, const T &item, const lint low, const lint high, const function<bool(const T&, const T&)> &less_than){
	if(low > high)
		return false;
	if(low == high)
		return data[low] == item; 

	else{
		auto mid = (( high - low ) /2) + low;
		if(data[mid] == item)
			return true;
		else if(less_than(data[mid], item))
				return binary_search(data, item, mid + 1, high, less_than);
			else
				return binary_search(data, item, low, mid - 1, less_than);
	}
}
template <typename T> 
bool binary_search(const vector<T> &data, const T &item, const function<bool(const T&, const T&)> less_than){
	return binary_search(data, item, 0, data.size() - 1, less_than);
}
bool binary_search(const vector<int> &data, const int item){
	function<bool (const int&, const int&)> lambda = [](const int &i, const int &j){
		return i < j;
	};
	return binary_search(data, item, 0, data.size() - 1, lambda);
}
bool binary_search(const vector<double> &data, const double item){
	function<bool (const double&, const double&)> lambda = [](const double &i, const double &j){
		return i < j;
	};
	return binary_search(data, item, 0, data.size() - 1, lambda);
}

int main(){
	std::vector<int> v = {1,3,5,7,9};
	cout << binary_search(v, 3) << endl;
	cout << binary_search(v, 2) << endl;

	std::vector<double> v2 = {-5.6, 0, 0.2 ,1.2, 1.6, 1000000.3};
	cout << binary_search(v2, 1.6) << endl;
	cout << binary_search(v2, 2) << endl;

	

	struct Person p1 = { 1, 1.5}, p2 = {2,2.5}, p3 = {3,3.5}, p4 { 4,4.5};
	std::vector<struct Person> v3 = { p1, p2, p4};
	std::function<bool(const Person&, const Person&)> compare = [](const Person &p1, const Person &p2){
		return p1.age < p2.age;
	};
	cout << binary_search(v3, p2, compare) << endl;
	cout << binary_search(v3, p3, compare) << endl;
}