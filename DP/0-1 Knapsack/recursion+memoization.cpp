#include <bits/stdc++.h> 
int solveMemoization(vector<int>& weight, vector<int>& value, int i, int n, int capacity, vector<vector<int>>& dp){
	// Base caase we are standing at last element
	if(i == n-1){
		// if we haave enough capacity
		if(weight[i] <= capacity){
			return value[i];
		}
		else{
			return 0;
		}
	}

	// If already calculated answer then return 
	if(dp[i][capacity] != -1) return dp[i][capacity];
	// Inclusion exclusion call
	int include = 0, exclude = 0;
	if(weight[i] <= capacity){
		include = value[i] + solveMemoization(weight, value, i+1, n, capacity - weight[i], dp);
	}
	exclude = 0 + solveMemoization(weight, value, i+1, n, capacity, dp);

	// Step 2: Store answer at changed parameters in DP
	return dp[i][capacity] = max(include, exclude);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Step 1: Create DP
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return solveMemoization(weight, value, 0, n, maxWeight, dp);
}
