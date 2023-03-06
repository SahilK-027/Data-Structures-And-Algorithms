#include<bits/stdc++.h>
int solveMemoization(int n, int x, int y, int z, vector<int>& dp){
	// Base case
	if(n == 0) return 0;
	if(n < 0) return INT_MIN;
	if(dp[n] != -1) return dp[n];
	// +1 to include current segement
	// take x length segment
	int ans1 = solveMemoization(n-x, x, y, z, dp) + 1;
	// take y length segment
	int ans2 = solveMemoization(n-y, x, y, z, dp) + 1;
	// take z length segment
	int ans3 = solveMemoization(n-z, x, y, z, dp) + 1;

	int ans = max(ans1, max(ans2, ans3));

	return dp[n] =  ans;
}
int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, -1);
	return solveMemoization(n, x, y, z, dp) < 0 ? 0 : solveMemoization(n, x, y, z, dp);
}
