#include <bits/stdc++.h> 
#define M 1000000007
int solveTab(int n, int k) {
    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = (k*k) % M;

    for(int i = 3; i <= n; i++){
        dp[i] = ((dp[i-2] * 1ll * (k-1)) + (dp[i-1]* 1ll * (k-1))) % M;
    }

    return dp[n];
}

int numberOfWays(int n, int k) {

    return solveTab(n, k);
}
