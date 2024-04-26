// MEMO
class Solution
{
private:
    int solve(int end, int idx, vector<int> &nums, vector<int> &dp)
    {
        if (idx == end)
        {
            return nums[idx];
        }
        if (idx < end)
        {
            return 0;
        }
        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        int rob = nums[idx] + solve(end, idx - 2, nums, dp);
        int no_rob = 0 + solve(end, idx - 1, nums, dp);

        return dp[idx] = max(rob, no_rob);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int op1 = solve(0, n - 2, nums, dp1);
        int op2 = solve(1, n - 1, nums, dp2);

        return max(op1, op2);
    }
};