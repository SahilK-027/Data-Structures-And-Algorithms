#include <bits/stdc++.h> 
int solve(vector<int> &nums, int i, int n){
    // Base case:
    // If exceeded size of array
    if(i >= n) return 0;
    
    // Inclusion exclusion cases
    int include = solve(nums, i + 2, n) + nums[i];
    int exclude = solve(nums, i+1, n);

    return max(include, exclude);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int i = 0;
    int n = nums.size();
    return solve(nums, i, n);
}
