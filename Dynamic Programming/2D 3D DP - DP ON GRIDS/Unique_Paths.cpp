// REC
class Solution
{
private:
    int solve(int s_x, int s_y, int d_x, int d_y)
    {
        if (s_x == d_x && s_y == d_y)
        {
            return 1;
        }
        if (s_x > d_x || s_y > d_y)
        {
            return 0;
        }

        // GO DOWN
        int down_ans = solve(s_x + 1, s_y, d_x, d_y);
        // GO RIGHT
        int right_ans = solve(s_x, s_y + 1, d_x, d_y);

        return down_ans + right_ans;
    }

public:
    int uniquePaths(int m, int n)
    {
        return solve(0, 0, m - 1, n - 1);
    }
};

// REC N -> 0
class Solution
{
private:
    int solve(int s_x, int s_y)
    {
        if (s_x == 0 && s_y == 0)
        {
            return 1;
        }
        if (s_x < 0 || s_y < 0)
        {
            return 0;
        }

        // GO DOWN
        int down_ans = solve(s_x - 1, s_y);
        // GO RIGHT
        int right_ans = solve(s_x, s_y - 1);

        return down_ans + right_ans;
    }

public:
    int uniquePaths(int m, int n)
    {
        return solve(m - 1, n - 1);
    }
};

// MEMO
class Solution
{
private:
    int solve(int s_x, int s_y, vector<vector<int>> &dp)
    {
        if (s_x == 0 && s_y == 0)
        {
            return 1;
        }
        if (s_x < 0 || s_y < 0)
        {
            return 0;
        }
        if (dp[s_x][s_y] != -1)
        {
            return dp[s_x][s_y];
        }

        // GO DOWN
        int down_ans = solve(s_x - 1, s_y, dp);
        // GO RIGHT
        int right_ans = solve(s_x, s_y - 1, dp);

        return dp[s_x][s_y] = down_ans + right_ans;
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }
};

// TABULATION
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int s_x = 0; s_x < m; s_x++)
        {
            for (int s_y = 0; s_y < n; s_y++)
            {
                if (s_x == 0 && s_y == 0)
                {
                    continue;
                }
                // GO DOWN
                int down_ans = 0;
                if (s_x > 0)
                {
                    down_ans = dp[s_x - 1][s_y];
                }

                // GO RIGHT
                int right_ans = 0;
                if (s_y > 0)
                {
                    right_ans = dp[s_x][s_y - 1];
                }
                dp[s_x][s_y] = down_ans + right_ans;
            }
        }
        return dp[m - 1][n - 1];
    }
};