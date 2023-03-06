#include <bits/stdc++.h> 
int solveTabulation(vector<int> &nums, int n){
    vector<int>dp(n, 0);
    dp[0] = nums[0];
    for(int i = 1 ; i < n ; i++){
        int include = dp[i-2] + nums[i];
        int exclude = dp[i-1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n-1];

}
int maximumNonAdjacentSum(vector<int> &nums){
    int i = 0;
    int n = nums.size();
    return solveTabulation(nums, n);
}
