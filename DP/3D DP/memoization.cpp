#include <bits/stdc++.h> 
int solve(int i, int j1, int j2, vector<vector<int>> &a, vector<int>&D, vector<vector<vector<int>>>& dp){
    // Bace case
    // Checking out of bound
    if(j1 < 0 || j2 < 0 || j1 >= a[0].size() || j2 >= a[0].size())
        return -1e8;
    if(i == a.size() - 1){
        if(j1 == j2)
            return a[i][j1];
        else
            return a[i][j1] + a[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int maxi = INT_MIN;
    for(auto di: D){
        for(auto dj: D){
            if(j1 == j2)
                maxi = max(maxi, a[i][j1] + solve(i+1, j1 + di , j2 + dj, a, D, dp));
            else
                maxi = max(maxi, a[i][j1] + a[i][j2] + 
                solve(i+1, j1+di, j2 + dj, a, D, dp));
        }
    }
    return dp[i][j1][j2] =  maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<int>delta = {-1,0,1};
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve(0, 0, c-1, grid, delta, dp);
}
