#include <iostream>

using namespace std;

unsigned add (unsigned x, unsigned y){

    unsigned sum = 0, temp_x = x, temp_y = y, k = 1, carry_in = 0;
    while(temp_x || temp_y){
        unsigned xk = x & k, yk = y & k;
        unsigned carry_out = (xk & yk) | (xk & carry_in) | (yk & carry_in);
        sum |= (xk ^ yk ^ carry_in);
        carry_in = carry_out << 1;
        k <<= 1;
        temp_x >>= 1;
        temp_y >>= 1;
    }
    return sum | carry_in;
}

unsigned multiply (unsigned x, unsigned y){
    
    unsigned sum = 0;
    while(x){
        if(x & 1){
            sum = add(sum, y);
        }
        x >>= 1;
        y <<= 1;
    }
    return sum;
}

int main()
{
    cout << multiply(3, 60) << endl;
    cout << add(3, 60) << endl;
    return 0;
}
