bool solveTab(int n, int k, vector<int>& a){
    vector<vector<bool>>dp(n+1, vector<bool>(k+1, false));
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }
    dp[0][a[0]] = true;

    for(int i = 1;  i < n ; i++){
        for(int target = 1; target <= k; target++){   
            bool exclude = dp[i - 1][target];
            bool include = false;
            if(target >= a[i]) include = dp[i - 1][target-a[i]];
            dp[i][target] = include || exclude;
        }
    }
    return dp[n-1][k];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
    return solveTab(n,k,arr);
}
