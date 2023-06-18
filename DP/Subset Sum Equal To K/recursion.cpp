#include <bits/stdc++.h> 
bool solve(int idx, int target, vector<int>& a){
    if(target == 0) return true;
    if(idx == 0){
        if(a[idx] == target) return true;
        return false;
    }
    
    bool include = false;
    if(target >= a[idx]) include = solve(idx - 1, target - a[idx],a);
    bool exclude = solve(idx - 1, target,a);

    return include || exclude;

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return solve(n-1, k, arr);
}
