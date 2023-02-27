#include <bits/stdc++.h>
using namespace std;
void dfs(int node, 
unordered_map<int,list<int>>& adj_list, 
stack<int>& st,
vector<bool>&visited)
{
	visited[node] = true;
	for(auto i: adj_list[node]){
		if(!visited[i]){
			dfs(i, adj_list, st, visited);
		}
	}
	st.push(node);
}

void reversed_dfs(int node, 
unordered_map<int,list<int>>& adj_list, 
vector<bool>&visited){
	visited[node] = true;
	for(auto i: adj_list[node]){
		if(!visited[i]){
			reversed_dfs(i, adj_list, visited);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Adjacency list
	unordered_map<int, list<int>>adj_list;
	for(auto i: edges){
		adj_list[i[0]].push_back(i[1]);
	}

	// Topological sort
	stack<int>st;
	vector<bool>visited(v, false);
	for(int i = 0 ; i < v; i++){
		if(!visited[i]){
			dfs(i, adj_list, st, visited);
		}
	}

	// Transpose of graph
	unordered_map<int, list<int>>transposted;
	for(int i = 0 ; i < v ; i++){
		visited[i] = false;
		for(auto neighbour: adj_list[i]){
			transposted[neighbour].push_back(i);
		}
	}

	// Dfs call for transposed graph
	int ans = 0;
	while(!st.empty()){
		int top = st.top();
		st.pop();
		if(!visited[top]){
			ans++;
			reversed_dfs(top,transposted, visited);
		}
	}
	return ans;
}
