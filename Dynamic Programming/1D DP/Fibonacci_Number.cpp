class Solution
{
private:
    int solve(int n, vector<int> &dp)
    {
        // Base case
        if (n == 1)
            return 1;
        if (n == 0)
            return 0;

        // Step 4: ANALYZE BC
        if (dp[n] != -1)
            return dp[n];

        // RECURSIVE CALL
        int ans = solve(n - 1, dp) + solve(n - 2, dp);

        // Step 3: UPDATYE
        return dp[n] = ans;
    }
    int solveTab(int n)
    {
        // Step 1:
        vector<int> dp(n + 1, -1);
        // Step 2:
        dp[1] = 1;
        dp[0] = 0;

        // Step 3: Filing
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int SO(int n)
    {
        // Step 2:
        int prev2 = 0;
        int prev1 = 1;
        int curr = 1;
        // Step 3: Filing
        for (int i = 2; i <= n; i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

public:
    int fib(int n)
    {
        // Step 1: CREATE
        // vector<int> dp(n+1, -1);
        // Step 2: PASS
        if (n == 0)
        {
            return 0;
        }
        return SO(n);
    }
};