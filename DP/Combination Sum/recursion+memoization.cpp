#include <bits/stdc++.h> 
int solveMemoization(vector<int> &arr, int t, vector<int>& dp){
    if(t == 0) return 1;
    if(t < 0) return 0;
    if(dp[t] != -1) return dp[t];

    int ans = 0;
    for(int i = 0 ; i < arr.size(); i++){
        ans += solveMemoization(arr, t - arr[i], dp);
    }
    return dp[t] =  ans;
}
int findWays(vector<int> &arr, int t)
{
    vector<int> dp(t+1, -1);
    return solveMemoization(arr, t, dp);
}
