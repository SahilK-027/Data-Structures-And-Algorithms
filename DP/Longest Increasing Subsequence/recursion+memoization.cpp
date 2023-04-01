class Solution {
private:
    int solveMemoization(vector<int>& nums, int prev, int curr, vector<vector<int>>& dp){
        if(curr >= nums.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        // Include 
        int include = INT_MIN;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveMemoization(nums, curr, curr+1, dp);
        }
        // Exclude
        int exclude = 0 + solveMemoization(nums, prev, curr+1, dp);

        //  Prev can be -1 as well so make prev + 1 
        return dp[curr][prev+1] =  max(include, exclude);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int curr = 0;
        int prev = -1;
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size() + 1, -1));
        return solveMemoization(nums, prev, curr, dp);
    }
};
