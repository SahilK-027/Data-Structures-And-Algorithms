#include <bits/stdc++.h>
using namespace std;
// SPACE OPTIMIZATION
int fib_SO(int n)
{
    if(n < 2){
        return n;
    }
    int prev1 = 1;
    int prev2 = 0;
    int curr;
    for(int i = 2 ; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return  curr;
}
int main()
{
    int n = 7;
    // Space optimization
    cout << fib_SO(n) << endl;
    return 0;
}
