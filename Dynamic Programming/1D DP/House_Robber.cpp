class Solution
{
private:
    int houseRobber(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i < 0)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }

        int robCurrHouse = nums[i] + houseRobber(i - 2, nums, dp);
        int doNotRobCurrHouse = 0 + houseRobber(i - 1, nums, dp);

        return dp[i] = max(robCurrHouse, doNotRobCurrHouse);
    }
    int tabHouseRobber(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int robCurrHouse = nums[i];
            int doNotRobCurrHouse = INT_MIN;
            if (i >= 2)
            {
                robCurrHouse = nums[i] + dp[i - 2];
            }
            if (i >= 1)
            {
                doNotRobCurrHouse = 0 + dp[i - 1];
            }

            dp[i] = max(robCurrHouse, doNotRobCurrHouse);
        }

        return dp[n - 1];
    }

public:
    int rob(vector<int> &nums)
    {
        return tabHouseRobber(nums);
        int n = nums.size();
        vector<int> dp(n, -1);
        return houseRobber(n - 1, nums, dp);
    }
};