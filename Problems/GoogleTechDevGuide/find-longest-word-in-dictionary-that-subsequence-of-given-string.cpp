/* https://techdevguide.withgoogle.com/paths/foundational/find-longest-word-in-dictionary-that-subsequence-of-given-string#! */
#include <string>
#include <set>
#include <iostream>
#include <array>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;
bool is_subseq(const string s, const string d) {
	if (d.size() > s.size()) {
		return false;
	}
	auto s_itr = s.begin();
	auto d_itr = d.begin();
	while (s_itr != s.end()) {
		if (*s_itr == *d_itr) {
			s_itr++;
			d_itr++;
		}
		else {
			s_itr++;
		}
		if (d_itr == d.end()) {
			return true;
		}
	}
	return false;
}
string solve(const string s, const set<string> ds) {
	string result = "";
	long r_len = 0;
	for (auto d : ds) {
		if (is_subseq(s, d) && d.size() > r_len) {
			result = d;
			r_len = d.size();
		}
	}
	return result;
}

array<std::vector<int>,26> generate_associative_array(const string s){
	array<vector<int>,26> arr;
	for(int i = 0; i < s.size(); i ++){
		arr[tolower(s[i]) - 'a'].emplace_back(i);
	}
	return arr;
}

bool is_subseq2(array<vector<int>,26> &arr, const string d){
	int last_found = -1;\
	for(char a : d){
		a = tolower(a);
		int i = a -'a';
		auto found = upper_bound(arr[i].begin(), arr[i].end(), last_found);
		if(found == arr[i].end()){
			return false;
		}
		else{
			last_found = *found;
		}
	}
	return true;
}

string solve2(const string s, const set<string> ds){
	auto arr = generate_associative_array(s);
	string result = "";
	long r_len = 0;
	for (auto d : ds) {
		if (is_subseq2(arr, d) && d.size() > r_len) {
			result = d;
			r_len = d.size();
		}
	}
	return result;
}

array<vector<int>,26> generate_full_associative_array(const string s){
	array<vector<int>,26> arr;
	for(int i = 0; i < s.size(); i ++){
		arr[tolower(s[i]) - 'a'][i] = 1;
	}
	return arr;
}

bool is_subseq3(int s_size, array<vector<int>,26> &arr, const string d){
	for(int j= 0; j <  s_size; j ++){
		char a = tolower(d[j]);
		int i = a -'a';
		auto found = (arr[i][j] == 1) ? true : false;
		if(!found){
			return false;
		}
	}
	return true;
}

string solve3(const string s, const set<string> ds){
	auto arr = generate_full_associative_array(s);
	for(auto &vec : arr){
        for(auto c : vec){
            cout << c << " " ;
        }
        cout << endl;
	}
	string result = "";
	long r_len = 0;
	for (auto d : ds) {
		if (is_subseq3(s.size(), arr, d) && d.size() > r_len) {
			result = d;
			r_len = d.size();
		}
	}
	return result;
}

int main() {
	string s = "abppplee";
	set<string> d = { "able", "ale", "apple", "bale", "kangaroo" };
	cout << solve(s, d) << endl;
	cout << solve2(s,d) << endl;
	cout << solve3(s,d) << endl;
}
