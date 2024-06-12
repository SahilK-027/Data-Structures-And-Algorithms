#include <iostream>
using namespace std;

// Set the bit at index i
// Example:
// x = 11
// 0000 0000 0000 0000 0000 0000 0000 1011
// set the bit at index i = 2
// 0000 0000 0000 0000 0000 0000 0000 1111
// op x = 11

// Approach:
// Now we have x = 11
// 0000 0000 0000 0000 0000 0000 0000 1011
// Lets create a mask of 1
// 0000 0000 0000 0000 0000 0000 0000 0001
// Now we must get set index of mask to ith index to get mast like this
// 0000 0000 0000 0000 0000 0000 0000 0100
// This we can get by left shifting 1 by i times

// x    = 0000 0000 0000 0000 0000 0000 0000 1011
// mask = 0000 0000 0000 0000 0000 0000 0000 0100

// Now we can do OR operation to set the bit at index i

int set_bit(int x, int i){
    x = x | (1 << i);
    return x;
}

int main(){
    int x = 11;
    int op = set_bit(x, 2);
    cout << "x = " << x << endl;
    cout << "op = " << op << endl;
    return 0;
}