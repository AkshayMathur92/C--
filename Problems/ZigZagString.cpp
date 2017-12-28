#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string zaigzag(string &s, int a){
	vector<stringstream> strings(a);
	auto itr = s.begin();
	int i = 0;
	bool down = true;
	while(itr < s.end()){
		if(i % (a-1) == 0)
			down = !down;
		strings[i] << *itr;
		i = (down) ? i + 1 : i - 1;
		itr++;
	}
	string ans;
	for(int j = 0; j < a; j++){
		ans = ans + strings[j].str();
	}
	return ans;
}