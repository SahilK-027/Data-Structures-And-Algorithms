#include<bits/stdc++.h>
int solve(int n, int x, int y, int z){
	// Base case
	if(n == 0) return 0;
	if(n < 0) return INT_MIN;
	// +1 to include current segement
	// take x length segment
	int ans1 = solve(n-x, x, y, z) + 1;
	// take y length segment
	int ans2 = solve(n-y, x, y, z) + 1;
	// take z length segment
	int ans3 = solve(n-z, x, y, z) + 1;

	int ans = max(ans1, max(ans2, ans3));

	return ans;
}
int cutSegments(int n, int x, int y, int z) {
	return solve(n, x, y, z) < 0 ? 0 : solve(n, x, y, z);
}
