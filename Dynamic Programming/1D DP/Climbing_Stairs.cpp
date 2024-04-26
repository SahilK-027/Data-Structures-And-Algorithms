// REC
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n < 0)
        {
            return 0;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// MEMOIZATION
class Solution
{
private:
    int memoizedClimbStairs(int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n < 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = memoizedClimbStairs(n - 1, dp) + memoizedClimbStairs(n - 2, dp);
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return memoizedClimbStairs(n, dp);
    }
};

// TABULATION
class Solution
{
private:
    int memoizedClimbStairs(int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n < 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = memoizedClimbStairs(n - 1, dp) + memoizedClimbStairs(n - 2, dp);
    }
    int tabulationClimbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int op1 = dp[i - 1];
            int op2 = 0;
            if (i > 1)
            {
                op2 = dp[i - 2];
            }
            dp[i] = op1 + op2;
        }
        return dp[n];
    }

public:
    int climbStairs(int n)
    {
        return tabulationClimbStairs(n);
    }
};

// OPTIMIZED
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        int prev1 = 1;
        int prev2 = 0;
        int curr = 0;
        for (int i = 1; i <= n; i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};