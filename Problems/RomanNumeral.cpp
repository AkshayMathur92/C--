#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <cmath>
#include <sstream>
using namespace std;

int romanToInt(string s){
	if(s.size() == 0)
		return 0;
	map<char, int> value;
	value.insert(pair<char,int>('I', 1));
	value.insert(pair<char,int>('V', 5));
	value.insert(pair<char,int>('X', 10));
	value.insert(pair<char,int>('L', 50));
	value.insert(pair<char,int>('C', 100));
	value.insert(pair<char,int>('D', 500));
	value.insert(pair<char,int>('M', 1000));

	auto itr = s.begin();
	long long int ans = 0;
	while(itr < s.end()){
		if(itr + 1 < s.end() && value[*itr] < value[*(itr + 1)]){
			ans = ans + value[*(itr+1)] - value[*itr];
			itr ++;
		}
		else{
			ans = ans + value[*itr];
		}
		itr++;
	}
	return ans;
}
string IntToRoman(int a){
	if(a == 0)
		return 0;
	map<int, string> value;
	value.insert(pair<int,string>(1 ,"I" ));
	value.insert(pair<int,string>(5 ,"V" ));
	value.insert(pair<int,string>(10 ,"X" ));
	value.insert(pair<int,string>(50 ,"L" ));
	value.insert(pair<int,string>(100 ,"C" ));
	value.insert(pair<int,string>(500 ,"D" ));
	value.insert(pair<int,string>(1000 ,"M" ));
	value.insert(pair<int,string>(4 ,"IV" ));
	value.insert(pair<int,string>(9 ,"IX" ));
	value.insert(pair<int,string>(40 ,"XL" ));
	value.insert(pair<int,string>(90 ,"XC" ));
	value.insert(pair<int,string>(400 ,"CD" ));
	value.insert(pair<int,string>(900 ,"CM" ));

	stringstream ss;
	while(a > 0){
		if(a > 9){
			int p = static_cast<int>(log10(a));
			int divisor = static_cast<int>(pow(10,p));
			auto temp = a / divisor;
			// cout << a<< " " << p << " "<< divisor << " " <<  temp <<endl;
			if(value.find(divisor*temp) != value.end()){
				ss << value[divisor*temp];
				a = a - divisor*temp;
			}
			else{
				a = a - divisor*temp;
				while(temp > 0){
					ss << value[divisor];
					temp--;
				}
			}
			
		}
		else{
			switch(a){
				case 1: ss << "I";break;
				case 2: ss << "II";break;
				case 3: ss << "III";break;
				case 4: ss << "IV";break;
				case 5: ss << "V";break;
				case 6: ss << "VI";break;
				case 7: ss << "VII";break;
				case 8: ss << "VIII";break;
				case 9: ss << "IX";break;
			}
			a=0;
		}
	}
	return ss.str();
}
int main() {
	 cout << romanToInt("MCMXC") << endl;
	cout << IntToRoman(1954);
	return 0;
}