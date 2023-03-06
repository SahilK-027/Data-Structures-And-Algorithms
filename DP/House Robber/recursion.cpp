#include <bits/stdc++.h> 
#define ll long long
ll solve(vector<int>& arr, int i, int n){
    if(i > n){
        return 0;
    }
    ll include = solve(arr, i+2, n) + arr[i];
    ll exclude = solve(arr, i+1, n) + 0;

    return max(include, exclude);
}
ll int houseRobber(vector<int>& arr)
{
    if(arr.size() == 1) return arr[0];
    int e = arr.size()-1;
    ll ans = max(solve(arr, 0, e-1), solve(arr, 1, e));
    return ans;
}
