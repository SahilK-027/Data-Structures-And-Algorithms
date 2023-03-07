#include <bits/stdc++.h> 
#define M 1000000007
int solveMemoization(int n, int k, vector<int>& dp) {
    // Base case
    // We have only one pole
    if(n == 1) return k ;
    if(n == 2) return (k % M + (k % M  * 1ll * (k - 1) % M)) % M;
    if(dp[n] != -1) return dp[n];

    // Recursion
    int last_same = (solveMemoization(n-2, k, dp) % M * 1ll * (k-1) % M) % M;
    int last_diff = (solveMemoization(n-1, k, dp) % M * 1ll * (k-1) % M) % M;

    return dp[n] = (last_same + last_diff) % M ;

}

int numberOfWays(int n, int k) {
    vector<int> dp(n+1, -1);
    return solveMemoization(n, k, dp);
}
