#include <iostream>
#include <string> 
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;
pair<char,char> sum(char a, char b){
	if(a == '0' || b == '0')
		return (a == '0')? pair<char,char>(b,'0') : pair<char,char>(a, '0');
	return pair<char,char>('0','1');
}
string addBinary(string &s1, string &s2){
	
	if(s1.size() == 0 || s2.size() == 0)
		return (s1.size() == 0) ? s2 : s1;

	auto itr1 = s1.rbegin();
	auto itr2 = s2.rbegin();
	char c = '0';
	stringstream ans ;

	while(itr1 < s1.rend() && itr2 < s2.rend()){
		auto temp = sum (*itr1 , *itr2);
		int nc = temp.second;
		auto temp2 = sum (c, temp.first);
		nc = (nc == '0')? temp2.second : '1'; 
		ans << temp2.first;
		c = nc;
		itr1++;
		itr2++;
	}

	while(itr1 < s1.rend()){
		auto temp = sum (c, *itr1);
		ans << temp.first;
		c = temp.second;
		itr1++;
	}
	while(itr2 < s2.rend()){
		auto temp = sum (c, *itr2);
		ans << temp.first;
		c = temp.second;
		itr2++;
	}
	if(c == '1')
		ans << '1';
	
	string s = ans.str();
	reverse(s.begin(),s.end());
	
	auto begin = s.find_first_of('1');
	if(begin == string::npos)
		return "0";
	else
		return s.substr(begin, s.size());
}
int main() {
	// your code goes here
	string s1 = "1";
	string s2 = "10";
	cout <<  addBinary(s1,s2);
	return 0;
}