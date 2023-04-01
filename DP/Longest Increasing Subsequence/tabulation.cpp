class Solution {
private:
    int Tabulation(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size() + 1, 0));

        for(int curr = n-1 ; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                // Include 
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + dp[curr + 1][curr+1];
                }
                // Exclude
                int exclude = 0 + dp[curr+1][prev+1];

                //  Prev can be -1 as well so make prev + 1 
                dp[curr][prev+1] =  max(include, exclude);
            }
        }
        return dp[0][0];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        return Tabulation(nums);
    }
};
