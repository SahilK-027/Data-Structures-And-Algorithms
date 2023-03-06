class Solution {
private:
    int solveTab(vector<int>& coins, int amount){
        vector<int>dp(amount+1 ,INT_MAX);
        dp[0] = 0;

        for(int i = 1 ; i <= amount; i++){
            // Utilize all coins for current amount
            for(auto c: coins){
                // Checking for valid index
                if(i - c >= 0 && dp[i - c] != INT_MAX){
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        else{
            return dp[amount];
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        return solveTab(coins, amount);
    }
};
