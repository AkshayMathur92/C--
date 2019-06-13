/*
  https://www.codechef.com/problems/CNOTE
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
  unsigned int T = 0;
  cin >> T;
  while(T -- > 0 ){
      unsigned int X =0, Y =0, K =0, N =0; 
      cin >> X >> Y >> K >> N ;
      bool lucky = false;
      while(N -- > 0){
          unsigned int P = 0, C = 0;
          cin >> P >> C; 
          if(!lucky && P >= (X - Y) && (C <= K)){
              lucky = true;
          }
      }
      cout << ((lucky) ? "LuckyChef":"UnluckyChef") << endl;
  }
}
