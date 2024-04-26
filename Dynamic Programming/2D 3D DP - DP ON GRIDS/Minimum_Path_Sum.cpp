// memo
class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return grid[0][0];
        }
        if (i < 0 || j < 0)
        {
            return 1e9;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int d = grid[i][j] + solve(i - 1, j, grid, dp);
        int r = grid[i][j] + solve(i, j - 1, grid, dp);

        return dp[i][j] = min(d, r);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, grid, dp);
    }
};

// tabulation
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                int d = 1e9;
                if (i > 0)
                {
                    d = grid[i][j] + dp[i - 1][j];
                }

                int r = 1e9;
                if (j > 0)
                {
                    r = grid[i][j] + dp[i][j - 1];
                }

                dp[i][j] = min(d, r);
            }
        }
        return dp[m - 1][n - 1];
    }
};