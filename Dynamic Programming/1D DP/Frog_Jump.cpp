// MEMO
int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int op1 = INT_MAX;
    if (n > 0)
    {
        op1 = abs(heights[n - 1] - heights[n]) + solve(n - 1, heights, dp);
    }
    int op2 = INT_MAX;
    if (n > 1)
    {
        op2 = abs(heights[n - 2] - heights[n]) + solve(n - 2, heights, dp);
    }

    return dp[n] = min(op1, op2);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    return solve(n - 1, heights, dp);
}

// TABULATION
int solveTab(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int op1 = INT_MAX;
        if (i > 0)
        {
            op1 = abs(heights[i - 1] - heights[i]) + dp[i - 1];
        }
        int op2 = INT_MAX;
        if (i > 1)
        {
            op2 = abs(heights[i - 2] - heights[i]) + dp[i - 2];
        }

        dp[i] = min(op1, op2);
    }
    return dp[n - 1];
}
int frogJump(int n, vector<int> &heights)
{
    return solveTab(n, heights);
}

// SPACE OPTIMIZED
int solveSO(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;
    int curr = 0;

    for (int i = 1; i < n; i++)
    {
        int op1 = abs(heights[i - 1] - heights[i]) + prev1;
        int op2 = INT_MAX;
        if (i > 1)
        {
            op2 = abs(heights[i - 2] - heights[i]) + prev2;
        }

        curr = min(op1, op2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int frogJump(int n, vector<int> &heights)
{
    return solveSO(n, heights);
}
