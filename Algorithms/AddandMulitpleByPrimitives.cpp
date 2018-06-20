// Example program
#include <iostream>
#include <string>
int add(int x, int y){
    int sum = 0;
    int carryin = 0;
    int k = 1;
    int temp_a = x, temp_b = y;
    while(temp_a || temp_b){
        int a = x & k;
        int b = y & k;
        int carryout = (a & b) | (a & carryin) | (b & carryin);
        sum |= (a ^ b ^ carryin);
        carryin = carryout << 1;
        temp_a >>= 1;
        temp_b >>= 1;
        k <<= 1;
        std::cout << "Sum : " << sum <<" Carryout " << carryout << " carryin " << carryin << " k "  << k << std::endl;
    }
    return sum | carryin;
}
int multiply (int x, int y) {
    int prod = 0; 
    while(x){
        if(x & 1){
            prod = add(prod, y);
        }
        x >>= 1;
        y <<= 1;
    }
    return prod;
}
int main()
{
  std::cout << multiply ( 2, 4); 
}
