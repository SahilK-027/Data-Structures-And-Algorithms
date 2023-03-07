#include <bits/stdc++.h> 
int SO(vector<int>& weight, vector<int>& value, int n, int capacity){
	// Step 1: Create Table
	vector<int> curr(capacity+1, 0);

	// Step 2: Analyze the base cases to fill table
	for(int w = weight[0]; w <= capacity; w++){
		if(weight[0] <= capacity){
			curr[w] = value[0];
		}
		else{
			curr[w] = 0;
		}
	}

	for(int row = 1; row < n; row++){
		// Go right to left
		for(int c = capacity; c >= 0; c--){
			int include = 0, exclude = 0;
			if(weight[row] <= c){
				include = value[row] + curr[c - weight[row]];
			}
			exclude = 0 + curr[c];

			curr[c] = max(include, exclude);
		}
	}
	return curr[capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int capacity) 
{
	return SO(weight, value, n, capacity);
}
