class Solution {
private:
    int solveMemoization(vector<int>& cost, int n, vector<int>&dp){
        if( n == 0 ){
            return cost[n];
        }
        if( n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = min(solveMemoization(cost, n-1, dp) + cost[n], solveMemoization(cost, n-2, dp) + cost[n]);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        return  min(solveMemoization(cost, n-1, dp), solveMemoization(cost, n-2, dp));
    }
};
