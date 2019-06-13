/*
	https://www.codechef.com/problems/LECANDY
*/

#include <iostream>

using namespace std;

int main(){

	unsigned int T = 0;
	cin >> T ;
	while(T-- > 0){
		unsigned int N = 0;
		unsigned int C = 0;
		unsigned int candies_required = 0;
		cin >> N >> C ;
		for(int i = 0; i < N ; i ++){
			unsigned int Ak ;
			cin >>Ak;
			candies_required += Ak;
		}
		if(candies_required <= C){
			cout << "Yes" << endl;
		}else{
		    cout << "No" << endl;
		}
	}
	return 0;
}