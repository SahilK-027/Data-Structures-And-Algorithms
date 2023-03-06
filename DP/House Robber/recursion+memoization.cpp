// Recursive solution + DP
class Solution {
private:
    int solveMemoization(vector<int>& nums, int s, int e, vector<int>& dp){
        // Base case
        if(s > e){
            return 0;
        }
        if(dp[s] != -1){
            return dp[s];
        }
        // Include current house
        int include = nums[s] + solveMemoization(nums, s + 2, e, dp);
        // Exclude current house
        int exclude = 0 + solveMemoization(nums, s + 1, e, dp);
        // Return whichever answer will be maximum
        return dp[s] = max(include, exclude);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int s = 0;
        int e = nums.size()-1;
        // Ans 1 will be for house 1 to second last house as last house will be adjacent house to house 1 in circle
        vector<int> dp1(nums.size(), -1);
        int ans_1 = solveMemoization(nums, s, e-1, dp1);
        // Ans 2 will be for house 2 to the last house.
        vector<int> dp2(nums.size(), -1);
        int ans_2 = solveMemoization(nums, s+1, e, dp2);
        // Finally return maximum of answers
        return max(ans_1, ans_2);
    }
};
