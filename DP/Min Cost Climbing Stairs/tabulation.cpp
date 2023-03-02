class Solution {
private:
    int solveTab(vector<int>& cost, int n){
        vector<int>dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2 ; i <= n; i++){
            dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
        }
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // Edge case
        if(n == 2){
            return min(cost[1], cost[0]);
        }
        return  min(solveTab(cost, n-1), solveTab(cost, n-2));
    }
};
