#include <bits/stdc++.h> 
int solve(vector<int> &arr, int t){
    if(t == 0) return 1;
    if(t < 0) return 0;

    int ans = 0;
    for(int i = 0 ; i < arr.size(); i++){
        ans += solve(arr, t - arr[i]);
    }
    return ans;
}
int findWays(vector<int> &arr, int t)
{
    return solve(arr, t);
}
