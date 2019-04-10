/* https://techdevguide.withgoogle.com/paths/foundational/find-longest-word-in-dictionary-that-subsequence-of-given-string#! */
#include <string>
#include <set>
#include <iostream>
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

int main() {
	string s = "abppplee";
	set<string> d = { "able", "ale", "apple", "bale", "kangaroo" };
	cout << solve(s, d) << endl;
}