bool solveMem(int idx, int target, vector<int>& a, vector<vector<int>>& dp){
    if(target == 0) return true;
    if(idx == 0){
        if(a[idx] == target) return true;
        return false;
    }
    if(dp[idx][target] != -1) return dp[idx][target];
    bool include = false;
    if(target >= a[idx]) include = solveMem(idx - 1, target - a[idx],a, dp);
    bool exclude = solveMem(idx - 1, target,a, dp);

    return dp[idx][target] = include || exclude;

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
    return solveMem(n-1, k, arr, dp);
}
