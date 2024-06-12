#include <iostream>
using namespace std;

// Remove the last set bit
// Logic1: x & (x - 1)
// Logic2: x -= (x & -x)

int remove_last_set_bit_1(int x){
    x = x & (x - 1);
    return x;
}
int remove_last_set_bit_2(int x){
    x -= (x & -1 * x);
    return x;
}

// Example:
// x = 12
// 0000 0000 0000 0000 0000 0000 0000 1100
// remove the last set bit
// 0000 0000 0000 0000 0000 0000 0000 1000
// op = 8

int main()
{
    int x = 12;
    int op1 = remove_last_set_bit_1(x);
    int op2 = remove_last_set_bit_2(x);
    cout << "x = " << x << endl;
    cout << "op1 = " << op1 << endl;
    cout << "op2 = " << op2 << endl;
    return 0;
}