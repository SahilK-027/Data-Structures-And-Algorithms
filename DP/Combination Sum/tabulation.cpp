#include <bits/stdc++.h> 
int solveTab(vector<int> &arr, int t){
    vector<int> dp(t+1, 0);
    dp[0] = 1;

    // Loop to fill table
    for(int i = 1; i <= t; i++){
        // Loop used in recursive code
        for(int j = 0 ; j < arr.size(); j++){
            if(i - arr[j] >= 0){
                dp[i] += dp[i - arr[j]];
            }
        }
    }

    return dp[t];
}
int findWays(vector<int> &arr, int t)
{
    return solveTab(arr, t);
}
