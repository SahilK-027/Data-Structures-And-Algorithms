#include <bits/stdc++.h> 
int solveTab(vector<int>& weight, vector<int>& value, int n, int capacity){
	// Step 1: Create Table
	vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

	// Step 2: Analyze the base cases to fill table
	for(int w = weight[0]; w <= capacity; w++){
		if(weight[0] <= capacity){
			dp[0][w] = value[0];
		}
		else{
			dp[0][w] = 0;
		}
	}

	for(int row = 1; row < n; row++){
		for(int c = 0; c <= capacity; c++){
			int include = 0, exclude = 0;
			if(weight[row] <= c){
				include = value[row] + dp[row-1][c - weight[row]];
			}
			exclude = 0 + dp[row-1][c];

			dp[row][c] = max(include, exclude);
		}
	}
	return dp[n-1][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int capacity) 
{
	return solveTab(weight, value, n, capacity);
}
