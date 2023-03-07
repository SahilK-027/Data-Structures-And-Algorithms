#include <bits/stdc++.h> 
int solve(vector<int>& weight, vector<int>& value, int i, int n, int capacity){
	// Base caase we are standing at last element
	if(i == n-1){
		// if we have enough capacity to include last element
		if(weight[i] <= capacity){
			return value[i];
		}
		else{
			return 0;
		}
	}

	// Inclusion exclusion calls
	int include = 0, exclude = 0;
	if(weight[i] <= capacity){
		include = value[i] + solve(weight, value, i+1, n, capacity - weight[i]);
	}
	exclude = 0 + solve(weight, value, i+1, n, capacity);

	return max(include, exclude);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight, value, 0, n, maxWeight);
}
