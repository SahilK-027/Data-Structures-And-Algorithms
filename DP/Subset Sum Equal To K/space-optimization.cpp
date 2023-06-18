bool SO(int n, int k, vector<int>& a){
    vector<bool>prev(k+1, false);
    vector<bool>curr(k+1, false);
    prev[0] = true;
    curr[0] = true;
    prev[a[0]] = true;

    for(int i = 1;  i < n ; i++){
        for(int target = 1; target <= k; target++){   
            bool exclude = prev[target];
            bool include = false;
            if(target >= a[i]) include = prev[target-a[i]];
            curr[target] = include || exclude;
        }
        prev = curr;
    }
    return prev[k];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
    return SO(n,k,arr);
    return solveTab(n,k,arr);
    return solveMem(n-1, k, arr, dp);
}
