// memo
class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= n)
        {
            return 100001;
        }
        if (i == 0)
        {
            return matrix[i][j];
        }
        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int up = solve(i - 1, j, matrix, n, dp);
        int d1 = solve(i - 1, j - 1, matrix, n, dp);
        int d2 = solve(i - 1, j + 1, matrix, n, dp);

        int ans = matrix[i][j] + min(up, min(d1, d2));
        return dp[i][j] = ans;
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int last_row = n - 1;
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        for (int col = 0; col < n; col++)
        {
            ans = min(ans, solve(last_row, col, matrix, n, dp));
        }
        return ans;
    }
};