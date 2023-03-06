#include <bits/stdc++.h> 
int SO(vector<int> &nums, int n){
    int prev2 = 0;
    int prev1 = nums[0];
    for(int i = 1 ; i < n ; i++){
        int include = prev2 + nums[i];
        int exclude = prev1 + 0;
        int curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;

}
int maximumNonAdjacentSum(vector<int> &nums){
    int i = 0;
    int n = nums.size();
    return SO(nums, n);
}
