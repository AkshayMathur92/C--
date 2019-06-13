#include <iostream>
#include <vector>
#include <array>
using namespace std;

void process_dec(array<int,8> &num, bool &isRainbow, int &itr,  const int N, int &prev){
    if(isRainbow && prev == 7){
        do{
            int temp;
            cin >> temp;
            if(temp < 1 || temp > 7 || !(temp == prev || (temp == prev - 1 && num[prev] == 0))){
                isRainbow = false;
            }
            else{
                num[temp]--;
            }
            prev= temp;
            itr ++;
        }while(itr != N);
    }else{
        isRainbow = false;
        while(itr != N ){
            int temp;
            cin >> temp;
            itr++;
        }
    }
}

void process_inc(array<int,8> &num, bool &isRainbow, int &itr, const int N, int &prev){
    if(isRainbow){
        int temp ;
        do{
            cin >> temp;
            if(temp > 7 || !(temp == prev || temp == prev + 1)){
                isRainbow = false;
            }
            else{
                num[temp]++;
            }
            prev = temp;
            itr ++;
        }while(itr < N / 2 && temp != 7);
        if(N % 2 != 0){
            int temp;
            cin >> temp;
            if(temp != 7){
                isRainbow = false;
            }
            prev =temp;
            itr ++;
        }
        process_dec(num, isRainbow, itr,N, prev);
    }
    else{
        isRainbow = false;
        do{
            int temp;
            cin >> temp;
            itr ++;
        }while(itr != N);
    }
}

int main ()
{
  int T;
  cin >> T;
  while (T-- > 0)
    {
        int N , prev = 1, itr = 0;
        bool isRainbow = true;
        array<int,8> nums;
        nums.fill(0);
        cin >> N ;
        if(N < 13)
            isRainbow = false;
        else
            process_inc(nums, isRainbow, itr, N, prev);
        std::cout << ((isRainbow) ? "yes" : "no") << std::endl;
    }
}
