#include <bits/stdc++.h> 
int solveMemoization(vector<int> &nums, int i, int n, vector<int>&dp){
    // Base case:
    // If exceeded size of array
    if(i >= n) return 0;
    // Step 3: If answer is already calculated return answer
    if(dp[i] != -1) return dp[i];
    // Inclusion exclusion cases
    int include = solveMemoization(nums, i + 2, n, dp) + nums[i];
    int exclude = solveMemoization(nums, i+1, n, dp);

    // Step 2: Solve and store answer in DP
    return dp[i] =  max(include, exclude);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int i = 0;
    int n = nums.size();
    // Step 1: Crate DP and pass to the function call
    vector<int>dp(n, -1);
    return solveMemoization(nums, i, n, dp);
}
