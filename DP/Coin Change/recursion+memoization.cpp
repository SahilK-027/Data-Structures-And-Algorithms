class Solution {
private:
    int solveMemoization(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        // Step 3: If answer is already calculated return answer
        if(dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;
        for(int i= 0 ; i < coins.size(); i++){
            int ans = solveMemoization(coins, amount - coins[i], dp);
            if(ans != INT_MAX){
                mini = min(mini, ans+1);
            }
        }

        // Step 2: Store answer in DP
        return dp[amount] =  mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // Step 1: Craete and pass DP
        vector<int> dp(amount+1, -1);
        int ans = solveMemoization(coins, amount, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
