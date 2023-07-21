class Solution {
private:
    int solveRec(int srcX, int srcY, vector<vector<int>>& grid){
        if(srcX == 0 && srcY == 0) return grid[srcX][srcY];
        if(srcX < 0 || srcY < 0) return 1001;

        int leftCall = grid[srcX][srcY] + solveRec(srcX, srcY-1, grid);
        int upCall = grid[srcX][srcY] + solveRec(srcX-1, srcY, grid);

        return min(leftCall, upCall);
    }
    int solveMem(int srcX, int srcY, vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(srcX == 0 && srcY == 0) return grid[srcX][srcY];
        if(srcX < 0 || srcY < 0) return 1001;
        if(dp[srcX][srcY] != -1) return dp[srcX][srcY];
        
        int leftCall = grid[srcX][srcY] + solveMem(srcX, srcY-1, grid, dp);
        int upCall = grid[srcX][srcY] + solveMem(srcX-1, srcY, grid, dp);

        return dp[srcX][srcY] =  min(leftCall, upCall);
    }

    int solveTab(int m, int n, vector<vector<int>>& grid){
        vector<vector<int>>dp(m, vector<int>(n,1001));
        dp[0][0] = grid[0][0];

        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n ;j++){
                if(i == 0 && j == 0 ) continue;

                int leftCall = 1001, upCall = 1001;
                if(j > 0) leftCall = grid[i][j] + dp[i][j-1];
                if(i > 0) upCall =  grid[i][j] + dp[i-1][j];
                dp[i][j] = min(leftCall, upCall);
            }
        }
        return dp[m-1][n-1];
    }

    int SO(int m, int n, vector<vector<int>>& grid){
        vector<int>prev(n,1001);
        
        for(int i = 0 ; i < m; i++){
            vector<int>curr(n,1001);
            for(int j = 0; j < n ;j++){
                if(i == 0 && j == 0 ){
                    prev[0] = grid[0][0];
                    curr[0] = grid[0][0];
                    continue;
                }

                int leftCall = 1001, upCall = 1001;
                if(j > 0) leftCall = grid[i][j] + curr[j-1];
                if(i > 0) upCall =  grid[i][j] + prev[j];
                curr[j] = min(leftCall, upCall);
            }
            prev = curr;
        }
        return prev[n-1];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));

        return SO(m, n, grid);
        return solveTab(m, n, grid);
        return solveMem(m-1, n-1, grid, dp);
        return solveRec(m-1, n-1, grid);
    }
};
