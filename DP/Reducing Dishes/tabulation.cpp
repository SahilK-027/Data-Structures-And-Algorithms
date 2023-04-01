class Solution {
private:
    int tabulation(vector<int>& arr){
        int n = arr.size();
        vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1, 0));
        for(int i = n - 1 ; i >= 0; i--){
            for(int time = i  ; time >= 0; time--){
                // Include case
                int include = (time + 1)* arr[i] + dp[i+1][time+1];
                // Exclude case
                int exclude = 0 + dp[i+1][time];

                dp[i][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
public:
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        return tabulation(arr);
    }
};
