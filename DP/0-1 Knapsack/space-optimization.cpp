#include <bits/stdc++.h> 
int SO(vector<int>& weight, vector<int>& value, int n, int capacity){
	// Step 1: Create Table
  vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);

	// Step 2: Analyze the base cases to fill table
	for(int w = weight[0]; w <= capacity; w++){
		if(weight[0] <= capacity){
			prev[w] = value[0];
		}
		else{
			prev[w] = 0;
		}
	}

	for(int row = 1; row < n; row++){
		for(int c = 0; c <= capacity; c++){
			int include = 0, exclude = 0;
			if(weight[row] <= c){
				include = value[row] + prev[c - weight[row]];
			}
			exclude = 0 + prev[c];

			curr[c] = max(include, exclude);
		}
		prev = curr;
	}
	return prev[capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int capacity) 
{
	return SO(weight, value, n, capacity);
}
