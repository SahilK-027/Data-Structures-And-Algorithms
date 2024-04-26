// memo
class Solution
{
private:
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (row >= n || col >= m)
        {
            return 1e9;
        }
        if (row == n - 1)
        {
            int curr_row_mini = 1e9;
            for (int new_col = 0; new_col < m; new_col++)
            {
                if (new_col != col)
                {
                    curr_row_mini = min(curr_row_mini, grid[row][new_col]);
                }
            }
            return curr_row_mini;
        }
        if (dp[row][col + 1] != -1)
        {
            return dp[row][col + 1];
        }

        // Pick element
        int ans = 1e9;
        for (int new_col = 0; new_col < m; new_col++)
        {
            if (new_col != col)
            {
                int remaining = grid[row][new_col] + solve(row + 1, new_col, grid, dp);
                ans = min(ans, remaining);
            }
        }

        return dp[row][col + 1] = ans;
    }

public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int m = grid[0].size();
        int ans = 1e9;
        vector<vector<int>> dp(grid.size(), vector<int>(m + 1, -1));
        for (int col = 0; col < m; col++)
        {
            ans = min(ans, solve(0, -1, grid, dp));
        }
        return ans;
    }
};