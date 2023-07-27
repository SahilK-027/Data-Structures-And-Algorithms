#include <bits/stdc++.h>
using namespace std ;

long long power(long long a, long long b, long long m){
    long long res = 1;
    a = a % m;
    while(b > 0){
        // odd power
        if(b & 1){
            res = (res * a) % m;
            b = b - 1;
        }
        //even power
        else{       
            a = (a * a) % m;
            b /= 2;
        }
    }
    return res;
}
int main()
{
    long long a = 3;
    // String input as b is very large
    int m = 1000000007;
    string b = "100000000000000000000000000";
    long long rem_b = 0;

    // Reduce the number b to a small number using Fermat Little
    for(int i = 0; i < b.length(); i++ ){
        rem_b = (rem_b * 10 + int(b[i])) % (m - 1);
    }

    cout<<power(a,rem_b,m)<<endl;
    return 0;
}