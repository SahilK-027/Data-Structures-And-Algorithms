#include <iostream>
using namespace std;

// Unset the bit at index i
// Example:
// x = 11
// 0000 0000 0000 0000 0000 0000 0000 1011
// unset the bit at index i = 1
// 0000 0000 0000 0000 0000 0000 0000 1001
// op = 9

// Approach:
// Now we have x = 11
// 0000 0000 0000 0000 0000 0000 0000 1011
// Lets create a mask of 1
// 0000 0000 0000 0000 0000 0000 0000 0001
// Now we must get set index of mask to ith index to get mast like this
// 0000 0000 0000 0000 0000 0000 0000 0010
// This we can get by left shifting 1 by i times

//  x    = 0000 0000 0000 0000 0000 0000 0000 1011
//  mask = 0000 0000 0000 0000 0000 0000 0000 0010
// ~mask = 1111 1111 1111 1111 1111 1111 1111 1101

// Now we can do AND operation to unset the bit at index i

int unset_bit(int x, int i){
    x = x & ~(1 << i);
    return x;
}

int main(){
    int x = 11;
    int op = unset_bit(x, 1);
    cout << "x = " << x << endl;
    cout << "op = " << op << endl;
    return 0;
}