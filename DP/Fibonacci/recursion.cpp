#include <bits/stdc++.h>
using namespace std;

// Recusrive
int fibo(int n){
    if(n < 2) return n;
    return fibo(n-1) + fibo(n-2);
}
int main()
{
    int n = 7;
    // Recursive 
    cout << fibo(n) << endl;
    return 0;
}
