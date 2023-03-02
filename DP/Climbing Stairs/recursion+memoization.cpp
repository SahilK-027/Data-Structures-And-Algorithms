class Solution {
private:
    int solveMemoization(int n, vector<int>& dp)
    {
        // if we reached the ground
        if( n == 0 ){
            return 1;
        }
        // If the path doesn't take us to ground
        if( n < 0 ){
            return 0;
        }
        if(dp[n] != -1) return dp[n];
        // Return the path which we get by climbing 
        return dp[n] = solveMemoization(n-1, dp) + solveMemoization(n - 2, dp);
    }

public:
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return solveMemoization(n, dp);
    }
};
