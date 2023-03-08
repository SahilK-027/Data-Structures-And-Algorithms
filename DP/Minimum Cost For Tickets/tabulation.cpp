class Solution {
private:
    int tabulation(int i, int n, vector<int>& days, vector<int>& costs){
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;

        for(int i = n-1 ; i >= 0 ; i--){
            // Option 1: Buy 1 day pass
            int option1 = costs[0] + dp[i+1];
            // Option 2: Buy 7 day pass
            // Go seven day ahead
            int x;
            for(x = i; x < n && days[x] < days[i] + 7; x++);
            int option2 = costs[1] + dp[x];
            // Option 3: Buy 30 day pass
            for(x = i; x < n && days[x] < days[i] + 30; x++);
            int option3 = costs[2] + dp[x];

            dp[i] =  min(option1, min(option2, option3));
        }
        
        return dp[0];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int i = 0;
        return tabulation(i, n, days, costs);
    }
};
