#include <bits/stdc++.h> 
int solveMem(int idx, vector<int> &h, vector<int> &dp){
    if(idx == 0) return 0;
    if(dp[idx] != -1) return dp[idx];
    int jump1 = solveMem(idx - 1, h, dp) + abs(h[idx] - h[idx-1]);    
    int jump2 = INT_MAX;
    if(idx > 1){
        jump2 = solveMem(idx - 2, h, dp) + abs(h[idx] - h[idx-2]);
    }
    return dp[idx] =  min(jump1, jump2);
}
int solveTab(int n, vector<int> &h){
    vector<int>dp(n+1, 0);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int jump1 = dp[i - 1] + abs(h[i] - h[i-1]);    
        int jump2 = INT_MAX;
        if(i > 1){
            jump2 = dp[i - 2] + abs(h[i] - h[i-2]);
        }
        dp[i] =  min(jump1, jump2);
    }
    return dp[n];
}
int SO(int n, vector<int> &h){
    // vector<int>dp(n+1, 0);
    // dp[0] = 0;
    int prev1 = 0;
    int prev2 = 0;
    for(int i = 1; i <= n; i++){
        // int jump1 = dp[i - 1] + abs(h[i] - h[i-1]);  
        int jump1 = prev1 + abs(h[i] - h[i-1]);    
  
        int jump2 = INT_MAX;
        if(i > 1){
            // jump2 = dp[i - 2] + abs(h[i] - h[i-2]);
            jump2 = prev2 + abs(h[i] - h[i-2]);

        }
        // dp[i] =  min(jump1, jump2);
        int curr =  min(jump1, jump2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n, -1);
    return SO(n-1, heights);
    return solveTab(n-1, heights);
    return solveMem(n-1, heights, dp);
}
