#include <bits/stdc++.h>
#define M 1000000007
#define lli long long int

lli solveMemoization(int n, vector<lli>& dp){
    if( n < 2 ) return 0;
    if( n == 2) return 1;
    if(dp[n] != -1) return dp[n];
    return 
    dp[n] = ((n-1) % M * (solveMemoization(n-1, dp) + solveMemoization(n-2, dp)))%M;
}
lli countDerangements(int n) {
    vector<lli> dp(n+1, -1);
    return solveMemoization(n, dp);
}
