#include <bits/stdc++.h>
#define M 1000000007
#define lli long long int

lli SO(int n){
    lli prev2 = 0;
    lli prev1 = 1;

    for(int i = 3; i <= n; i++){
        lli curr = ((i - 1) % M * (prev1 + prev2)) % M;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
lli countDerangements(int n) {
    return SO(n);
}
