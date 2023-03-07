#include <bits/stdc++.h>
#define M 1000000007
#define lli long long int

lli tabulation(int n){
    vector<lli> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= n; i++){
        dp[i] = ((i - 1) % M * (dp[i-1] + dp[i-2])) % M;
    }
    return dp[n];
}
lli countDerangements(int n) {
    return tabulation(n);
}
